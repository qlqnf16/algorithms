package algorithm;
import java.util.Scanner;
 
public class Palindrome {
 
      static int N, M, sym, size;
      static int[] digits;

      public static int reverseNum(int num) {
    	  String numString = Integer.toString(num);
    	  String reverseString = (new StringBuffer(numString)).reverse().toString();
    	  return Integer.parseInt(reverseString);
      }
 
      public static void iToArray(int num) {
    	  String tempString = Integer.toString(num);
    	  size = tempString.length();
    	  digits = new int[size];
    	  for (int i = 0; i < size; i++) {
    		  digits[i] = tempString.charAt(i) - '0';
    	  }
      }
      
      public static void isPalindrome() {
    	  for (int i = 0; i < size / 2; i++) {
    		  if (digits[i] != digits[size-i-1]) {
    			  sym = 0;
    			  return;
    		  }
    	  }
    	  sym = 1;
	}
      
      public static void main(String[] args) {
           
            // 입력받는 부분
            Scanner sc = new Scanner(System.in);
            N = sc.nextInt();
 
            // 여기서부터 작성
            for(int i=0; i<N; i++)
            {
                  // 입력받는 부분
                  M = sc.nextInt();
 
                  // 여기서부터 작성
                  int reverseNum = reverseNum(M);
                  int sum = reverseNum + M;
                  iToArray(sum);
                  isPalindrome();
                  
                  // 출력하는 부분
                  if(sym == 1)      System.out.println("YES");
                  else  System.out.println("NO");
            }          
            sc.close();
           
      }
}