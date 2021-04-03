package com.company;

class Solution {
    static int[][] needs;
    static int size;
    static int maxPrdoduct;

    public int solution(int[][] n, int r) {
        int answer = 0;
        needs = n;
        size = needs[0].length;
        int[] combi = new int[size];
        makeCombi(0, r, 0, combi);
        answer = maxPrdoduct;
        return answer;
    }

    static int cntProduct(int[] combi) {
        int cnt = 0;
        for (int[] need: needs) {
            boolean canMake = true;
            for (int i = 0; i < size; i++) {
                if (need[i] == 1 && combi[i] == 0) {
                    canMake = false;
                    break;
                }
            }
            if (canMake) cnt++;
        }
        return cnt;
    }

    static void makeCombi(int idx, int r, int selected, int[] combi) {
        if (selected >= r) {
            int cnt = cntProduct(combi);
            if (cnt > maxPrdoduct) maxPrdoduct = cnt;
            return;
        }
        if (idx >= size) return;

        // 선택
        combi[idx] = 1;
        makeCombi(idx+1, r, selected+1, combi);
        // 선택 안함
        combi[idx] = 0;
        makeCombi(idx+1, r, selected, combi);
    }
}

class  Main {
    public static void main(String[] args) {
        Solution sl = new Solution();
        int[][] needs = { { 1, 0, 0 }, {1, 1, 0}, {1, 1, 0}, {1, 0, 1}, {1, 1, 0}, {0, 1, 1} };
        int r = 2;
        int answer = sl.solution(needs, r);
        System.out.println(answer);
    }
}
