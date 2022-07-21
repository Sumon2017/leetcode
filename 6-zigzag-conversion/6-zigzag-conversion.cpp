class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        char grid[1000][1000];
        memset(grid,0,sizeof(grid));
        int row=0,col=0;
        for(auto c : s){
            grid[row][col] = c ;
            if(row == 0){
                row++;
            }
            else if(row == numRows -1){
                row--;
                col++;
            }
            else if(grid[row-1][col] != NULL){
                row++;
            }
            else{
                row--;
                col++;
            }
        }
        string ans = "";
        for(int row = 0 ; row < numRows ; row++){
            for(int col = 0 ; col < 1000 ; col++){
                if(grid[row][col] == NULL)continue;
                ans.push_back(grid[row][col]);
            }
        }
        return ans;
    }
};