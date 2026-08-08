class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxlen=0;
        int count = 0;
        if(nums.size()<=1){
            return nums.size();
        }
        if(nums.size()>1){
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]-nums[i-1]==1){
                count++;
            }
            else if(nums[i]-nums[i-1] != 1){
                count = 0;
            }
            maxlen=max(count,maxlen);
        }
        }
        if(maxlen != 0){        
        return maxlen+1;}
    }
};
