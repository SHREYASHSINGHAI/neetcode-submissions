class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_score(n+1,0);
        for(auto it:trust){
            int person1 = it[0];
            int person2 = it[1];
            trust_score[person1]--;
            trust_score[person2]++;
        }
        for(int i = 1 ; i <= n ; i++){
            if(trust_score[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};