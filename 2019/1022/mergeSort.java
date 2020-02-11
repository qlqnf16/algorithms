import java.util.ArrayList;

public class Main {
  public static void main(String[] args) {
    List<Integer> targetList = new ArrayList<Integer>(4);
    sort(targetList);
  }

  // /**
  // * merge sort를 시행합니다.
  // *
  // * @param targetList sort할 target 입니다.
  // * @return
  // */
  public static List<Integer> sort(List<Integer> targetList) {
    // 사이즈가 1보다 크다면
    if (targetList.size() > 1) {
      // 왼쪽 오른쪽을 merge 합니다.
      return merge(
          // 왼쪽 / 오른쪽으로 배열을 나누고 다시 sort하도록 합니다.
          sort(targetList.subList(0, targetList.size() / 2)),
          sort(targetList.subList(targetList.size() / 2, targetList.size())));
    } else {
      // 사이즈가 1 이하라면 재귀가 종료됩니다.
      return targetList;
    }
  }

  // /**
  // * 병합합니다.
  // *
  // * @param left 왼쪽 배열
  // * @param right 오른쪽 배열
  // * @return
  // */
  public static List<Integer> merge(List<Integer> left, List<Integer> right) {
    // 결과가 될 임시 배열입니다.
    List<Integer> result = new ArrayList<>();
    int rightIdx = 0;

    // 왼쪽 배열을 순환하면서
    for (Integer l : left) {

      // right를 끝까지 돌았는지 / right배열의 값이 l보다 작은지 확인하고,
      while (right.size() > rightIdx && l > right.get(rightIdx)) {
        // 작은 값을 결과에 넣습니다.
        result.add(right.get(rightIdx));
        rightIdx++;
      }
      // left가 작다면 left element를 넣습니다.
      result.add(l);
    }
    // 오른쪽 배열의 남은 숫자를 결과에 넣습니다.
    for (int i = rightIdx; i < right.size(); i++) {
      result.add(right.get(i));
    }
    return result;
  }
}