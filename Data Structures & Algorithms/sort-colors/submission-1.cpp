class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i< nums.size()-1;i++){
            int smallidx = i;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j]<nums[smallidx]){
                    smallidx = j;
                }
            }
            swap(nums[i],nums[smallidx]);
        }
    }
};