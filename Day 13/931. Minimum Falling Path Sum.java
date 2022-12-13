// https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
    public int minFallingPathSum(int[][] A) {
        int len = A.length;
        if(len == 0) return 0;
        int[][] dp = new int[len][len];
        for(int i = 0; i < len; i++){
            dp[0][i] = A[0][i];
        }
        for(int i = 1; i < len; i++){
            for(int j = 0; j < len; j++){
                dp[i][j] = Math.min(Math.min(j > 0 ? dp[i - 1][j - 1]: Integer.MAX_VALUE, j + 1 < len ? dp[i - 1][j + 1]: Integer.MAX_VALUE), dp[i - 1][j]) + A[i][j];
            }
        }
        int res = Integer.MAX_VALUE;
        for(int i = 0; i < len; i++)
            res = Math.min(res, dp[len - 1][i]);
        return res;
    }
}