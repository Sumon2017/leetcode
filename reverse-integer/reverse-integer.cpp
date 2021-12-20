class Solution {
public:
    int reverse(int x) {
        long int val = x , xx = x ;
        xx = abs( xx );
        vector<long int> arr;
        while( xx ){
            arr.push_back(xx%10);
            xx /= 10;
        }
        long int result = 0 ;
        for(int i = 0 ; i < arr.size() ; i++){
            result = result * 10 + arr[i] ;
        }
        if( val < 0 ) result = 0 - result ;
        if( val > 0 && result > 2147483648 -1 ) return 0 ;
        if( val < 0 && result < -2147483648 ) return 0 ;
        
        return (int)result ;
    }
};