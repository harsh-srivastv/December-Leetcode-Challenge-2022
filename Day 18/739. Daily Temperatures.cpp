// https://leetcode.com/problems/daily-temperatures/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n);

        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() and temp[st.top()] <= temp[i]) st.pop();
            if(st.empty()){
                st.push(i);
                res[i] = 0;
            } else {
                res[i] = (st.top()-i);
                st.push(i);
            }
        }
        
        return res;
    }
};