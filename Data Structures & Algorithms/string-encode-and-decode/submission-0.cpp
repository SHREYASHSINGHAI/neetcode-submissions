class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(int i = 0 ; i < strs.size(); i++){
            int len=strs[i].size();
            string length = to_string(len);
            res += length+'#'+strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i<s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            string numStr = s.substr(i,j-i);
            int len = stoi(numStr);
            string current_word="";
            current_word = s.substr(j+1,len);
            res.push_back(current_word);
            i=j+1+len;
        }
        return res;
    }
};
