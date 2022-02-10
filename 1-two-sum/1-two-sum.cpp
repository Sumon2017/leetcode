class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int> >my_nums;
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            my_nums.push_back({nums[i],i});
        }
        
        sort(my_nums.begin(),my_nums.end());
        
        int start=0 , end = nums.size() -1 ;
        
        while(start != end){
            
            if(my_nums[start].first + my_nums[end].first == target)break;
            
            else if(my_nums[start].first + my_nums[end].first > target)end--;
            
            else start++;
            
        }
        
        vector<int>answer;
        
        answer.push_back(my_nums[start].second);
        
        answer.push_back(my_nums[end].second);
        
        return answer;
    }
};