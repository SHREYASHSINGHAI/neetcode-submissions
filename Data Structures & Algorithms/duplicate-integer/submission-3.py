class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        ans = False
        nums.sort()
        n=len(nums)
        for i in range(1,n):
            if(nums[i]==nums[i-1]):
                ans = True
        return ans
