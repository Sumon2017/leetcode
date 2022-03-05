class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int l = 0 , r = 0 ;
        long cur_max = -1e9-1;
        long cur_sum = 0;
        while(r<nums.size()){
            cur_sum = cur_sum + nums[r];
            cur_max = max(cur_max,cur_sum);
            if(cur_sum<1){
                cur_sum=0;
                l=r+1;
            }
            r=r+1;
        }
        return (int)cur_max;
        
    }
};