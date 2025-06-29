class Solution {
public:
    int largestRectangleArea(vector<int>&a) {
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
};