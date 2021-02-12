import java.util.LinkedList;
import java.util.Queue;

public class K7 {
  static int[] dirr = { 0, 0, 1, -1 };
  static int[] dirc = { 1, -1, 0, 0 };
  static boolean[][] visit = new boolean[4][4];

  public int solution(int[][] board, int r, int c) {
    int answer = 0;
    int cardTotal = 0;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (board[i][j] > 0)
          cardTotal++;
      }
    }
    answer = bfs(r, c, board, cardTotal);
    return answer;
  }

  static int bfs(int sr, int sc, int[][] board, int cardTotal) {
    Queue<Position> q = new LinkedList<Position>();
    q.add(new Position(sr, sc, 0, cardTotal));

    while (!q.isEmpty()) {
      Position cur = q.poll();
      if (cur.leftcard == 0)
        return cur.t;

      // 상하좌우 이동, 상하좌우 가장 가까이 이동, 엔터
      int nextr, nextc;
      for (int i = 0; i < 4; i++) {
        nextr = cur.r + dirr[i];
        nextc = cur.c + dirc[i];
        if (!isPossible(nextr, nextc))
          continue;
        if (visit[nextr][nextc])
          continue;
        visit[nextr][nextc] = true;
        q.add(new Position(nextr, nextc, cur.t + 1, cur.leftcard, cur.o));
      }

      for (int i = 0; i < 4; i++) {
        nextr = cur.r;
        nextc = cur.c;
        while (isPossible(nextr, nextc) && board[nextr][nextc] == 0) {
          nextr += dirr[i];
          nextc += dirc[i];
        }
        if (!isPossible(nextr, nextc))
          continue;
        visit[nextr][nextc] = true;
        q.add(new Position(nextr, nextc, cur.t + 1, cur.leftcard, cur.o));
      }

      Open nexto;
      int nextl = cur.leftcard;
      if (cur.o.isOpen) {
        if (cur.o.card == board[cur.r][cur.c]) {
          board[cur.r][cur.c] = board[cur.o.r][cur.o.c] = 0;
          nextl -= 2;
        }
        nexto = new Open();
      } else {
        nexto = new Open(true, cur.r, cur.c, board[cur.r][cur.c]);
      }
      q.add(new Position(cur.r, cur.c, cur.t + 1, nextl, nexto));

    }

    return -1;
  }

  static boolean isPossible(int r, int c) {
    if (r >= 0 && r < 4 && c >= 0 && c < 4)
      return true;
    return false;
  }
}

class Open {
  boolean isOpen;
  int r;
  int c;
  int card;

  public Open() {
    this.isOpen = false;
    this.r = -1;
    this.c = -1;
    this.card = -1;
  }

  public Open(boolean isOpen, int r, int c, int card) {
    this.isOpen = isOpen;
    this.r = r;
    this.c = c;
    this.card = card;
  }
}

class Position {
  int r;
  int c;
  int t;
  int leftcard;
  Open o;

  public Position(int r, int c, int t, int leftcard, Open o) {
    this.r = r;
    this.c = c;
    this.t = t;
    this.leftcard = leftcard;
    this.o = o;
  }

  public Position(int r, int c, int t, int leftcard) {
    this.r = r;
    this.c = c;
    this.t = t;
    this.leftcard = leftcard;
    this.o = new Open();
  }
}
