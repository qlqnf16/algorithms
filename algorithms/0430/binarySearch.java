import java.util.Scanner;
public class Main{
    public static boolean binarySearch(int[] arr, int myStart, int myEnd, int value){
        if (arr[myStart] == value) return true;
        else if (arr[myEnd] == value) return true;
        else if (arr[myStart] > value) return false;
        else if (arr[myEnd] < value) return false;

        int start = myStart;
        int end = myEnd;
        int mid = 0;

        while (end - start > 1) {
            mid = (start+end) / 2;
            if (arr[mid] == value) return true;
            else if (arr[mid] > value) end = mid;
            else start = mid;
        }

        return false;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int numbers[] = new int[n];
        for (int i = 0; i < n; i++){
            numbers[i] = sc.nextInt();
        }
        int question = 0;
        for (int i = 0; i < q; i ++){
            question = sc.nextInt();
            int start = 0;
            int end = n-1;
            if (binarySearch(numbers, start, end, question)) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}