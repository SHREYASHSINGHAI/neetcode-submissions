class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>output;
        sort(nums.begin(), nums.end());
        int count = 1;

        if(nums.size()<3){
            for(int j = 0; j < nums.size(); j++){
                if(count > (n/3)){
                    output.push_back(nums[j]);
                }
            }
        }

        for(int i = 1; i < n; i++){
            if(nums[i]==nums[i-1]){
                count++;
            
            if(count>(n/3) && find(output.begin(),output.end(),nums[i])==output.end()){
                output.push_back(nums[i]);
            }
            }
            else if(nums[i]!=nums[i-1]){
                count = 1;
            }            
        }
        return output;
    }
};