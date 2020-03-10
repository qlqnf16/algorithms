import java.util.Scanner;
public class Main{
    public static int binarySearch(int arr[], int start, int end, int value){
        // arr의 start부터 end까지 값 중에서
        // value가 존재한다면 그 위치를 반환하고,
        // 그렇지 않다면 -1을 반환하는 함수

        if (start > end) return -1;
        else if (start == end) {
            if (arr[start] == value) return start;
            else return -1;
        } else {
            int mid = (start+end)/2;
            if (arr[mid] == value) return mid;
            else if (mid > value) return binarySearch(arr, start, mid-1, value);
            else return binarySearch(arr, mid+1, end, value);
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        // arr은 정렬되어 있다고 가정
        for (int i = 0; i < n; i ++){
            arr[i] = sc.nextInt();
        }
        int m = sc.nextInt();

        int index = binarySearch(arr, 0, n-1, m);
        if (index == -1) System.out.print("숫자가 없어요");
        else {
            System.out.print(index+"번째에 있습니다");
        }
    }
}