class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> diff;
        vector<int>output;
        int n = arr.size();
        for(int i =0; i < n; i++){
            int dif = abs(x - arr[i]);
            diff.push_back(dif);
        }
        while(k>0){
            int min = INT_MAX;
            int max = min;
            for(int j =0; j <n; j++){
                if(diff[j] < min){
                    min = diff[j];
                }
            }
            bool found = false;
            int min_idx;
            
            for(int k = 0; k <n; k++){
                if(diff[k] == min){
                    min_idx = k;
                    output.push_back(arr[min_idx]);
                    found = true;
                    diff[k]=max;
                    break;
                }
            }
            if(found == true){
                k--;
                found = false;
            }
        }
        sort(output.begin(), output.end());
        return output;

    }
};