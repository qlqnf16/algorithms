package com.company;

import java.util.ArrayList;
import java.util.PriorityQueue;

class Node implements Comparable<Node> {
    int node;
    int cost;

    public Node(int node, int cost) {
        this.node = node;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node o) {
        return this.cost - o.cost;
    }
}

class Solution {
    static ArrayList<Node>[] graph;
    static boolean[] visit;

    static  void init(int n) {
        graph = new ArrayList[n+1];
        visit = new boolean[n+1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<Node>();
        }
    }

    static void makeGraph(int n, int[][] fares) {
        for (int[] fare: fares) {
            int a = fare[0];
            int b = fare[1];
            int c = fare[2];
            graph[a].add(new Node(b, c));
            graph[b].add(new Node(a, c));
        }
    }

    static int[] dijkstra(int n, int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int[] cheapestCost = new int[n+1];
        for (int i = 1; i <= n; i++) {
            visit[i] = false;
            cheapestCost[i] = Integer.MAX_VALUE;
        }
        cheapestCost[start] = 0;
        pq.add(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if (visit[cur.node]) continue;
            visit[cur.node] = true;

            for (Node next : graph[cur.node]) {
                if (cheapestCost[next.node] > cur.cost + next.cost) {
                    cheapestCost[next.node] = cur.cost + next.cost;
                    pq.add(new Node(next.node, cheapestCost[next.node]));
                }
            }
        }

        return cheapestCost;
    }

    public static int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = 0;
        init(n);
        makeGraph(n, fares);
        int[] fromA = dijkstra(n, a);
        int[] fromB = dijkstra(n, b);
        int[] fromS = dijkstra(n, s);

        int cheapestCost = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            int tempSum = fromA[i] + fromB[i] + fromS[i];
            if (tempSum < cheapestCost) cheapestCost = tempSum;
        }
        answer = cheapestCost;

        return answer;
    }
}

class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] fares = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};
        System.out.println(sol.solution(7,3, 4, 1, fares));
    }
}