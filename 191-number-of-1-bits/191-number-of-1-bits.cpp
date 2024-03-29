class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0 ;
        while(n){
            if(n&1)answer = answer + 1 ;
            n = n >> 1 ;
        }
        return answer;
    }
};