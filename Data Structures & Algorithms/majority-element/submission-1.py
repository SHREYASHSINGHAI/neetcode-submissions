class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans=0
        pair=dict()
    
        for i in range(len(nums)):
            if nums[i] not in pair:
                pair[nums[i]] =1
            else:
                pair[nums[i]] += 1
        n = int(len(nums)/2)
        for i in pair:
            if(pair[i] >n):
                ans=i
        return ans