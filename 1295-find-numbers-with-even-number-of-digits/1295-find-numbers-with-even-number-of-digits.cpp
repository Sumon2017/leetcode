class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int answer = 0 ;
        int count,current;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            count = 0 ;
            current = nums[i];
            
            while(current){
                current = current / 10;
                count = count + 1;
            }
            
            if(count % 2 == 0)answer = answer + 1;
            
        }
        
        return answer;
        
    }
};