import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    Map<String, Integer> cards = new HashMap<String, Integer>();
    int max = 0;

    for (int i = 0; i < n; i++) {
      String key = sc.next();
      if (cards.get(key) == null)
        cards.put(key, 1);
      else {
        int count = cards.get(key);
        cards.put(key, count + 1);
        if (count + 1 >= max)
          max = count + 1;
      }
    }

    Collection<Integer> cardCount = cards.values();
    boolean possible = true;
    int tempCount = 0;
    boolean addCard = false;

    for (int count : cardCount) {
      if (max - count >= 2) {
        possible = false;
        break;
      } else if (max - count == 1) {
        tempCount++;
        addCard = true;
      }

      if (tempCount > 1) {
        possible = false;
        break;
      }
    }

    if (possible) {
      System.out.println('Y');
      if (addCard)
        System.out.println(n + 1);
      else
        System.out.println(n);
      System.out.println(cards.size());
    } else {
      System.out.println('N');
      System.out.println(n);
      System.out.println(cards.size());
    }

  }
}