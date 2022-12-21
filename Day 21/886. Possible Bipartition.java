import java.util.*;

// https://leetcode.com/problems/possible-bipartition/description/

class Solution {
    private Map<Integer, List<Integer>> graph;
    private int[] visited;
    public boolean possibleBipartition(int N, int[][] dislikes) {
        if(N == 0 || dislikes.length == 0) return true;
        graph = new HashMap<>();
        for(int[] dislike : dislikes){
            List<Integer> temp = graph.containsKey(dislike[0]) ? graph.get(dislike[0]): new ArrayList<>();
            temp.add(dislike[1]);
            graph.put(dislike[0], temp);
            temp = graph.containsKey(dislike[1]) ? graph.get(dislike[1]): new ArrayList<>();
            temp.add(dislike[0]);
            graph.put(dislike[1], temp);
        }
        visited = new int[N + 1];
        for(int i = 0; i < N; i++){
            if(visited[i] == 0){
                if(!dfs(i, 1)) return false;
            }
        }
        return true;
    }
    private boolean dfs(int node, int color){
        if(visited[node] != 0 && visited[node] != color) return false;
        if(visited[node] == color) return true;
        visited[node] = color;
        List<Integer> neighbours = graph.get(node);
        if(neighbours == null) return true;
        for(Integer neighbour : neighbours){
            if(!dfs(neighbour, -color)) return false;
        }
        return true;
    }
}