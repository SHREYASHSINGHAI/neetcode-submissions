class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        map<int, int> numMap;
        for(int i = 0; i < nums.size(); i ++){
            numMap[nums[i]]++;
        }
        int ans;
        for(auto it : numMap){
            if(it.second >n){
                ans=it.first;
            }
        }
        return ans;
    }
};