class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        vector<pair<int,int>>nexts(n);
        vector<pair<int,int>>prevs(n);
        stack<pair<int,int>>st;
        for(int i = n- 1;i>=0;i--){
            while(!st.empty() && st.top().first>a[i]){
                st.pop();
            }
            if(st.empty()){
                nexts[i] = {-1,-1};
            }else{
                nexts[i] = st.top();
            }
            st.push({a[i],i});
        }
        while(!st.empty()){
            st.pop();
        }

        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top().first>=a[i]){
                st.pop();
            }
             if(st.empty()){
                prevs[i] = {-1,-1};
            }else{
                prevs[i] = st.top();
            }
            st.push({a[i],i});
        }
        int MOD = 1e9+7 ;
        long long ans = 0;
        for(int i = 0 ;i<n;i++){
            int left = -1;
            int right = n;
            if(prevs[i].second!=-1){
                left = prevs[i].second ;
            }
            if(nexts[i].second!=-1){
                right = nexts[i].second ;
            }
            // cout<<left<<" "<<i<<" "<<right<<endl;
            int lefti = (i-left);
            int righti = right - i ;
long long count  = ((1LL * a[i] * lefti) % MOD * righti) % MOD;
            ans = (ans + count)%MOD ;
        }
        return ans ;

    }
};