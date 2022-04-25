class Solution {
    vector<vector<int> >adj;
    bitset<100001>visited;
    bitset<100001>on_stack;
    bool flag;
    void dfs(int n){
        visited[n]=true;
        on_stack[n]=true;
        for(int i=0 ; i<adj[n].size() ; i++){
            if(!visited[adj[n][i]])dfs(adj[n][i]);
            else{
                if(on_stack[adj[n][i]])flag=false;
            }
        }
        on_stack[n]=false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)return true;
        flag = true ;
        for(int i=0 ; i<numCourses ; i++){
            vector<int>empty;
            adj.push_back(empty);
        }
        for(int i=0 ; i<prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0 ; i<numCourses ; i++){
            if(!visited[i])dfs(i);
        }
        return flag;
    }
};