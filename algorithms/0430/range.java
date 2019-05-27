import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int n = sc.nextInt();
    static long[][] nums = new long[n][2];
    static long sum = 0;

    public static long count(long testnum) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i][0] <= testnum && nums[i][1] >= testnum)
                sum += testnum - nums[i][0];
            else if (nums[i][1] < testnum)
                sum += nums[i][1] - nums[i][0] + 1;
        }
        return sum;
    }

    public static void main(String[] args) {
        long min = 1000000001;
        long max = 0;
        for (int i = 0; i < n; i++) {
            nums[i][0] = sc.nextLong();
            if (nums[i][0] < min)
                min = nums[i][0];
            nums[i][1] = sc.nextLong();
            if (nums[i][1] > max)
                max = nums[i][1];
        }
        long index = sc.nextLong();
        long mid;
        if (min + 1 == max) {
            if (index == 1)
                System.out.print(max);
            else if (index == 0)
                System.out.print(min);
        } else {
            while (min + 1 < max) {
                mid = (min + max) / 2;
                if (count(mid) > index)
                    max = mid;
                else if (count(mid) < index)
                    min = mid;
                else
                    min = mid;
            }
            System.out.print(min);
        }
    }
}