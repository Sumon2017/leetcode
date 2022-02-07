class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int tmp1 ;
        
        string answer = "" ;
        
        int smallest = 1000 ;
        
        for( int i = 0 ; i < strs.size() ; i++ ){
            tmp1 = strs[i].size();
            smallest = min( smallest , tmp1 ) ;
        }
        
        bool flag = false ;
        
        for( int i = 0 ; i < smallest ; i++ ){
            
            for( int j = 0 ; j < strs.size() ; j++ ){
                
                if( strs[0][i] != strs[j][i] ){
                    flag = true ;
                    break;
                }
                
                if( j == strs.size() - 1 ){
                    answer.push_back(strs[0][i]);
                }
                
            }
            
            if(flag)break;
            
        }
        
        return answer;
        
    }
};