class Solution {
    int r,c;
    int visited[2][201][201];
    void dfs(int i,int j,vector<vector<int> >& heights,int ocean){
        if(ocean == 0)visited[0][i][j]=1;
        else visited[1][i][j]=1;
        if(i!=0 and visited[ocean][i-1][j]==0 and heights[i][j]<=heights[i-1][j])dfs(i-1,j,heights,ocean);
        if(i!=r-1 and visited[ocean][i+1][j]==0 and heights[i][j]<=heights[i+1][j])dfs(i+1,j,heights,ocean);
        if(j!=0 and visited[ocean][i][j-1]==0 and heights[i][j]<=heights[i][j-1])dfs(i,j-1,heights,ocean);
        if(j!=c-1 and visited[ocean][i][j+1]==0 and heights[i][j]<=heights[i][j+1])dfs(i,j+1,heights,ocean);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        r = heights.size();
        c = heights[0].size();
        memset(visited,0,sizeof(visited));
        for(int row=0;row<r;row++){
            dfs(row,0,heights,0);
        }
        for(int col=0;col<c;col++){
            dfs(0,col,heights,0);
        }
        for(int row=0;row<r;row++){
            dfs(row,c-1,heights,1);
        }
        for(int col=0;col<c;col++){
            dfs(r-1,col,heights,1);
        }
        vector<vector<int > >answer;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(visited[0][i][j]==1 and visited[1][i][j]==1)answer.push_back(vector<int>{i,j});
            }
        }
        return answer;
    }
};