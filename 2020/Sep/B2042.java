import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B2042 {
  static int N, M, K, S;
  static int[] nums;
  static long[] tree;

  static int MODIFY = 1;
  static int GETSUM = 2;

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());
    S = 1;
    while (S < N)
      S *= 2;
    tree = new long[S * 2];
    nums = new int[N + 1];
    for (int i = 1; i <= N; i++) {
      nums[i] = Integer.parseInt(br.readLine());
    }
    init(1, S, 1);
    int q, arg1, arg2;

    for (int i = 0; i < M + K; i++) {
      st = new StringTokenizer(br.readLine());
      q = Integer.parseInt(st.nextToken());
      arg1 = Integer.parseInt(st.nextToken());
      arg2 = Integer.parseInt(st.nextToken());
      if (q == MODIFY) {
        long diff = arg2 - tree[arg1 + S - 1];
        update(1, S, 1, arg1, diff);
      } else {
        System.out.println(query(1, S, 1, arg1, arg2));
      }
    }
  }

  static long init(int start, int end, int node) {
    if (start == end) {
      if (node - S < N)
        tree[node] = nums[node - S + 1];
      return tree[node];
    }
    int mid = (start + end) / 2;
    tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    return tree[node];
  }

  static long query(int start, int end, int node, int left, int right) {
    if (right < start || left > end)
      return 0;
    if (left <= start && right >= end)
      return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
  }

  static void update(int start, int end, int node, int idx, long diff) {
    if (start > idx || end < idx)
      return;
    tree[node] += diff;
    if (start == end)
      return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, idx, diff);
    update(mid + 1, end, node * 2 + 1, idx, diff);
  }
}
