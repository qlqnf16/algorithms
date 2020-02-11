import java.util.Scanner;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
  static int N, M;
  static ArrayList<Integer>[] graph;
  static boolean[] color;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    M = sc.nextInt();
    graph = new ArrayList[N + 1];
    color = new boolean[N + 1];

    for (int i = 0; i <= N; i++) {
      graph[i] = new ArrayList<Integer>();
    }

    for (int i = 0; i < M; i++) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      graph[a].add(b);
      graph[b].add(a);
    }

    bfs(0);
  }

  public static void bfs(int start) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(start);
    color[start] = true;

    while (true) {
      if (queue.isEmpty() == true)
        break;

      int current = queue.remove();
      System.out.print(current + " ");

      for (int n : graph[current]) {
        if (color[n] == false) {
          color[n] = true;
          queue.add(n);
        }
      }
    }
  }

}