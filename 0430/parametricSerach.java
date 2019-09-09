import java.util.Scanner;
public class Main {
    static Scanner sc = new Scanner(System.in);
    static int n = sc.nextInt();
    static int S = sc.nextInt();
    static int[] data = new int[n];

    public static boolean check(int interval){
        int sum = 0;
        for (int i = 0; i < interval; i++) sum += data[i];
        if (sum >= S) return true;
        for (int i = 0; i < n-interval; i++){
            sum = sum - data[i] + data[i+interval];
            if(sum >= S) return true;
        }
        return false;
    }
    public static void main(String[] args) {
        for (int i = 0; i < n; i ++) data[i] = sc.nextInt();
        
        int start = 1; //start는 X
        int end = n; //end는 O

        if(check(1)) System.out.print(1);
        if(!check(n)) System.out.print(-1);

        while (start+1 < end){
            int mid = (start+end) / 2;
            if (check(mid)) end = mid;
            else start = mid;
        }

        System.out.print(end);
    }
}