class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        minlen = float('inf')
        left = 0
        summ = 0
        for right in range(len(nums)):
            summ += nums[right]
            while summ>=target:
                minlen = min(minlen, right - left + 1)
                summ -= nums[left] 
                left +=1
        if not minlen == float('inf'):
            return minlen
        else:
            return 0