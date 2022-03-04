class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)return 0;
        int l = 0 , r = 1 ;
        int max_profit = 0 ;
        while(r<prices.size()){
            max_profit = max(max_profit,prices[r]-prices[l]);
            if(prices[r] < prices[l])l=r;
            r=r+1;
        }
        return max_profit;
    }
};
