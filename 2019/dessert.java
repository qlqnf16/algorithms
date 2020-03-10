import java.util.Scanner;
public class Main{
    static int count = 0;
    public static void dessert(int n, int index, int sum, char[] symbol, char[] arr, int[] nums) {
        if (index == n-1){
            if (sum == 0) {
                count ++;
                if (count <= 20){
                    for (int i = 0; i < n-1; i++){
                        System.out.print(i+1);
                        System.out.print(" "+arr[i]+" ");
                    } System.out.println(n+" ");
                }
            }
            for (int i = 0; i < n-1; i++){
                if (symbol[i] != 0) break;
                if (i == n-2) System.out.println(count);
            }
        }
        else {
            for (int i = 0; i < 3; i ++){
                if (i == 0) {
                    arr[index] = '+';
                    symbol[index] = '+';
                    nums[index+1] = index+2;
                    sum += nums[index+1];
                } else if (i == 1) {
                    arr[index] = '-';
                    symbol[index] = '-';
                    nums[index+1] = index+2;
                    sum -= nums[index+1];
                } else {
                    arr[index] = '.';
                    if (index + 2 >= 10) {
                        nums[index+1] = (nums[index] * 100)+ (index + 2);
                    } else {
                        nums[index+1] = (nums[index] * 10) + (index + 2);
                    }
                    if (index == 0 || symbol[index-1] == 0) {
                        sum = nums[index+1];
                    } else if (symbol[index-1] == '+') {
                        sum -= nums[index];
                        sum += nums[index+1];
                    }
                    else if (symbol[index-1] == '-') {
                        sum += nums[index];
                        sum -= nums[index+1];
                    }
                }
                dessert(n, index+1, sum, symbol, arr, nums);
                if (symbol[index] == '+') sum -= nums[index+1];
                else if (symbol[index] == '-') sum += nums[index+1];
                symbol[index] = 0; 
            }
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] arr = new char[n-1];
        char[] symbol = new char[n-1];
        int[] nums = new int[n];
        nums[0] = 1;
        dessert(n, 0, 1, symbol, arr, nums);
    }
}