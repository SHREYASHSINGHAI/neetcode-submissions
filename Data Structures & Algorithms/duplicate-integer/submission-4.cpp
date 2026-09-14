class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<1){
            return 0;
        }
        bool flag=false;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]==nums[i-1]){
                flag = true;
            }
        }
        return flag;
    }
};