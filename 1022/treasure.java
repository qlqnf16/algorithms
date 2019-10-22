import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
  static int N;
  static int M;
  static int[][] map;
  static int[][] direction = { { 0, 0, -1, 1 }, { -1, 1, 0, 0 } };
  static boolean[][] check;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    M = sc.nextInt();
    N = sc.nextInt();
    map = new int[M][N];
    check = new boolean[M][N];
    int K = sc.nextInt();

    for (int i = 0; i < K; i++) {
      int leftN = sc.nextInt();
      int leftM = M - 1 - sc.nextInt();
      int rightN = sc.nextInt() - 1;
      int rightM = M - sc.nextInt();
      for (int m = rightM; m <= leftM; m++) {
        for (int n = leftN; n <= rightN; n++) {
          map[m][n] = 1;
        }
      }
    }

    int[][] coners = { { 0, M - 1, 0, M - 1 }, { 0, 0, N - 1, N - 1 } };
    List<Integer> areas = new ArrayList<Integer>(4);
    int count = 0;

    // for (int n = 0; n < N; n++) {
    // if (n == 0 || n == N - 1) {
    // for (int m = 0; m < M; m++) {
    // if (map[m][n] == 0 && !check[m][n]) {
    // count += 1;
    // Integer[] start = new Integer[] { m, n };
    // areas.add(getArea(start));
    // }
    // }
    // } else {
    // if (map[0][n] == 0 && !check[0][n]) {
    // count += 1;
    // Integer[] start = new Integer[] { 0, n };
    // areas.add(getArea(start));
    // }
    // if (map[M-1][n] == 0 && !check[M-1][n]) {
    // count += 1;
    // Integer[] start = new Integer[] { 0, n };
    // areas.add(getArea(start));
    // }
    // }
    // }

    for (int i = 0; i < 4; i++) {
      int m = coners[0][i];
      int n = coners[1][i];
      if (map[m][n] == 0 && !check[m][n]) {
        count += 1;
        Integer[] start = new Integer[] { m, n };
        areas.add(getArea(start));
      }
    }

    System.out.println(count);
    sort(areas);
    print(sort(areas));
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
          check[nextM][nextN] = true;
          queue.offer(nextLoc);
        }
      }
    }

    return area;
  }

  public static void print(List<Integer> result) {
    result.stream().forEach(item -> System.out.print(String.format("%d ", item)));
    System.out.println();
  }

  public static List<Integer> sort(List<Integer> targetList) {
    if (targetList.size() > 1) {
      return merge(sort(targetList.subList(0, targetList.size() / 2)),
          sort(targetList.subList(targetList.size() / 2, targetList.size())));
    } else {
      return targetList;
    }
  }

  public static List<Integer> merge(List<Integer> left, List<Integer> right) {
    List<Integer> result = new ArrayList<>();
    int rightIdx = 0;

    for (Integer l : left) {
      while (right.size() > rightIdx && l > right.get(rightIdx)) {
        result.add(right.get(rightIdx));
        rightIdx++;
      }
      result.add(l);
    }
    for (int i = rightIdx; i < right.size(); i++) {
      result.add(right.get(i));
    }
    return result;
  }
}