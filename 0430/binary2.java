import java.util.Scanner;
public class Main{
    public static int binarySearch(int arr[], int myStart, int myEnd, int value){
        // arr의 myStart부터 myEnd까지 값 중에서
        // value가 존재한다면 그 위치를 반환하고,
        // 그렇지 않다면 -1을 반환하는 함수
        
        if (arr[myStart] > value || arr[myEnd] < value) return -1;
        // start는 value보다 항상 작고, end는 value보다 항상 크다
        else if (arr[myStart] == value) return myStart;
        else if (arr[myEnd] == value) return myEnd;

        int start = myStart;
        int end = myEnd;
        int mid = 0;

        while(end - start > 1){
            mid = (start + end) / 2;
            if (arr[mid] == value) return mid;
            else if (arr[mid] > value) end = mid;
            else start = mid;
        }

        return -1;
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