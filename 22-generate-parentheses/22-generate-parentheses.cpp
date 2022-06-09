class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>answer;
        int N = 2*n;
        int stop_n = pow(2,N);
        int x = 0;
        while(x<stop_n){
            int current = x ;
            stack<char>mystack;
            string arr = "";
            for(int i=0;i<N;i++){
                arr.push_back( (current & 1) ? '(' : ')' );
                current >>= 1;
            }
            for(int i=0;i<arr.size();i++){
                if(!mystack.empty() and mystack.top() == '(' and arr[i] == ')' )mystack.pop();
                else mystack.push(arr[i]);
            }
            if(mystack.empty())answer.push_back(arr);
            x++;
        }
        return answer;
    }
};