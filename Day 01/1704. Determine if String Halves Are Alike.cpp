// https://leetcode.com/problems/determine-if-string-halves-are-alike/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char v){
        if(v=='a' or v=='e' or v=='o' or v=='i' or v=='u' or v=='A' or v=='E' or v=='I' or v=='O' or v=='U'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int count1=0;
        int count2=0;
        int mid = s.size()/2;
        for(int a=0; a<mid;a++){
            if(isVowel(s[a]))
                count1++;
        }
        for(int b=mid;b<s.size();b++){
            if(isVowel(s[b]))
                count2++;
        }
        
        if(count1 == count2)
            return true;
        return false;
    }
};