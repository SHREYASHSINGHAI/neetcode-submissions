class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        
        for(const string& op : operations){
            if(op=="+"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                int res = top2 + top1;
                st.push(top1);
                st.push(res);

            }
            else if(op == "D"){
                st.push(2*st.top());
            }
            else if(op == "C"){
                st.pop();
            }
            else{
                st.push(stoi(op));
            }
        }
        int totalsum =0;
        while(!st.empty()){
            totalsum += st.top();
            st.pop();
        }
        return totalsum;
    }
};