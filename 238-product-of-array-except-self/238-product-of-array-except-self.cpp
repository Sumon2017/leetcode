class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>pre_prod;
        vector<int>post_prod;
        int cur_prod = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            cur_prod = cur_prod * nums[i];
            pre_prod.push_back(cur_prod);
        }
        cur_prod = 1;
        for(int i = nums.size()-1 ; i>=0 ; i--){
            cur_prod = cur_prod * nums[i];
            post_prod.push_back(cur_prod);
        }
        reverse(post_prod.begin(),post_prod.end());
        vector<int>answer;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i==0)answer.push_back(post_prod[i+1]);
            else if(i==nums.size()-1)answer.push_back(pre_prod[i-1]);
            else answer.push_back(pre_prod[i-1]*post_prod[i+1]);
        }
        return answer;
    }
};
