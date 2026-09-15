class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0;
        int curr;
        for(int i = 0; i < nums.size(); i++){
            if(freq==0){
                curr=nums[i];
            }
            if(nums[i]==curr){
                freq++;
            }
            else if(nums[i] != curr){
                freq--;
            }
        }
        return curr;
    }
};