import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class B9251 {

  static String word1, word2;
  static int[][] dp;

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    word1 = br.readLine();
    word2 = br.readLine();
    dp = new int[word1.length() + 1][word2.length() + 1];
    for (int i = 1; i <= word1.length(); i++) {
      for (int j = 1; j <= word2.length(); j++) {
        if (word1.charAt(i - 1) == word2.charAt(j - 1))
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    int ans = dp[word1.length()][word2.length()];
    System.out.println(ans);
  }
}
