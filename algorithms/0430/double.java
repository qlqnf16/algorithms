import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i ++)
            arr[i] = sc.nextInt();
        
        int p = 0;
        int q = 0;
        int max = 0;
        int[] nums = new int[n+1];
        while (q <= p && p < n) {
            if (nums[arr[p]] != 1) {
                if (p-q+1 > max) max = p-q+1;
                nums[arr[p]] += 1;
                p ++; 
            } else {
                nums[arr[q]] -= 1;
                q ++;
            }
        }
        System.out.print(max);
    }
}