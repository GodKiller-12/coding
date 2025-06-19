class Solution {
public: 
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(num == "0" || k == num.size()) {
            return "0";
        }

        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && (num[i] - '0') < st.top() && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i] - '0');
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty()) {
            ans +=  (char)(st.top() + '0'); 
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};
