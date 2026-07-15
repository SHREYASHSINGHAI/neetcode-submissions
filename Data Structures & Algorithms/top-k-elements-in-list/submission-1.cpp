class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map <int, int> freq;
        vector<int> ans;

        for(int i : nums){
            freq[i]++;
        }
        while(k--){
            int max_freq=0;
            int element;
            for(auto it : freq){
                if(it.second>max_freq){
                    max_freq = it.second;
                    element = it.first;
                }
            }
            ans.push_back(element);
            freq.erase(element);
        }
        return ans;
    }
};
