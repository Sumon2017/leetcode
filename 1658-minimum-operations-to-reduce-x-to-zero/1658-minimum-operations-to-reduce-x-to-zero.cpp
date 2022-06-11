class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(nums.size() == 1){
            return (nums[0] == x) ? 1 : -1 ;
        }
        int current = 0 ;
        vector<int>p_sum(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            current = current + nums[i];
            p_sum[i] = current;
        }
        unordered_map<int,int>ourmap;
        for(int i=0;i<p_sum.size();i++)ourmap[p_sum[i]]=i;
        ourmap[0] = p_sum.size();
        current = 0 ;
        int ans = 100000+1;
        int maptemp,temp,a,b;
        int ss = nums.size();
        for(int i=-1;i<ss;i++){
            if(i != -1)current = current + nums[i];
            if(current > x)break;
            maptemp = ourmap[x-current];
            if(maptemp != 0){
                a = i;
                b = maptemp;
                if(b>a){
                    temp = a+1+p_sum.size()-b;
                    ans = min(ans,temp);
                }
            }
            
        }
        return (ans == 100000+1) ? -1 : ans ;
    }
};