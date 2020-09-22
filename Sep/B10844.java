import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B10844 {

  static int N;
  static long[][] dp;
  static final int MOD = 1000000000;

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    dp = new long[N + 1][10];
    for (int i = 1; i < 10; i++) {
      dp[1][i] = 1;
    }

    for (int n = 2; n <= N; n++) {
      for (int i = 0; i < 10; i++) {
        if (i == 0) {
          dp[n][i] = dp[n - 1][1];
        } else if (i == 9) {
          dp[n][i] = dp[n - 1][8];
        } else {
          dp[n][i] = ((dp[n - 1][i - 1] % MOD) + (dp[n - 1][i + 1] % MOD)) % MOD;
        }
      }
    }

    long result = 0;
    for (int i = 0; i < 10; i++) {
      result = (result % MOD + dp[N][i] % MOD) % MOD;
    }

    System.out.println(result);
  }
}
