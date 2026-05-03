
class Solution {
public:
    int evaluate(string op, int x, int y){
        char c = op[0];
        switch(c){
            case '+' : return x+y;
            case '-' : return y-x;
            case '*' : return x*y;
            case '/' : return y/x;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int answer = 0;
        int n = tokens.size();
        for(int i = 0; i<n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || 
               tokens[i] == "*" || tokens[i] == "/")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                answer = evaluate(tokens[i], x, y);
                st.push(answer);
                
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
