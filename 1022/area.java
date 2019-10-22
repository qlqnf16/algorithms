import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
  static int N;
  static int M;
  static int[][] map;
  static int[] direction = { { 0, 0, -1, 1 }, { -1, 1, 0, 0 } };
  static boolean[][] check = new boolean[M][N];

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    M = sc.nextInt();
    map = new int[M][N];
    int K = sc.nextInt();

    for (int i = 0; i < K; i++) {
      int leftM = sc.nextInt();
      int leftN = sc.nextInt();
      int rightM = sc.nextInt();
      int rightN = sc.nextInt();
      for (int m = leftM; m <= rightM; m++) {
        for (int n = leftN; n <= rightN; n++) {
          map[m][n] = 1;
        }
      }
    }

    int[] coners = { { 0, 0, N - 1, N - 1 }, { 0, M - 1, 0, M - 1 } };
    int[] areas = new int[4];
    int count = 0;

    for (int i = 0; i < 4; i++) {
      int m = coners[1][i];
      int n = coners[0][i];
      if (map[m][n] == 0 && !check[m][n]) {
        count += 1;
        Integer[] start = new Integer[] { m, n };
        areas[i] = getArea(start);
      }
    }

    System.out.println(count);
    for (int i = 0; i < 4; i++) {
      if (areas[i] > 0)
        System.out.print(areas[i] + " ");
    }
  }

  public static int getArea(Integer[] start) {
    Queue<Integer[]> queue = new LinkedList<Integer[]>();
    int area = 1;
    queue.offer(start);
    check[start[0]][start[1]] = true;

    while (!queue.isEmpty()) {
      int m = queue.peek()[0];
      int n = queue.peek()[1];
      queue.poll();

      for (int i = 0; i < 4; i++) {
        int nextM = m + direction[0][i];
        int nextN = n + direction[1][i];
        if (nextM >= 0 && nextM < M && nextN >= 0 && nextN < N && !check[nextM][nextN] && map[nextM][nextN] == 0) {
          area += 1;
          Integer[] nextLoc = new Integer[] { nextM, nextN };
          queue.offer(nextLoc);
        }
      }
    }

    return area;
  }
}