import java.util.Scanner;
public class Main{
    static Scanner sc = new Scanner(System.in);
    static int n = sc.nextInt();
    static char[] arr = new char[n];
    static int[] nums = new int[n+1];
    static boolean[] check = new boolean[10];
    static boolean[] change = new boolean[10];

    public static void maximum(int index){
        if (index == n+1) {
            for (int i = 0; i < n+1; i ++){
                System.out.print(nums[i]);
            } System.out.println();
        } else {
            for (int i = 9; i >= 0; i --){
                if (change[n] == true) break;
                if (index != 0) {
                    if (arr[index-1] == '>'){
                        if (nums[index-1] > i && check[i] == false) {
                            nums[index] = i;
                            check[i] = true;
                            change[index] = true;
                            maximum(index+1);
                            check[i] = false;
                        }
                    } else {
                        if (nums[index-1] < i && check[i] == false) {
                            nums[index] = i;
                            check[i] = true;
                            change[index] = true;
                            maximum(index+1);
                            check[i] = false;
                        }
                    }
                } else {
                    nums[index] = i;
                    check[i] = true;
                    change[index] = true;
                    maximum(index+1);
                    check[i] = false;
                }
            }
        }
    }

    public static void minimum(int index){
        if (index == n+1) {
            for (int i = 0; i < n+1; i ++){
                System.out.print(nums[i]);
            } System.out.println();
        } else {
            for (int i = 0; i < 10; i ++){
                if (change[n] == true) break;
                if (index != 0) {
                    if (arr[index-1] == '>'){
                        if (nums[index-1] > i && check[i] == false) {
                            nums[index] = i;
                            change[index] = true;
                            check[i] = true;
                            minimum(index+1);
                            check[i] = false;
                        }
                    } else {
                        if (nums[index-1] < i && check[i] == false) {
                            nums[index] = i;
                            change[index] = true;
                            check[i] = true;
                            minimum(index+1);
                            check[i] = false;
                        }
                    }
                } else {
                    nums[index] = i;
                    check[i] = true;
                    minimum(index+1);
                    check[i] = false;
                }
            }
        }
    }

    public static void main(String[] args){
        for (int i = 0; i < n; i++){
            arr[i] = sc.next().charAt(0);
        }
        maximum(0);
        nums = new int[n+1];
        change = new boolean[10];          
        minimum(0);
    }
}