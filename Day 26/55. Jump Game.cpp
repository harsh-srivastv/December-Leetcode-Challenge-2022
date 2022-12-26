// https://leetcode.com/problems/jump-game/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size()-1;
      int lastpos = n;
      for(int i=n-1;i>=0;i--)
      {
          if(i+nums[i]>=lastpos)
          {
              lastpos = i;
          }
      }
      return lastpos == 0;
    }
};