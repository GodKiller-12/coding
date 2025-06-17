class Solution {
public:
    vector<int> nextGreaterElement(vector<int>&a, vector<int>&b) {
        vector<int>ans(a.size(),-1);
        map<int,int>mp;
        stack<int>st;
        for(int i =  b.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<b[i]){
                st.pop();
            }
            if(st.empty()){
                mp[b[i]] = -1;
                st.push(b[i]);
            }
            else if( b[i]<st.top()){
            mp[b[i]] = st.top();
            st.push(b[i]);
          }
        
        }
        for(int i = 0;i<a.size();i++){
            ans[i] = mp[a[i]];
        }
        return ans ;
    }
};