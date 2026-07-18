class Solution {
public:
     vector<char>reverseString(vector<char>& s) {
        vector<char> res;
        if(s.empty()){
            return res;
        }
        for(int i = s.size()-1; i>=0; i--){
            res.push_back(s[i]);
        }
        s=res;
    return s;

    }
};