class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1)return triangle[0][0];
        vector<int>dp = triangle[triangle.size()-1];
        for(int r = triangle.size()-1 ; r>=1 ; r--){
            for(int c = 0 ; c < triangle[r].size()-1 ; c++){
                dp[c] = triangle[r-1][c] + min(dp[c],dp[c+1]);
            }
        }
        return dp[0];
    }
    /*
    2
    3 4
    6 5 7
    4 1 8 3
    */
};