package algorithm; 
import java.util.Scanner;
 
public class Calculator {

      static String str;
      static String[] nums;
      static long sol;
      
      public static void solve() {
    	  int numIndex = 1;
    	  nums = str.split("\\+|\\-");
    	  sol = Long.parseLong(nums[0]);
    	  
    	  for (int i = 1; i < str.length(); i++) {
    		  if (str.charAt(i) == '+') {
    			  sol += Long.parseLong(nums[numIndex++]);
    		  }
    		  if (str.charAt(i) == '-') {
    			  sol -= Long.parseLong(nums[numIndex++]);
    		  }
    	  }
      }
     
      public static void main(String[] args) {
 
            // 입력받는 부분
            Scanner sc = new Scanner(System.in);
            str = sc.nextLine();
            sc.close();
 
            // 여기서부터 작성
            solve();
                       
            // 출력하는 부분
            System.out.print(sol);
      }
}