class Solution {
public:
    using List = vector<string>;
    vector<string> generateParenthesis(int n) {
        List result;
        backtrack(n, "", result);
        return result;
    }

    void backtrack(int n, string current, List& result){
        if(current.size() == 2*n){
            if(isBalanced(current))
                result.push_back(current);
            return;
        }

        backtrack(n, current + '(', result);
        backtrack(n, current + ')', result);
    }

    bool isBalanced(string s){
        int open = 0;
        for(char c : s){
            open += c == '(' ? 1 : -1;
            if(open < 0) return false;
        }

        return open == 0;
    }
};
