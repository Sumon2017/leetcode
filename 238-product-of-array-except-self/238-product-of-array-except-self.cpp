class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>answer(nums.size(),1);
        int cur_prod = 1;
        for(int i = 0 ; i < nums.size() - 1 ; i++){
            cur_prod = cur_prod*nums[i];
            answer[i+1]=cur_prod;
        }
        cur_prod = 1;
        for(int i = nums.size() - 1 ; i > 0 ; i--){
            cur_prod = cur_prod*nums[i];
            answer[i-1] = answer[i-1]*cur_prod;
        }
        return answer;
    }
};
