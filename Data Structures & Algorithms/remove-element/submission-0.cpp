class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val),nums.end());
        int count = 0;
        for(int i=0; i< nums.size();i++){
            if(nums[i] != val){
                count++;
            }
        }
        return count;
    }
};