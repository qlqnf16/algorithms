package com.company;

import java.util.ArrayList;
import java.util.PriorityQueue;

class Solution {
    static ArrayList<Integer>[] graph;

    static void makeGraph(int n, int[][] train) {
        graph = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        for (int[] line: train) {
            int a = line[0];
            int b = line[1];
            graph[a].add(b);
            graph[b].add(a);
        }
    }

    static int[] dijkstra(int n, int[] passenger) {
        PriorityQueue<Station> pq = new PriorityQueue<>();
        boolean[] visit = new boolean[n+1];
        int[] maxPeople = new int[n+1];

        pq.add(new Station(1, passenger[0]));
        while (!pq.isEmpty()) {
            Station cur = pq.poll();
            if (visit[cur.node]) continue;
            visit[cur.node] = true;

            for (int next : graph[cur.node]) {
                if (!visit[next] && maxPeople[next] < cur.people + passenger[next-1]) {
                    maxPeople[next] = cur.people + passenger[next-1];
                    pq.add(new Station(next, maxPeople[next]));
                }
            }
        }

        return maxPeople;
    }

    public int[] solution(int n, int[] passenger, int[][] train) {
        int[] answer = {0, 0};
        makeGraph(n, train);
        int[] maxPeople = dijkstra(n, passenger);
        for (int i = 1; i <= n; i++) {
            if (answer[1] <= maxPeople[i]) {
                answer[0] = i;
                answer[1] = maxPeople[i];
            }
        }
        return answer;
    }

}

class Station implements Comparable<Station> {
    int node;
    int people;

    public Station(int node, int people) {
        this.node = node;
        this.people = people;
    }

    @Override
    public int compareTo(Station o) {
        return o.people - this.people;
    }
}

class  Main {
    public static void main(String[] args) {
        Solution sl = new Solution();
        int n = 6;
        int[] passenger = {1,1,1,1,1,1};
        int[][] train = {{1,2},{1,3},{1,4},{3,5},{3,6}};
        int[] answer = sl.solution(n, passenger, train);
        System.out.println(answer[0] + " " + answer[1]);
    }
}
