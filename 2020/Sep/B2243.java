import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B2243 {

  static int N, S, tempans;
  static int[] tree;
  static final int MAX = 1000000;
  static final int IN = 2;
  static final int OUT = 1;

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    N = Integer.parseInt(br.readLine());
    S = 1;
    while (S < MAX)
      S *= 2;
    tree = new int[S * 2];

    int q, arg1, arg2;
    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      q = Integer.parseInt(st.nextToken());
      arg1 = Integer.parseInt(st.nextToken());
      if (q == IN) {
        arg2 = Integer.parseInt(st.nextToken());
        update(1, S, 1, arg1, arg2);
      } else {
        query(1, S, 1, arg1);
        update(1, S, 1, tempans, -1);
        System.out.println(tempans);
      }
    }
  }

  static void query(int start, int end, int node, int target) {
    if (start == end) {
      tempans = start;
      return;
    }
    int mid = (start + end) / 2;
    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    if (tree[leftNode] >= target)
      query(start, mid, leftNode, target);
    else
      query(mid + 1, end, rightNode, target - tree[leftNode]);
  }

  static void update(int start, int end, int node, int taste, int diff) {
    if (start > taste || end < taste)
      return;
    tree[node] += diff;
    if (start == end)
      return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, taste, diff);
    update(mid + 1, end, node * 2 + 1, taste, diff);
  }

}
