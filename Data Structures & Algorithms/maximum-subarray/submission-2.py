class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum = float('-inf')
        currsum = 0
        if len(nums) < 2:
            return nums[0]
        for i in range(len(nums)):
            currsum += nums[i]
            
            if currsum > maxsum:
                maxsum = currsum

            if currsum < 0:
                currsum = 0
        return maxsum