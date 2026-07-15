class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<bool>visited(strs.size(),false);
        for(int i = 0 ; i < strs.size(); i++){
            if(visited[i]){
                continue;
            }
            vector<string>group;
            string s1=strs[i];
            sort(s1.begin(), s1.end());
            group.push_back(strs[i]);
            visited[i]=true;
            for (int j = i+1; j<strs.size();j++){
                string s2=strs[j];
                sort(s2.begin(),s2.end());
                if(s1==s2){
                    group.push_back(strs[j]);
                    visited[j]=true;
                }
            }
            res.push_back(group);
        }
        return res;
    }
};
