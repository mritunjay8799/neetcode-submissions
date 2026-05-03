class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int>res(n,0);
        stack<int>st;

        for(int i = 0; i<n; i++){
            while(!st.empty() && t[st.top()] < t[i]){
                int idx = st.top();
                st.pop();
                res[idx] = i-idx;
            }
            st.push(i);
        }
        return res;
    }
};
