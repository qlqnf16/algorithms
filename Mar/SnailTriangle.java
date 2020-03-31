package algorithm; 
import java.util.Scanner;

public class SnailTriangle {

     static int N;
     static int[][] table;
     static boolean[][] visit;
     static int dirIndex = 0;
     static int[][] dir = {{1, 1}, {0, -1}, {-1, 0}};
     
     public static void fillTable() {
    	 int c = 0, r = 0, num = 1;
    	 int end0 = N-1, end1 = 0, end2 = 1;
    	 visit[0][0] = true;
    	 
    	 while (true) {
			c = c + dir[dirIndex][0];
			r = r + dir[dirIndex][1];
			//System.out.println(c + " " + r);
			
			if (visit[c][r]) return;
			table[c][r] = num++;
			visit[c][r] = true;
			if (num == 10) num = 0;
			
			if (dirIndex == 0 && c == end0) {
				dirIndex = 1;
				end0 --;
			}
			if (dirIndex == 1 && r == end1) {
				dirIndex = 2;
				end1 ++;
			}
			if (dirIndex == 2 && c == end2) {
				dirIndex = 0;
				end2 += 2;
			}
		}
     }
    
     public static void main(String[] args) {
          
           // 입력받는 부분
           Scanner sc = new Scanner(System.in);
           N = sc.nextInt();
           table = new int[N][N];
           visit = new boolean[N][N];
           
           sc.close();

           // 여기서부터 작성
           fillTable();
           for (int i = 0; i < N; i++) {
        	   for (int j = 0; j < N; j++) {
        		   if (visit[i][j]) System.out.print(table[i][j] + " ");
        	   }
        	   System.out.println();
           }
     }
}