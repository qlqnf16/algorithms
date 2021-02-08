package algorithm;
import java.util.Scanner;

public class WithoutThree {
      static int N;
      static int sum;
      
      public static void solve(int num) {
    	  int base = 1;
    	  while (num > 0) {
    		  sum += (num % 10) * base;
    		  if (num % 10 > 3) sum -= base; 
    		  num /= 10;
    		  base *= 9;
    	  }
      }
     
      public static void main(String[] args) {
 
            // 입력받는 부분
            Scanner sc = new Scanner(System.in);
            N = sc.nextInt();
            sc.close();
 
            // 여기서부터 작성
            solve(N);
           
            // 출력하는 부분
            System.out.print(sum);
      }
}