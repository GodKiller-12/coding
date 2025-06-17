class Solution {
public:
int la(vector<int>&a) {
        //  a[i] *(nse - pse -1);
        int n = a.size();
     stack<int>st;
     int ans = 0;
     for(int i = 0;i<n;i++){
      while(!st.empty() && a[st.top()]>a[i]){
        int nse = i;
        int pse = -1;
        int num = st.top();
        st.pop();
        if(!st.empty()){
            pse = st.top();
        }
        ans = max(ans , a[num]*(nse-pse-1));
      }
      st.push(i);
     }
          int nse = n;
    int pse = -1; 
   
    while(! st.empty() ){
      int num = st.top();
      st.pop();

      if(!st.empty()){
        pse = st.top();
      }
      else{
        pse = -1;
      }
      ans = max(ans,a[num]*(nse-pse-1));
    }
    return ans ;
}
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>pref(n,vector<int>(m,0));
        for(int j = 0;j<m;j++){
            for(int i = 0;i<n;i++){
                if(a[i][j]=='1'){
                    if(i==0){
                   pref[i][j] = 1;
                    }
                    else{
                        pref[i][j] = 1+pref[i-1][j];
                    }
                }
                
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans , la(pref[i]));
        }
        return ans ;
    }
};