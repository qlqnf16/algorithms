package algorithm;
import java.util.Scanner;

public class MostAlphabet {
      static int TC, maxIndex;
      static int alphabets[];
      
      public static void countAlphabet(String s) {
    	  int temp;
    	  for (int i = 0; i < s.length(); i++) {
    		  temp = (int)s.charAt(i);
    		  if (temp >= 97 && temp <= 122) {
    			  alphabets[temp - 97] += 1;
    		  }
    	  }
      }
      
      public static void findMax() {
    	  int max = 0;
    	  for (int i = 0; i < 26; i++) {
    		  if (alphabets[i] > max) {
    			  max = alphabets[i];
    			  maxIndex = i;
    		  }
    	  }
      }
 
      public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            TC = sc.nextInt();
            sc.nextLine();
           
            for (int tcase = 0; tcase<TC; tcase++) {
                  // 여기서부터 작성
            	alphabets = new int[26];
            	String inputString = sc.nextLine();
            	countAlphabet(inputString);
            	findMax();
            	System.out.println((char)(maxIndex+97));
 
            }
            sc.close();
      }
}