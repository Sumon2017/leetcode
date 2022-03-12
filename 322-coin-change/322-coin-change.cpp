class Solution {
public:
    vector<int>coins_g;
    int dp[10000+1];
    int solution(int amount){
        if(dp[amount] != -1){
            return dp[amount];
        }
        if(amount == 0){
            return 0 ;
        }
        int cur_min = 100000;
        for(int i = 0 ; i < coins_g.size() ; i++){
            if(amount-coins_g[i] >= 0){
                cur_min = min(cur_min , 1 + solution(amount-coins_g[i]));
            }
        }
        return dp[amount] = cur_min;
    }
    int coinChange(vector<int>& coins, int amount) {
        int answer;
        coins_g = coins;
        memset(dp,-1,sizeof(dp));
        answer = solution(amount);
        if(answer == 100000)answer = -1;
        return answer;
    }
};