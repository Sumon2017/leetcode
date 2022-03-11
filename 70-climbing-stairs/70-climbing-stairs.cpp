class Solution {
    int dp[46];
    int goal;
    int solution(int steps = 0){
        if(steps > goal ){
            return 0;
        }
        if(dp[steps]!=-1){
            return dp[steps];
        }
        if(steps == goal){
            return 1;
        }
        return dp[steps] = solution(steps + 1) + solution(steps + 2);
    }
public:
    int climbStairs(int n) {
        for(int i=0;i<46;i++)dp[i]=-1;
        goal = n ;
        return solution();
    }
};