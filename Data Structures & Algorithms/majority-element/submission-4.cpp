class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int freq = 0;
        for(int i = 0; i<nums.size();i++){
            if(freq == 0){
                ans = nums[i];
            }
            if(nums[i]==ans){
                freq++;
            }
            else{
                freq--;
            }
        }
        return ans;
    }
};