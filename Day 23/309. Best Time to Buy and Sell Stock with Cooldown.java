// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n<=1)
            return 0;
        int[] buy = new int[n];
        int[] sell = new int[n];
        int[] cooldown = new int[n];
        
        //no choice on day 0
        buy[0] = -prices[0];
        for(int i=1;i<n;i++)
        {
            buy[i] = Math.max(buy[i-1], cooldown[i-1]-prices[i]);
            sell[i] = Math.max(sell[i-1], prices[i]+buy[i-1]);
            cooldown[i] = Math.max(cooldown[i-1], sell[i-1]);
        }
        return Math.max(sell[n-1],cooldown[n-1]);
    }
}