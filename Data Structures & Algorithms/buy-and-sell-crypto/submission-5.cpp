class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int,int>> arr;
        for(int i = 0 ; i < nums.size(); i++){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        for(int i = 0 ; i < nums.size()-1; i++){
            if(arr[i].first == arr[i+1].first){
                if(abs(arr[i].second-arr[i+1].second)<=k){
                    return true;
                }
            }
        }
        return false;

    }
};