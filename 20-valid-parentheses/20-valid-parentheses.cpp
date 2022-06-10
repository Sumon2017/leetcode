class Solution {
public:
    bool isValid(string s) {
        stack<char>mystack;
        for(int i=0;i<s.size();i++){
            if(!mystack.empty() and ( (mystack.top() == '(' and s[i] == ')') or (mystack.top() == '{' and s[i] == '}') or (mystack.top() == '[' and s[i] == ']')  ))mystack.pop();
            else mystack.push(s[i]);
        }
        return mystack.empty();
    }
};