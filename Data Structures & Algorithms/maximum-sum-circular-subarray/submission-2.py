class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        currmax = 0
        currmin = 0
        globmax = nums[0]
        globmin = nums[0]
        total = 0
        for i in range(len(nums)):
            
            currmin = min(currmin + nums[i], nums[i])
            currmax = max(currmax + nums[i], nums[i])

            globmax = max(globmax, currmax)
            globmin = min(globmin, currmin)
            total += nums[i]
        if globmax>0:
            return max(globmax, total - globmin)
        else:
            return globmax