package com.company;

class Solution {
    static int MAX_SEC = 99 * 3600 + 59 * 60 + 59 + 10;
    static int[][] timeline = new int[MAX_SEC][2];
    static long[] accPlaytime = new long[MAX_SEC];
    static int playTime, advTime;
    
    public int covertToSecond(String time) {
        String[] splitTime = time.split(":");
        int hr = Integer.parseInt(splitTime[0]);
        int mn = Integer.parseInt(splitTime[1]);
        int sc = Integer.parseInt(splitTime[2]);
        return hr * 3600 + mn * 60 + sc;
    }

    public String convertToString(int sec) {
        int hr = sec / 3600;
        int mn = (sec % 3600) / 60;
        int sc = (sec % 3600) % 60;
        return String.format("%02d:%02d:%02d", hr, mn, sc);
    }
    
    public void markPlaytime(String[] logs) {
        for (String log : logs) {
            String[] splitLog = log.split("-");
            int fromT = covertToSecond(splitLog[0]);
            int toT = covertToSecond(splitLog[1]);
            timeline[fromT][0] += 1;
            timeline[toT][1] += 1;
        } 
    }

    public void calcAccTime(String play_time, String adv_time) {
        playTime = covertToSecond(play_time);
        advTime = covertToSecond(adv_time);
        int addCnt = 0;
        for (int i = 1; i <= playTime; i++) {
            accPlaytime[i] = accPlaytime[i-1] + addCnt;

            if (timeline[i][0] > 0) addCnt += timeline[i][0];
            if (timeline[i][1] > 0) addCnt -= timeline[i][1];
        }
    }

    public int findBestTime(String[] logs) {
        long maxTime = 0;
        int bestTime = 0;

        for (String log : logs) {
            String[] splitLog = log.split("-");

            for (int i = 0; i < 2; i++) {
                int sec = covertToSecond(splitLog[i]);
                int from;
                long accTime;
                if (i == 0) {
                    from = sec;
                    int to = Math.min(sec + advTime, playTime);
                    accTime = accPlaytime[to] - accPlaytime[from];
                } else {
                    from = Math.max(sec - advTime, 0);
                    accTime = accPlaytime[sec] - accPlaytime[from];
                }
                if (accTime >= maxTime) {
                    bestTime = accTime == maxTime ? Math.min(from, bestTime) : from;
                    maxTime = accTime;
                }
            }
        }

        return bestTime;
    }
    
    public String solution(String play_time, String adv_time, String[] logs) {
        String answer = "";
        markPlaytime(logs);
        calcAccTime(play_time, adv_time);
        int bestTime = findBestTime(logs);
        answer = convertToString(bestTime);
        return answer;
    }
}

class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] logs = {"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"};
        System.out.println(sol.solution("99:59:59", "25:00:00", logs));
    }
}