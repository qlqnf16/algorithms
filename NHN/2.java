import java.io.*;
import java.util.Scanner;

public class Main {
  static int[] FQ = new int[101];
  static int[] count = new int[101];
  static int end = 0;

  public static void enqueue(int n) {
    FQ[end] = n;
    end++;
    count[n] += 1;
  }

  public static void dequeue() {
    int index = findMostFrequent();
    System.out.print(FQ[index] + " ");
    count[FQ[index]]--;
    FQ[index] = 0;
  }

  public static int findMostFrequent() {
    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i < 101; i++) {
      if (count[FQ[i]] > max) {
        max = count[FQ[i]];
        maxIndex = i;
      }
    }
    return maxIndex;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    for (int i = 0; i < N; i++) {
      String order = sc.next();
      if (order.equals("enqueue")) {
        int n = sc.nextInt();
        enqueue(n);
      } else {
        dequeue();
      }
    }

  }
}