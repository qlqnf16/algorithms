import java.io.*;
import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int r = sc.nextInt();
    sc.nextLine();

    ArrayList<HashMap<String, Integer>>[] routes = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      routes[i] = new ArrayList<HashMap<String, Integer>>();
    }

    for (int i = 0; i < r; i++) {
      String orderline = sc.nextLine();
      HashMap<String, Integer> hashMap = new HashMap<>();
      hashMap.put(orderline.split("\\s")[1], Integer.parseInt(orderline.split("\\s")[2]));

      for (char alpha : orderline.split("\\s")[0].toCharArray()) {
        int routeIndex = (int) alpha;
        routes[routeIndex].add(hashMap);
      }
    }
  }
}