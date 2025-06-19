class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for (char digit : num) {
            while (!st.empty() && st.back() > digit && k > 0) {
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }

        while (k-- > 0 && !st.empty()) {
            st.pop_back();
        }
        int start = 0;
        while (start < st.size() && st[start] == '0') start++;

        string result = st.substr(start);
        return result.empty() ? "0" : result;
    }
};
