class Solution {
public:
    bool isPalindrome(string s) {
        // lowercasing first alphabet
        for(int i = 0 ; i < s.size(); i++){
            s[i]=tolower(s[i]);
            if(!isalnum(s[i])){
                s.erase(i,1);
                i--;
            }
            
        }
        
        string reversed;
        for(int i = s.size()-1; i >= 0; i--){
            reversed += s[i];
        }
        if(reversed==s){
            return true;
        }
        else{
            return false;
        }
    }
};
