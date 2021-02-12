package algorithm;
import java.util.Scanner;

public class HappyNumber {

     static int N;
     static int sol;
     static int[] check = new int[1001];
     
     public static int sumDigit(int num) {
		int sum = 0;
		while (num > 0) {
			sum += (num % 10) * (num % 10);
			num /= 10;
		}
		return sum;
	}
     
     public static boolean isHappyNumber(int num) {
    	 int temp = num;
    	 while (true) {
    		 temp = sumDigit(temp);
    		 if (check[temp] == 1) return true;
    		 if (check[temp] == -1) return false;
    		 
    		 if (temp == 1) {
    			 for (int i = 0; i < 1001; i++) {
    				 if (check[i] == 2) check[i] = 1;
    			 }
    			 return true;
    		 }
    		 if (check[temp] == 2) {
    			 for (int i = 0; i < 1001; i++) {
    				 if (check[i] == 2) check[i] = -1;
    			 }
    			 return false;
    		 }
    		 if (temp < 1000) check[temp] = 2;
    	 }
     }
     
     public static void solve() {
    	 for (int i = N; i >= 1; i--) {
    		 if (isHappyNumber(i)) {
    			 sol = i;
    			 return;
    		 }
    	 }
	}
    
     public static void main(String[] args) {
          
           // 입력받는 부분
           Scanner sc = new Scanner(System.in);
           N = sc.nextInt();
           sc.close();

           // 여기서부터 작성
           solve();
           // 출력하는 부분
           System.out.print(sol);

     }
}