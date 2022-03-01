class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        vector<long>q_sum;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i == 0)
                q_sum.push_back(nums[i]);
            else
                q_sum.push_back(*q_sum.rbegin() + nums[i]);
        }
        
        long cur_min = 0;
        vector<long>min_arr;
        min_arr.push_back(0);
        for(int i = 0 ; i < q_sum.size() ; i++){
            cur_min = min(cur_min , q_sum[i]);
            min_arr.push_back(cur_min);
        }
        
        long answer = -1e9-1;
        long temp;
        for(int i = 0 ; i < q_sum.size() ; i++){
            if(i == 0)
                temp = q_sum[i];
            else
                temp = q_sum[i] - min_arr[i];
            answer = max(answer , temp );
        }
        return (int)answer;
        
    }
};