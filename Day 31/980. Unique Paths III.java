// https://leetcode.com/problems/unique-paths-iii/description/

class Solution {
    private int height, width;
    private short[][][] dp = null;
    private static int[][] dir = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    public int uniquePathsIII(int[][] grid) {
        height = grid.length;
        width = grid[0].length;
        int[] start = null;
        dp = new short[height][width][1 << (width * height)];        
        int state = 0;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(grid[i][j] == 0 || grid[i][j] == 2)
                    state |= key(i, j);
                else if(grid[i][j] == 1)
                    start = new int[]{i, j};
            }
        }
        return dfs(grid, start[0], start[1], state);
    }
    private int key(int i, int j){
        return 1 <<(i * width + j);
    }
    private int dfs(int[][] grid, int i, int j, int state){
        if(dp[i][j][state] > 0) return dp[i][j][state];
        if(grid[i][j] == 2 && state == 0) return 1;        
        int tempRow = 0, tempCol = 0;
        for(int d = 0; d < 4; d++){
            tempRow = i + dir[d][0];
            tempCol = j + dir[d][1];
            if(tempRow >= 0 && tempRow < height && tempCol >= 0 && tempCol < width && grid[tempRow][tempCol] != -1){
                if((state & key(tempRow, tempCol)) == 0) continue;
                dp[i][j][state] += dfs(grid, tempRow, tempCol, (state ^ key(tempRow, tempCol)));
            }
        }
        return dp[i][j][state];
    }
}