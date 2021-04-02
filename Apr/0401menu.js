let combiObj = {}

function makeCombi(menus, combi, curIdx, curCnt, cnt) {
    if (curCnt == cnt) {
        if (combiObj[combi]) combiObj[combi]++;
        else combiObj[combi] = 1;
    }
    for (let i = curIdx; i < menus.length; i++) {
        makeCombi(menus, combi + menus[i], i + 1, curCnt + 1, cnt);
    }
}

function makeCourse() {
    let maxCnt = 0;
    let menuList = [];
    for (const key in combiObj) {
        if (combiObj[key] < 2 || combiObj[key] < maxCnt) continue;
        if (combiObj[key] > maxCnt) {
            maxCnt = combiObj[key];
            menuList = [key];
        }
        else if (combiObj[key] == maxCnt) {
            menuList.push(key);
        }
    }
    return menuList;
}

function sortString(str) {
    return str.split('').sort().join('')
}

function solution(orders, course) {
    var answer = [];

    for (let i = 0; i < orders.length; i++) {
        orders[i] = sortString(orders[i]);
    }

    course.forEach(cnt => {
        orders.forEach(order => {
            makeCombi(order, '', 0, 0, cnt);
        })
        answer.push(...makeCourse());
        combiObj = {};
    });
    answer.sort();
    return answer;
}

const orders = ["XYZ", "XWY", "WXA"]
const course = [2, 3, 4]
console.log(solution(orders, course));