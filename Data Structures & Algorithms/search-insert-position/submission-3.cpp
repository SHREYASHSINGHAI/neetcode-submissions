class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int end = nums.size()-1;
        int st = 0;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if (nums[mid]>target){
                end = mid -1;
            }
            else{
                st = mid + 1;
            }
        } 
        nums.push_back(target);
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size(); i++){
            if(target == nums[i]){
                return i;
            }
        }
        return 0;
    }
};