class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() < 2)return 0;
        
        int min_var = 100000 ;
        vector<int>min_arr;
        
        for( int i = 0 ; i < prices.size() ; i++ ){
            min_var = min(min_var , prices[i]);
            min_arr.push_back(min_var);
        }
        
        int max_var = -1 ;
        
        for( int i = 1 ; i < prices.size() ; i++ ){
            max_var = max(max_var , prices[i] - min_arr[i-1] );
        }
        
        if(max_var < 0)return 0;
        else return max_var;
    }
};