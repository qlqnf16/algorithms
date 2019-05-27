import java.util.Scanner;
public class Main{
    static int[] temp = new int[300000];

    public static int binarySearch(int[] arr, int start, int end, int value) {
        if (start > end) return 0;
        else if (start == end) {
            if (arr[start] == value) return 1;
            else return 0;
        } else {
            int mid = (start+end) / 2;
            if (arr[mid] == value) return 1;
            else if (arr[mid] > value) return binarySearch(arr, start, mid-1, value);
            else return binarySearch(arr, mid+1, end, value);
        }
    }
    public static void mergeSort(int arr[], int start, int end){
        if (start >= end) return;
        else {
            int mid = (start+end)/2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid+1, end);
            merging(arr, start, mid, mid+1, end);
        }
    }
    public static void merging(int arr[], int s1, int e1, int s2, int e2) {
        int p = s1;
        int q = s2;
        int temp_index = 0;
        while (p <= e1 && q <= e2){
            if (arr[p] < arr[q]) {
                temp[temp_index++] = arr[p];
                p ++;
            } else {
                temp[temp_index++] = arr[q];
                q ++;
            }
        }
        if (p > e1) {
            for (int i = q; i <= e2; i++)
                temp[temp_index++] = arr[i];
        } else {
            for (int i = p; i <= e1; i++) 
                temp[temp_index++] = arr[i];
        }

        for (int i = s1; i <= e2; i++)
            arr[i] = temp[i-s1];
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] numbers = new int[N];
        for (int i = 0; i < N; i ++) numbers[i] = sc.nextInt();
        // 정렬 먼저!
        mergeSort(numbers, 0, N-1);

        int M = sc.nextInt();
        for (int i = 0; i < M; i ++){
            int number = sc.nextInt();
            System.out.println(binarySearch(numbers, 0, N-1, number));
        }
    }
}