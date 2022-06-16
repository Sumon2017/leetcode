class Solution {
public:
    string longestPalindrome(string s) {
        int counter;
        string ans="",cur,temp;
        for(int i=0;i<s.size();i++){
            counter = 1;
            cur = "";
            while(i-counter >=0 and i+counter <s.size() and s[i-counter] == s[i+counter]){
                cur.push_back(s[i+counter]);
                counter = counter + 1;
            }
            temp=cur;
            reverse(temp.begin(),temp.end());
            cur = temp + s[i] + cur ;
            ans = (cur.size() > ans.size()) ? cur : ans;
            counter = 1;
            cur = "";
            while(i-counter >=0 and i+counter-1 <s.size() and s[i-counter] == s[i+counter-1]){
                cur.push_back(s[i+counter-1]);
                counter = counter + 1;
            }
            temp=cur;
            reverse(temp.begin(),temp.end());
            cur = temp + cur ;
            ans = (cur.size() > ans.size()) ? cur : ans;
        }
        return ans;
    }
};