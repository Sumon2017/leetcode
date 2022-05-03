class Solution {
    int r,c;
    bool pacific,atlantic;
    int visited[201][201];
    bool off_flag;
    int in_answer[201][201];
    void dfs(int i,int j,vector<vector<int> >& grid){
        if(off_flag==true)return;
        if(in_answer[i][j]==1){
            pacific=true;
            atlantic=true;
            off_flag=true;
            return;
        }
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
        memset(in_answer,0,sizeof(in_answer));
        for(int i=0 ; i<r ; i++){
            for(int j=0 ; j<c ; j++){
                pacific=false;
                atlantic=false;
                memset(visited,0,sizeof(visited));
                off_flag=false;
                dfs(i,j,heights);
                if(pacific==true and atlantic==true){
                    result.push_back(vector<int>{i,j});
                    in_answer[i][j]=1;
                }
            }
        }
        return result;
    }
};