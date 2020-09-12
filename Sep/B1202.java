// 백준 1202 보석도둑

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B1202 {
  static int N, K;
  static Gem[] gems;
  static int[] bags;

  public static void main(String[] arg) throws Exception {
    System.setIn(new FileInputStream("./input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());
    gems = new Gem[N];
    bags = new int[K];

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      int value, weight;
      weight = Integer.parseInt(st.nextToken());
      value = Integer.parseInt(st.nextToken());
      gems[i] = new Gem(value, weight);
    }
    for (int i = 0; i < K; i++) {
      bags[i] = Integer.parseInt(br.readLine());
    }

    Arrays.sort(bags);
    Arrays.sort(gems);

    long ans = 0;
    int gemIdx = 0;

    PriorityQueue<Integer> temp = new PriorityQueue<>(Collections.reverseOrder());
    for (int i = 0; i < K; i++) {
      while (gemIdx < N) {
        if (gems[gemIdx].weight > bags[i])
          break;
        temp.add(gems[gemIdx++].value);
      }
      if (temp.isEmpty())
        continue;
      ans += temp.poll();
    }

    System.out.println(ans);
  }
}

class Gem implements Comparable<Gem> {
  int value;
  int weight;

  public Gem(int value, int weight) {
    this.value = value;
    this.weight = weight;
  }

  @Override
  public int compareTo(Gem o) {
    return this.weight - o.weight;
  }
}