class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        int n = a.size();
        for(int i = 0;i<n;i++){
            if(a[i]<0){
            while(!st.empty() && st.top()>0 && st.top()<-a[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(a[i]);
            }
            else if(!st.empty() && st.top()<0){
                st.push(a[i]);
            }
            else  if(st.top()==-a[i]){
                st.pop();
            }
            }
            else{
                st.push(a[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};