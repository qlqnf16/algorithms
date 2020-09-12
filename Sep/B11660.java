import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B11660 {

  static int N, M;
  static int[][] table;
  static long[][] dp;
  static int r1, c1, r2, c2;

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    table = new int[N + 1][N + 1];
    for (int i = 1; i <= N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 1; j <= N; j++) {
        table[i][j] = Integer.parseInt(st.nextToken());
      }
    }
    fillDP();
    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      r1 = Integer.parseInt(st.nextToken());
      c1 = Integer.parseInt(st.nextToken());
      r2 = Integer.parseInt(st.nextToken());
      c2 = Integer.parseInt(st.nextToken());
      long ans = dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
      System.out.println(ans);
    }
  }

  static void fillDP() {
    dp = new long[N + 1][N + 1];
    dp[1][1] = table[1][1];
    for (int i = 2; i <= N; i++) {
      dp[i][1] = dp[i - 1][1] + table[i][1];
      dp[1][i] = dp[1][i - 1] + table[1][i];
    }

    for (int i = 2; i <= N; i++) {
      for (int j = 2; j <= N; j++) {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + table[i][j] - dp[i - 1][j - 1];
      }
    }
  }
}
