class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy;
        int sell;
        for(int i = 0; i < prices.size()-1; i++){
            buy=prices[i];
            sell=prices[i+1];
            if(sell>buy){
                profit += sell-buy;
            }
        }
        return profit;
    }
};