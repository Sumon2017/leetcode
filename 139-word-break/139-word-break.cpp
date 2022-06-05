class Solution {
    class myInt{
        public:
        int val;
        myInt(){
            val =-1;
        }
    };
    unordered_map<string,myInt>mymap;
    string input;
    vector<unordered_map<string,myInt> >look_up;
    bool func(int idx=0,string current=""){
        if(look_up[idx][current].val != -1)return look_up[idx][current].val;
        if(idx == input.size()){
            return look_up[idx][current].val = current.size() == 0 ;
        }
        
        current.push_back(input[idx]);
        
        if(mymap[current].val==1){
            return look_up[idx][current].val = (func(idx+1,"") or func(idx+1,current));
        }
        
        return look_up[idx][current].val = func(idx+1,current);
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<=301;i++)look_up.push_back(unordered_map<string,myInt>());
        input = s;
        for(auto x:wordDict){
            mymap[x].val=1;
        }
        return func();
    }
};