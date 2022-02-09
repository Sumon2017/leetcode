class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int num1,num2;
        
        unordered_map<int,int>table;
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            table[nums[i]] += 1 ;
        }
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            if(nums[i] != target-nums[i] && table[target-nums[i]] >= 1){
                num1 = nums[i];
                num2 = target-nums[i];
                break;
            }
            if(nums[i] == target-nums[i] && table[target-nums[i]] >= 2){
                num1 = nums[i];
                num2 = nums[i];
                break;
            }
        }
        
        vector<int>answer;
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            if(num1 == nums[i]){
                answer.push_back(i);
                break;
            }
        }
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            if(i==answer[0])continue;
            
            if(num2 == nums[i]){
                answer.push_back(i);
                break;
            }
        }
        
        return answer;
    }
};