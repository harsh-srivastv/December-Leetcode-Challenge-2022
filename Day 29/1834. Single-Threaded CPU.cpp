// https://leetcode.com/problems/single-threaded-cpu/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef unsigned long long ll;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int i = 0;
        int N = tasks.size();
        for (auto& t : tasks) {
            t.push_back(i++);
        }
        sort(tasks.begin(), tasks.end(), [](const auto& t1, const auto& t2) {
            if (t1[0] != t2[0]) return t1[0] < t2[0];
            else if (t1[1] != t2[1]) return t1[1] < t2[1];
            else return t1[2] < t2[2];
        });
        auto cmp = [](const auto& t1, const auto& t2) {
            if (t1[1] != t2[1]) return t1[1] > t2[1];
            else return t1[2] > t2[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        vector<int> ans;
        pq.push(tasks[0]);
        i = 1;
        ll curTime = tasks[0][0];
        while (pq.size() or i < N) {
            if (pq.size() == 0) {
                curTime = tasks[i][0];
                pq.push(tasks[i++]);
            }
            auto t = pq.top(); pq.pop();
            ans.push_back(t[2]);
            curTime += t[1];
            while (i < N and tasks[i][0] <= curTime) {
                pq.push(tasks[i++]);
            }
        }
        return ans;
    }
};