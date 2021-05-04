function calcPlaytime(musicinfo) {
  const start = musicinfo[0].split(":");
  const end = musicinfo[1].split(":");
  const sTime = start[0] * 1 * 60 + start[1] * 1;
  const eTime = end[0] * 1 * 60 + end[1] * 1;
  return eTime - sTime;
}

function getNoteArray(notes, length) {
  const noteLength = notes.length;
  const noteArray = [];
  let pointer = 0;
  for (let i = 0; i < length; i++) {
    let note = notes.charAt(pointer);
    if (notes.charAt(pointer + 1) === "#") {
      note += "#";
      pointer++;
    }
    noteArray.push(note);
    pointer = pointer + 1 >= noteLength ? 0 : pointer + 1;
  }
  return noteArray;
}

function isSongEqual(a, b) {
  const compA = a.map((e) => JSON.stringify(e)).join(",");
  const compB = b.map((e) => JSON.stringify(e)).join(",");
  return compA.includes(compB);
}

function solution(m, musicinfos) {
  let answer = 0;
  let maxPlaytime = 0;
  const heardNote = getNoteArray(
    m,
    m.length - m.split("").filter((e) => e === "#").length
  );
  musicinfos.forEach((musicinfo) => {
    const info = musicinfo.split(",");
    const playtime = calcPlaytime(info);
    const playedNote = getNoteArray(info[3], playtime);
    console.log(playedNote);
    if (isSongEqual(playedNote, heardNote)) {
      if (playtime > maxPlaytime) {
        answer = info[2];
        maxPlaytime = playtime;
      }
    }
  });
  return !answer ? "(None)" : answer;
}

const m = "ABC";
const mi = ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"];
console.log(solution(m, mi));
