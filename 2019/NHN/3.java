import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;

class Main {
  static int n;
  static int[] players;
  static ArrayList<Integer>[] followers;
  static boolean[] visit;

  public static void add(int p) {
    players[p] += 1;
    follow(p);
  }

  public static void follow(int p) {
    for (int f : followers[p]) {
      if (visit[f] == false) {
        visit[f] = true;
        players[f] += 1;
        follow(f);
      }
    }
  }

  public static void ace(int p) {
    add(p);
    visit = new boolean[n + 1];
  }

  public static void jack(int p) {
    if (p == 0) {
      add(n - 1);
      add(1);
    } else if (p == n - 1) {
      add(n - 2);
      add(0);
    } else {
      add(p - 1);
      add(p + 1);
    }
    visit = new boolean[n + 1];
  }

  public static void queen() {
    for (int i = 0; i < n; i++) {
      players[i] += 1;
    }
  }

  public static void king(int p, int f) {
    followers[p].add(f);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    sc.nextLine();
    String orderLine = sc.nextLine();

    players = new int[n];
    followers = new ArrayList[n];
    visit = new boolean[n];
    for (int i = 0; i < n; i++) {
      followers[i] = new ArrayList<Integer>();
    }

    String[] orders = orderLine.split("\\s");
    int index = 0;
    int currentPlayer = 0;
    while (index < orders.length) {
      if (currentPlayer >= n) {
        currentPlayer -= n;
      }
      if (orders[index].equals("A")) {
        ace(currentPlayer);
      } else if (orders[index].equals("J")) {
        jack(currentPlayer);
      } else if (orders[index].equals("Q")) {
        queen();
      } else {
        king(currentPlayer, Integer.parseInt(orders[index + 1]));
        index++;
      }
      currentPlayer++;
      index++;
    }

    for (int i = 0; i < n; i++) {
      System.out.print(players[i] + " ");
    }
  }
}