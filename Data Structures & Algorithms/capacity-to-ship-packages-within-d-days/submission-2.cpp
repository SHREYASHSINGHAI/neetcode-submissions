class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int provided_days = days;
        int min_ship_cap = *max_element(weights.begin(), weights.end());
        int i = 0;
        int result = min_ship_cap;
        int n = weights.size();

        while(days>0){
            int current_cap = 0;
            while(i<n && current_cap + weights[i] <= min_ship_cap){
                current_cap += weights[i];
                i++;
            }
            days--;

            if(days == 0 && i != n){
                days = provided_days;
                i = 0;
                min_ship_cap += 1;
            }
        }
        result = min_ship_cap;
        return result ;
    }
};