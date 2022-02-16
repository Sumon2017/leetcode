class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        string s = "";
        int temp;
        char ch;
        while(x!=0){
            temp = x%10 ;
            x = x/10 ;
            ch = '0' + temp ;
            s.push_back(ch);
        }
        reverse(s.begin(),s.end());
        for ( int i = 0 ; i < s.size() ; i ++){
            if(s[i] != s[s.size()-1-i])return false;
        }
        return true;
    }
};