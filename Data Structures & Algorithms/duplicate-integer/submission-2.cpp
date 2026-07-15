class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool flag=false;
        sort(begin(nums), end(nums));
        for(int i= 0 ; i < (int) nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                flag=true;
            }
        }
        return flag;
    }
};