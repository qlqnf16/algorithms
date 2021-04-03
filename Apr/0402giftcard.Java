package com.company;

import java.util.Arrays;

class Solution {
    static int rest;
    static int size;
    static Info[] infos;

    public int solution(int[] gift_cards, int[] wants) {
        int answer = 0;
        makeInfo(gift_cards, wants);
        Arrays.sort(infos);
        switchCards();
        answer = rest;
        return answer;
    }

    static int findTarget(int target) {
        int s = 0;
        int e = size - 1;
        int m;
        while (s <= e) {
            m = (s+e) / 2;
            if (infos[m].card == target) {
                if (infos[m].card == infos[m].want) s = m+1;
                else return m;
            } else if (infos[m].card < target) {
                s = m+1;
            } else {
                e = m-1;
            }
        }
        return -1;
    }

    static void switchCards(){
        int i = 0;
        while (i < size) {
            if (infos[i].card == infos[i].want) {
                i++;
                continue;
            }
            int switchIdx = findTarget(infos[i].want);
            System.out.println(switchIdx);
            if (switchIdx != -1) {
                int tmp = infos[i].want;
                infos[i].want = infos[switchIdx].want;
                infos[switchIdx].want = tmp;
                rest -= 1;
                if (infos[i].card == infos[i].want) {
                    rest -= 1;
                    i++;
                }
            } else {
                i++;
            }
        }
    }

    static void makeInfo(int[] cards, int[] wants) {
        size = cards.length;
        infos = new Info[size];

        rest = size;
        for (int i = 0; i < size; i++) {
            if (cards[i] == wants[i]) {
                rest--;
            }
            infos[i] = new Info(cards[i], wants[i]);
        }
    }
}

class Info implements Comparable<Info> {
    int card;
    int want;

    public Info(int card, int want) {
        this.card = card;
        this.want = want;
    }

    @Override
    public int compareTo(Info o) {
        return this.card - o.card;
    }
}

class  Main {
    public static void main(String[] args) {
        Solution sl = new Solution();
        int[] gift_card = {4, 5, 3, 2, 1};
        int[] wants = {2,4,4,5,1};
        int answer = sl.solution(gift_card, wants);
        System.out.println(answer);
    }
}
