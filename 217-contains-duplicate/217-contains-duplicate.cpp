class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int>my_map;
        
        for(int i = 0 ; i < nums.size() ; i++){
            my_map[nums[i]]++;
        }
        
        if(nums.size() == my_map.size())return false;
        else return true;
    }
};