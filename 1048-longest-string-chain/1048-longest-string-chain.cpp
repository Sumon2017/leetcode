class Solution {
    class cInt{
        public:
        int val;
        cInt(){
            val = -1 ;
        }
    };
    string temp="";
    vector<vector<string> >l_list;
    vector<map<string,cInt> >dp;
    int sol(int index,string cur){
        if(dp[index][cur].val != -1)return dp[index][cur].val;
        int ans = 0;
        for(auto item:l_list[index+1]){
            for(int skip=0;skip<item.size();skip++){
                temp="";
                for(int ch=0;ch<item.size();ch++){
                    if(ch == skip)continue;
                    temp.push_back(item[ch]);
                }
                if(temp == cur){
                    ans=max(ans,1+sol(index+1,item));
                }
            }
        }
        return dp[index][cur].val = ans;
    }
public:
    int longestStrChain(vector<string>& words) {
        for(int i=1;i<=18;i++)l_list.push_back(vector<string>());
        for(int i=1;i<=18;i++)dp.push_back(map<string,cInt>());
        for(auto item:words)l_list[item.size()].push_back(item);
        vector<int>second_dp(18,-1);
        for(int i=1;i<=16;i++){
            for(auto item:l_list[i]){
                second_dp[i] = max(second_dp[i],sol(i,item));
            }
        }
        return *max_element(second_dp.begin(),second_dp.end())+1;
    }
};