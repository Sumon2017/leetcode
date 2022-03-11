class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int len = nums.size();
        int total_sum = (len*(len+1))/2;
        for(int i = 0 ; i < nums.size(); i++)total_sum = total_sum - nums[i] ;
        return total_sum ;
        
    }
};