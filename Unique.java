package algorithm;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Unique {
	static String words[];
	static boolean isUnique = true;
	static ArrayList<Integer>[] indexes;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.nextLine();
		indexes = new ArrayList[N];
		
		for (int i = 0; i < N; i++) {
			indexes[i] = new ArrayList<Integer>();
		}
		
		String inputString = sc.nextLine();
		words = inputString.split(" ");
		
		HashMap<String, Integer> wordHashMap = new HashMap<String, Integer>();
		HashMap<Integer, String> idxHashMap = new HashMap<Integer, String>();
		
		int idx = 0;
		for (int i = 0; i < words.length; i++) {
			if (wordHashMap.get(words[i]) == null) {
				idxHashMap.put(idx, words[i]);
				wordHashMap.put(words[i], idx);
				indexes[idx++].add(i+1);
			} else {
				isUnique = false;
				indexes[wordHashMap.get(words[i])].add(i+1);
			}
		}
		
		if (isUnique) System.out.println("unique");
		else {
			for (int i = 0; i < idx; i++) {
				if (indexes[i].size() > 1) {
					System.out.print(idxHashMap.get(i) + " ");
					for (int j = 0; j < indexes[i].size(); j++) {
						System.out.print(indexes[i].get(j) + " ");
					}
					System.out.println();
				}
			}
		}
		sc.close();
	}

}
