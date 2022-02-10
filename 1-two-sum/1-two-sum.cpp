class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>answer;
        
        unordered_map<int,int>table;
        
        for ( int i = 0 ; i < nums.size() ; i ++){
            if(table[target-nums[i]] > 0 ){
                answer.push_back(i);
                answer.push_back(table[target-nums[i]]-1);
            }
            table[nums[i]] = i+1 ;
        }
        
        return answer;
    }
};