class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if(len(nums)==0):
            return
        insert_index=1

        for i in range(1, len(nums),1):
            if(nums[i] != nums[i-1]):
                nums[insert_index]=nums[i]
                insert_index += 1
            
        return insert_index