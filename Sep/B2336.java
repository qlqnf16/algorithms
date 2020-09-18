import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B2336 {

  static int N, S;
  static Student[] scores;
  static int[] tree;

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    init();
    int idx;
    StringTokenizer st = new StringTokenizer(br.readLine());
    for (int rank = 1; rank <= N; rank++) {
      idx = Integer.parseInt(st.nextToken());
      scores[idx].first = rank;
    }
    st = new StringTokenizer(br.readLine());
    for (int rank = 1; rank <= N; rank++) {
      idx = Integer.parseInt(st.nextToken());
      scores[idx].second = rank;
    }
    st = new StringTokenizer(br.readLine());
    for (int rank = 1; rank <= N; rank++) {
      idx = Integer.parseInt(st.nextToken());
      scores[idx].third = rank;
    }
    Arrays.sort(scores);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
      int tempmin = query(1, S, 1, 1, scores[i].second);
      if (tempmin > scores[i].third)
        ans++;
      update(1, S, 1, scores[i].second, scores[i].third);
    }
    System.out.println(ans);
  }

  static void init() {
    scores = new Student[N + 1];
    for (int i = 0; i <= N; i++) {
      scores[i] = new Student();
    }
    S = 1;
    while (S < N)
      S *= 2;
    tree = new int[S * 2];
    for (int i = 0; i < S * 2; i++) {
      tree[i] = Integer.MAX_VALUE;
    }
  }

  static int update(int start, int end, int node, int idx, int val) {
    if (idx < start || idx > end)
      return tree[node];
    if (start == end)
      return tree[node] = val;
    int mid = (start + end) / 2;
    tree[node] = Math.min(update(start, mid, node * 2, idx, val), update(mid + 1, end, node * 2 + 1, idx, val));
    return tree[node];
  }

  static int query(int start, int end, int node, int left, int right) {
    if (left > end || right < start)
      return Integer.MAX_VALUE;
    if (left <= start && right >= end)
      return tree[node];
    int mid = (start + end) / 2;
    return Math.min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
  }
}

class Student implements Comparable<Student> {
  int first;
  int second;
  int third;

  public Student() {
    super();
  }

  @Override
  public int compareTo(Student o) {
    return first - o.first;
  }
}
