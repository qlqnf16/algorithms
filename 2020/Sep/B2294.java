import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B2294 {
  static int n, k;
  static Integer[] coins;
  static int[] dp;
  static int INF = Integer.MAX_VALUE - 1;

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());
    coins = new Integer[n];
    dp = new int[k + 1];
    for (int i = 0; i < n; i++) {
      coins[i] = Integer.parseInt(br.readLine());
    }

    for (int i = 1; i <= k; i++) {
      dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j < n; j++) {
        if (i - coins[j] >= 0) {
          dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }

    if (dp[k] == INF)
      dp[k] = -1;
    System.out.println(dp[k]);
  }
}
