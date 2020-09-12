import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B11659 {

  static int N, M;
  static int[] nums;
  static int[] sums;

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    nums = new int[N + 1];
    sums = new int[N + 1];
    st = new StringTokenizer(br.readLine());
    for (int i = 1; i <= N; i++) {
      nums[i] = Integer.parseInt(st.nextToken());
    }
    fillDP();
    int from, to;
    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      from = Integer.parseInt(st.nextToken());
      to = Integer.parseInt(st.nextToken());
      int ans = sums[to] - sums[from - 1];
      System.out.println(ans);
    }
  }

  static void fillDP() {
    sums[1] = nums[1];
    for (int i = 2; i <= N; i++) {
      sums[i] = sums[i - 1] + nums[i];
    }
  }
}