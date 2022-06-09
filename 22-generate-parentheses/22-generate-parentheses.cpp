class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>answer;
        int N = 2*n;
        int stop_n = pow(2,N);
        int x = 0;
        stack<char>mystack;
        string arr = "";
        while(x<stop_n){
            int current = x ;
            mystack = stack<char>();
            arr = "";
            int a=0,b=0;
            for(int i=0;i<N;i++){
                (current & 1) ? a++ : b++ ;
                arr.push_back( (current & 1) ? '(' : ')' );
                current >>= 1;
                if(a>n or b>n)break;
            }
            x++;
            if(a!=b)continue;
            for(int i=0;i<arr.size();i++){
                if(!mystack.empty() and mystack.top() == '(' and arr[i] == ')' )mystack.pop();
                else mystack.push(arr[i]);
            }
            if(mystack.empty())answer.push_back(arr);
        }
        return answer;
    }
};