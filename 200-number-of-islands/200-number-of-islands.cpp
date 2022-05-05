class Solution {
    int r,c;
    bool visited[301][301];
    void dfs(int i,int j,vector<vector<char> >&grid){
        visited[i][j]=true;
        if(i!=0 and grid[i-1][j]=='1' and visited[i-1][j]==false)dfs(i-1,j,grid);
        if(i!=r-1 and grid[i+1][j]=='1' and visited[i+1][j]==false)dfs(i+1,j,grid);
        if(j!=0 and grid[i][j-1]=='1' and visited[i][j-1]==false)dfs(i,j-1,grid);
        if(j!=c-1 and grid[i][j+1]=='1' and visited[i][j+1]==false)dfs(i,j+1,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int answer = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' and visited[i][j]==false){
                    answer++;
                    dfs(i,j,grid);
                }
            }
        }
        return answer;
    }
};