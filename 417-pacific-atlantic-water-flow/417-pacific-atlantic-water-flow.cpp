class Solution {
    int r,c;
    bool pacific,atlantic;
    int visited[201][201];
    void dfs(int i,int j,vector<vector<int> >& grid){
        visited[i][j]=1;
        if(i==0 or j==0)pacific=true;
        if(i==r-1 or j==c-1)atlantic=true;
        if(i!=0 and visited[i-1][j]==0 and grid[i][j]>=grid[i-1][j])dfs(i-1,j,grid);
        if(i!=r-1 and visited[i+1][j]==0 and grid[i][j]>=grid[i+1][j])dfs(i+1,j,grid);
        if(j!=0 and visited[i][j-1]==0 and grid[i][j]>=grid[i][j-1])dfs(i,j-1,grid);
        if(j!=c-1 and visited[i][j+1]==0 and grid[i][j]>=grid[i][j+1])dfs(i,j+1,grid);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int> >result;
        r = heights.size();
        c = heights[0].size();
        for(int i=0 ; i<r ; i++){
            for(int j=0 ; j<c ; j++){
                pacific=false;
                atlantic=false;
                memset(visited,0,sizeof(visited));
                dfs(i,j,heights);
                if(pacific==true and atlantic==true)result.push_back(vector<int>{i,j});
            }
        }
        return result;
    }
};