import java.util.Scanner;

public class liquid {
    static Scanner sc = new Scanner(System.in);
    static int n = sc.nextInt();
    static long[] liquids = new long[n];
    static int mid;
    static long temp_num = 1000000000;
    static int temp_index;

    public static void trySum(int index, int start, int end) {
        while (start + 1 < end) {
            mid = (start + end) / 2;
            long sum = liquids[index] + liquids[mid];
            if (sum < 0)
                start = mid;
            else
                end = mid;
            if (Math.abs(sum) < Math.abs(temp_num))
                temp_num = sum;
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < n; i++) {
            liquids[i] = sc.nextLong();
        }
        mergeSort(liquids, 0, n - 1);

    }

    static long[] temp = new long[100000];

    public static void mergeSort(long arr[], int start, int end) {
        if (start >= end) {
            return;
        } else {
            int mid = (start + end) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);

            merging(arr, start, mid, mid + 1, end);
        }
    }

    public static void merging(long arr[], int s1, int e1, int s2, int e2) {
        int p = s1;
        int q = s2;
        int temp_index = 0;

        while (p <= e1 && q <= e2) {
            if (arr[p] <= arr[q]) {
                temp[temp_index++] = arr[p];
                p++;
            } else {
                temp[temp_index++] = arr[q];
                q++;
            }
        }

        if (p > e1) {
            for (int i = q; i <= e2; i++)
                temp[temp_index++] = arr[i];
        } else {
            for (int i = p; i <= e1; i++)
                temp[temp_index++] = arr[i];
        }

        for (int i = s1; i <= e2; i++) {
            arr[i] = temp[i - s1];
        }
    }
}