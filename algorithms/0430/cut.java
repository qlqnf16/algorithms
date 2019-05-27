import java.util.Scanner;
public class Main{
    static Scanner sc = new Scanner(System.in);
    static int N = sc.nextInt();
    static int M = sc.nextInt();
    static int[] trees = new int[N];

    public static boolean check(int height){
        long sum = 0;
        for (int i = 0; i < N; i ++){
            if(height <= trees[i]) sum += trees[i]-height;
        }
        if (sum >= M) return true;
        else return false;
    }
    public static void main(String[] args){
        for (int i = 0; i < N; i ++) trees[i] = sc.nextInt();
        
        int max = 0;
        for (int i = 0; i < N; i++)
            if (trees[i] > max) max = trees[i];
        
        int start = 1;
        int end = max;
        int mid;
        while (start + 1 < end) {
            mid = (start + end) / 2;
            if (check(mid)) start = mid;
            else end = mid;
        }
        System.out.print(start);
    }
}