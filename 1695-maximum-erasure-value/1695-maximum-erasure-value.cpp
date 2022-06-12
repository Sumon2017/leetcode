class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool>lookup(10000+1,false);
        int l=0,r=0,ans=-1,current_sum=0,size=nums.size();
        while(r<size){
            while(lookup[nums[r]]){
                lookup[nums[l]]=false;
                current_sum = current_sum - nums[l] ;
                l = l+1;
            }
            lookup[nums[r]] = true;
            current_sum = current_sum + nums[r] ;
            ans = max(ans,current_sum);
            r = r+1;
        }
        return ans;
    }
};