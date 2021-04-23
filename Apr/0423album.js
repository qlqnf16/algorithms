let playsByGenre = {};
let songsByGenre = {};

function fillDict(genres, plays) {
  const songCnt = genres.length;
  for (let i = 0; i < songCnt; i++) {
    const genre = genres[i];
    const play = plays[i];

    if (playsByGenre[genre]) {
      playsByGenre[genre] += play;
      songsByGenre[genre].push([i, play]);
    }
    else {
      playsByGenre[genre] = play;
      songsByGenre[genre] = [[i, play]];
    }
  }
}

function getSortedDict() {
  Object.keys(songsByGenre).forEach(key => {
    songsByGenre[key].sort((a, b) => b[1] - a[1]);
  })

  const genrePlay = [];
  Object.keys(playsByGenre).forEach(key => {
    genrePlay.push([playsByGenre[key], key]);
  })
  genrePlay.sort((a, b) => b[0] - a[0]);

  return genrePlay;
}

function solution(genres, plays) {
  const answer = [];

  fillDict(genres, plays);
  const genrePlay = getSortedDict();
  genrePlay.forEach(element => {
    const genre = element[1];
    for (let i = 0; i < 2; i++) {
      const song = songsByGenre[genre][i]
      if (song) {
        answer.push(song[0]);
      }
    }
  })

  return answer;
}