class Solution:
    def jump(self, nums: List[int]) -> int:
        
        farthest = 0
        currend = 0
        count = 0
        for i in range(len(nums)-1):
            farthest = max(farthest,i+nums[i])
            if i == currend:
                count += 1
                currend = farthest
        return count