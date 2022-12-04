# https://leetcode.com/problems/minimum-average-difference/

from ast import List


class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        allSum =0
        for num in nums:
            allSum += num
            
        minAvgDif = 50001
        answer = 0
        sum = 0
        for i,num in enumerate(nums):
            sum += num
            dif = int(sum/(i+1)) 
            if i == len(nums)-1:
                dif2=0
            else : dif2 = int((allSum-sum)/(len(nums)-(i+1)))
            if minAvgDif >  abs(dif -dif2):
                answer = i
                minAvgDif = min(abs(dif -dif2),minAvgDif)
                
        return answer