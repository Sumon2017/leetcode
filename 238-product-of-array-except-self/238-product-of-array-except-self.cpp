class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod = 1 ;
        
        int zero = 0 ;
        
        for (int i = 0 ; i < nums.size() ; i++){
            
            if(nums[i] == 0){
                zero ++ ;
            }
            else{
                prod = prod * nums[i] ;
            }
            
        }
        
        vector<int>answer;
        
        for (int i = 0 ; i < nums.size() ; i++){
            
            if(nums[i] == 0){
                if(zero > 1 )answer.push_back(0);
                else answer.push_back(prod);
            }
            else{
                if(zero > 0)answer.push_back(0);
                else answer.push_back(prod/nums[i]);
            }
        }
        
        return answer;
        
    }
};