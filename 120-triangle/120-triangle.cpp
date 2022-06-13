class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1)return triangle[0][0];
        vector<int>dp_down(triangle.size(),1000000000+1);
        vector<int>dp_right(triangle.size(),1000000000+1);
        vector<int>dp_main(triangle.size(),1000000000+1);
        dp_main[0] = triangle[0][0] ;
        for(int r = 0 ; r < triangle.size()-1 ; r++){
            for(int c = 0 ; c < triangle[r].size() ; c++){
                dp_down[c] = dp_main[c] + triangle[r+1][c];
                dp_right[c+1] = dp_main[c] + triangle[r+1][c+1];
            }
            for(int c = 0; c <triangle[r].size()+1 ; c++)dp_main[c] = min(dp_down[c],dp_right[c]);
        }
        int ans = 1000000000+1;
        for(int i = 0 ; i < triangle.size() ; i++)ans = min(ans,dp_main[i]);
        return ans;
    }
    /*/
           
     2
     3   4 
    /*/
};