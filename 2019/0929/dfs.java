import java.util.Scanner;
import java.util.ArrayList;

public class Main {
  static ArrayList<Integer>[] graph;
  static boolean[] check;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    graph = new ArrayList[N + 1];
    check = new boolean[N + 1];

    for (int i = 0; i <= N; i++) {
      graph[i] = new ArrayList<Integer>();
    }

    for (int i = 0; i < M; i++) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      graph[a].add(b);
      graph[b].add(a);
    }

    dfs(0);
  }

  public static void dfs(int node) {
    check[node] = true;
    System.out.print(node + " ");

    for (int n : graph[node]) {
      if (check[n] == false) {
        dfs(n);
      }
    }
  }
}