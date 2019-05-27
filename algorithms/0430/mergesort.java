import java.util.Scanner;
public class Main{
    static int[] temp = new int[100000];

    public static void mergeSort(int arr[], int start, int end){
        if (start >= end) {
            return;
        } else {
            // 1. 왼쪽 절반 합병정렬
            // 2. 오른쪽 절반 합병정렬
            // 3. 합치기
            int mid = (start + end) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid+1, end);

            // arr[start~mid], arr[mid+1~end]는 이미 정렬되어 있음
            merging(arr, start, mid, mid+1, end);
        }
    }

    public static void merging(int arr[], int s1, int e1, int s2, int e2){
        int p = s1; int q = s2;
        int temp_index = 0;

        while (p <= e1 && q <= e2){
            if(arr[p] <= arr[q]){
                temp[temp_index++] = arr[p];
                p ++;
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

        for (int i = s1; i <= e2; i++){
            arr[i] = temp[i-s1];
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] numbers = new int[n];
        for (int i = 0; i < n; i ++){
            numbers[i] = sc.nextInt();
        }
        mergeSort(numbers, 0, n-1);
        for (int i = 0; i < n; i++){
            System.out.print(numbers[i] + " ");
        }
    }
}