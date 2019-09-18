import java.util.Scanner;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    long n = sc.nextLong();
    long m = sc.nextLong();
    int mod = 10007;

    long result = 1;
    long multiply = n;
    while (m > 0) {
      if (m % 2 == 1)
        result *= multiply;
      result %= mod;
      multiply = ((multiply % mod) * (multiply % mod)) % mod;
      m /= 2;
    }
    System.out.print(result);
  }
}