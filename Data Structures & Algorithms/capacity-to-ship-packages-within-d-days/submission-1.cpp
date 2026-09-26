class Solution {
public:

    int shipWithinDays(vector<int>& weights, int days) {
        int provided_days = days;
        int n = weights.size();
        int min_ship_cap = *std::max_element(weights.begin(), weights.end());
    
    int result = min_ship_cap;
    int i = 0;
    while(days>0){
        int current_shipment_weight = 0;
        while(i<n && (current_shipment_weight + weights[i])<= min_ship_cap ){
        current_shipment_weight += weights[i];
        i++;
        }
        days--;
        if(days == 0 && i != n){
            min_ship_cap += 1;
            days = provided_days;
            i = 0;
        }
    }
    result = min_ship_cap;
    return result;
    }
};
