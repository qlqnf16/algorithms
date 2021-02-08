import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B3955 {
  static int T;
  static int A, B;
  static final int INF = 1000000000;

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    T = Integer.parseInt(br.readLine());
    for (int t = 0; t < T; t++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      A = Integer.parseInt(st.nextToken());
      B = Integer.parseInt(st.nextToken());
      int ans = solve(A, B);
      if (ans == -1)
        System.out.println("IMPOSSIBLE");
      else
        System.out.println(ans);
    }
  }

  static int solve(int A, int B) {
    // - Ax + By = 1;
    if (A == 1)
      return 1;
    if (B == 1)
      return A + 1;
    int D = gcd(A * -1, B);
    // System.out.println("D " + D);
    if (1 % D != 0)
      return -1;
    int[] eeReturn = ee(A * -1, B);
    int x0 = eeReturn[0];
    int y0 = eeReturn[1];

    int minBorder = (int) Math.ceil(D * (y0 - INF) / (double) A);
    int maxBorder = (int) Math.floor(D * y0 / (double) A);
    // System.out.println(maxBorder + " " + minBorder);
    if (minBorder > maxBorder)
      return -1;
    int res = Math.min(y0 - (A * minBorder / D), y0 - (A * maxBorder / D));
    return res;
  }

  static int gcd(int a, int b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }

  static int[] ee(int a, int b) {
    int s, t, r, q;
    int s1 = 1;
    int t1 = 0;
    int r1 = a;
    int s2 = 0;
    int t2 = 1;
    int r2 = b;

    while (r2 != 0) {
      q = r1 / r2;
      r = r1 - r2 * q;
      s = s1 - s2 * q;
      t = t1 - t2 * q;

      r1 = r2;
      r2 = r;
      s1 = s2;
      s2 = s;
      t1 = t2;
      t2 = t;
    }

    int[] res = { s1, t1 };
    return res;
  }
}
