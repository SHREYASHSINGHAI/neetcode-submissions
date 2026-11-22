class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        globmax, globmin=nums[0],nums[0]
        curmax,curmin = 0,0
        total = 0
        for n in nums:
            curmax = max(curmax+n, n)
            curmin = min(curmin+n,n)
            

            globmax = max(globmax,curmax)
            globmin = min(globmin,curmin)
            total += n
        
        if globmax > 0:
            return max(globmax, total - globmin)
        else:
            return globmax
