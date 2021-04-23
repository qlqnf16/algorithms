const nicknameDict = {};
const inOutRecord = [];

function enter(uid, nickname) {
  nicknameDict[uid] = nickname;
  inOutRecord.push([0, uid]);
}

function leave(uid) {
  inOutRecord.push([1, uid])
}

function change(uid, nickname) {
  nicknameDict[uid] = nickname;
}

function makeRecord(record) {
  record.forEach(element => {
    const splitRecord = element.split(' ');
    const order = splitRecord[0];
    const uid = splitRecord[1];
    if (order === 'Enter') {
      enter(uid, splitRecord[2]);
    } else if (order === 'Leave') {
      leave(uid);
    } else {
      change(uid, splitRecord[2]);
    }
  });
}

function writeChatLog() {
  const logs = [];
  inOutRecord.forEach(record => {
    const uid = record[1];
    if (record[0] == 0) {
      logs.push(`${nicknameDict[uid]}님이 들어왔습니다.`)
    } else {
      logs.push(`${nicknameDict[uid]}님이 나갔습니다.`)
    }
  })
  return logs;
}

function solution(record) {
  let answer = [];
  makeRecord(record);
  answer = writeChatLog();
  return answer;
}

const record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"];
console.log(solution(record));