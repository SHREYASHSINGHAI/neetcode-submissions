class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum = float('-inf')
        summ = 0
        if len(nums)<2:
            return nums[0]
        for num in nums:
            summ += num
            if summ > maxsum :
                maxsum = summ
            if summ <0:
                summ = 0
        return maxsum