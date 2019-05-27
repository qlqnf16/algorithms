import java.util.Scanner;
public class Main{
    public static int check(long temp, long value) {
        // System.out.println(temp);
        if (temp*(temp+1) == value) return 0;
        else if (temp*(temp+1) < value) return -1;
        else return 1;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();

        long start = 0;
        long end = (long)Math.sqrt(a+a);

        while(start + 1 < end){
            long mid = (start+end) / 2;
            long temp = check(mid, a);
            if(temp == 0) {
                start = mid;
                break;
            }
            else if (temp == -1) start = mid;
            else if (temp == 1) end = mid;
        }
        System.out.print(start);
    }
}