import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B1717 {
  static int N, M;
  static int[] union;

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    init();
    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int q = Integer.parseInt(st.nextToken());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      if (q == 0)
        union(a, b);
      else {
        if (find(a) == find(b))
          System.out.println("YES");
        else
          System.out.println("NO");
      }
    }
  }

  static void init() {
    union = new int[N + 1];
    for (int i = 0; i <= N; i++) {
      union[i] = i;
    }
  }

  static void union(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    union[roota] = rootb;
  }

  static int find(int a) {
    if (union[a] == a)
      return a;
    return union[a] = find(union[a]);
  }
}
