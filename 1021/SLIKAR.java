import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int[] locS = new int[2];
    int[] locD = new int[2];
    int[] locW = new int[2];

    int R = sc.nextInt();
    int C = sc.nextInt();
    String[][] map = new String[R][C];
    sc.nextLine();

    for (int i = 0; i < R; i++) {
      String line = sc.nextLine();
      String[] lines = line.split("");
      for (int j = 0; j < C; j++) {
        map[i][j] = lines[j];
        if (lines[j].equals("S")) {
          locS[0] = i;
          locS[1] = j;
        }
        if (lines[j].equals("D")) {
          locD[0] = i;
          locD[1] = j;
        }
        if (lines[j].equals("*")) {
          locW[0] = i;
          locW[1] = j;
        }
      }
    }

    int[][] direction = { { 0, 0, 1, -1 }, { 1, -1, 0, 0 } };
    int[][] distance = new int[R][C];

    // 고슴도치 이동 세팅
    boolean[][] check = new boolean[R][C];
    Queue<Integer> xQueue = new LinkedList<Integer>();
    Queue<Integer> yQueue = new LinkedList<Integer>();
    xQueue.offer(locS[0]);
    yQueue.offer(locS[1]);
    check[locS[0]][locS[1]] = true;
    int disCount = 1;

    // 물 전파 세팅
    boolean[][] check2 = new boolean[R][C];
    Queue<Integer> wxQueue = new LinkedList<Integer>();
    Queue<Integer> wyQueue = new LinkedList<Integer>();
    wxQueue.offer(locW[0]);
    wyQueue.offer(locW[1]);
    check2[locW[0]][locW[1]] = true;
    int wCount = 1;

    while (!check[locD[0]][locD[1]] && !xQueue.isEmpty() && !yQueue.isEmpty()) {
      int tempCount = 0;

      // 물 전파
      for (int c = 0; c < wCount; c++) {
        int x = wxQueue.poll();
        int y = wyQueue.poll();

        for (int i = 0; i < 4; i++) {
          int nextX = x + direction[0][i];
          int nextY = y + direction[1][i];
          if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && !check2[nextX][nextY]) {
            if (!map[nextX][nextY].equals("D") && !map[nextX][nextY].equals("X")) {
              wxQueue.offer(nextX);
              wyQueue.offer(nextY);
              map[nextX][nextY] = "*";
              check2[nextX][nextY] = true;
              tempCount += 1;
            }
          }
        }
      }
      wCount = tempCount;
      tempCount = 0;

      // 고슴도치 옮기기
      for (int c = 0; c < disCount; c++) {
        int x = xQueue.poll();
        int y = yQueue.poll();

        for (int i = 0; i < 4; i++) {
          int nextX = x + direction[0][i];
          int nextY = y + direction[1][i];
          if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && !check[nextX][nextY]) {
            if (map[nextX][nextY].equals(".") || map[nextX][nextY].equals("D")) {
              xQueue.offer(nextX);
              yQueue.offer(nextY);
              check[nextX][nextY] = true;
              distance[nextX][nextY] = distance[x][y] + 1;
              tempCount += 1;
            }
          }
        }
      }
      disCount = tempCount;
    }

    int dis = distance[locD[0]][locD[1]];
    if (dis <= 0) {
      System.out.print("KAKTUS");
    } else {
      System.out.print(dis);
    }
  }
}