import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B11053 {

  static int N;
  static int[] nums;
  static int[] dp;

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    nums = new int[N];
    dp = new int[N];
    StringTokenizer st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      nums[i] = Integer.parseInt(st.nextToken());
    }
    int ans = 1;
    for (int i = 0; i < N; i++) {
      dp[i] = 1;
      for (int j = i - 1; j >= 0; j--) {
        if (nums[j] < nums[i])
          dp[i] = Math.max(dp[i], dp[j] + 1);
      }
      ans = Math.max(ans, dp[i]);
    }

    System.out.println(ans);
  }
}