package algorithm;  
import java.util.Scanner;
public class ComparePhoneNumber {
 
      static int N;
      static int [] sortBase;
      static String [] phoneNumbers;
      
      public static boolean ALargerThanB(String a, String b) {
    	  int locNumA = -1, locNumB = -1;
    	  String[] numA = a.split("\\-");
    	  String[] numB = b.split("\\-");
    	  
    	  // 지번 비교 
    	  for (int i = 0; i < 6; i++) {
    		  if (sortBase[i] == Integer.parseInt(numA[0])%10) locNumA = i;
    		  if (sortBase[i] == Integer.parseInt(numB[0])%10) locNumB = i;
    	  }
    	  if (locNumA > locNumB) return true;
    	  if (locNumA < locNumB) return false;
    	  
    	  // 중간자리 비교 
    	  if (numA[1].length() > numB[1].length()) return false;
    	  if (numA[1].length() < numB[1].length()) return true;
    	  if (Integer.parseInt(numA[1]) > Integer.parseInt(numB[1])) return true;
    	  if (Integer.parseInt(numA[1]) < Integer.parseInt(numB[1])) return false;
    	  
    	  // 마지막자리 비교
    	  if (Integer.parseInt(numA[2]) > Integer.parseInt(numB[2])) return true;
    	  return false;
      }
      
      public static void sortNumber() {
    	  String tempString;
      
    	  for (int i = 0; i < N; i++) {
    		  for (int j = i+1; j < N; j++) {
    			  if (ALargerThanB(phoneNumbers[i], phoneNumbers[j])) {
    				  tempString = phoneNumbers[i];
    				  phoneNumbers[i] = phoneNumbers[j];
    				  phoneNumbers[j] = tempString;
    			  }
    		  }
		  }
      }
 
      public static void main(String[] args) {
 
            // 입력받는 부분
            Scanner sc = new Scanner(System.in);
            N = sc.nextInt();
            sortBase = new int[6];
            for(int i = 0; i<sortBase.length; i++)
            {
                  sortBase[i] = sc.nextInt();
            }
            phoneNumbers = new String[N];
            for(int i = 0; i<phoneNumbers.length; i++)
            {
                  phoneNumbers[i] = sc.next();
            }
            sortNumber();
            for (int i = 0; i < N; i++) {
            	System.out.println(phoneNumbers[i]);
            }
            sc.close();
 
            // 여기서부터 작성
           
      }
}