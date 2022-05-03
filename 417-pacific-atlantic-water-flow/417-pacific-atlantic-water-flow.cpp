class Solution {
    int r,c;
    int pacific[201][201];
    int atlantic[201][201];
    int visited[201][201];
    void dfs(int i,int j,vector<vector<int> >& heights,int ocean){
        visited[i][j]=1;
        if(ocean == 1)pacific[i][j]=1;
        else atlantic[i][j]=1;
        if(i!=0 and visited[i-1][j]==0 and heights[i][j]<=heights[i-1][j])dfs(i-1,j,heights,ocean);
        if(i!=r-1 and visited[i+1][j]==0 and heights[i][j]<=heights[i+1][j])dfs(i+1,j,heights,ocean);
        if(j!=0 and visited[i][j-1]==0 and heights[i][j]<=heights[i][j-1])dfs(i,j-1,heights,ocean);
        if(j!=c-1 and visited[i][j+1]==0 and heights[i][j]<=heights[i][j+1])dfs(i,j+1,heights,ocean);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        r = heights.size();
        c = heights[0].size();
        memset(pacific,0,sizeof(pacific));
        memset(atlantic,0,sizeof(atlantic));
        for(int row=0;row<r;row++){
            memset(visited,0,sizeof(visited));
            dfs(row,0,heights,1);
        }
        for(int col=0;col<c;col++){
            memset(visited,0,sizeof(visited));
            dfs(0,col,heights,1);
        }
        for(int row=0;row<r;row++){
            memset(visited,0,sizeof(visited));
            dfs(row,c-1,heights,2);
        }
        for(int col=0;col<c;col++){
            memset(visited,0,sizeof(visited));
            dfs(r-1,col,heights,2);
        }
        vector<vector<int > >answer;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pacific[i][j]==1 and atlantic[i][j])answer.push_back(vector<int>{i,j});
            }
        }
        return answer;
    }
};