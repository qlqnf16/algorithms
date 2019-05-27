import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int n = sc.nextInt();
    static long sum;

    public static long count(long num) {
        sum = 0;
        for (long i = 1; i <= n; i++) {
            if (num > i * n)
                sum += n;
            else if (num <= i)
                break;
            else {
                sum += num / i;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        long K = sc.nextLong();
        long start = 1;
        long end = n * n;
        long mid;
        if (K == 1)
            System.out.print(1);
        else {
            while (start + 1 < end) {
                mid = (start + end) / 2;
                if (count(mid) > K)
                    end = mid;
                else
                    start = mid;
            }
            System.out.print(end);
        }
    }
}