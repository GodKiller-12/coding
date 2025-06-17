class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
      int l = 0;
      int lmax = a[0];
      int rmax = a[n-1];
      int r = n-1;
      int ans = 0;
      while(l<r){
        // cout<<l<<" "<<r<<" "<<lmax<<" "<<rmax<<endl;
        if(a[r]>=a[l]){
        if(lmax>=a[l]){
            ans = ans + (lmax-a[l]);
            l++;
        }
        else{
            lmax = max(lmax,a[l]);
            l++;
        }
        }
        else{
             if(rmax>=a[r]){
            ans = ans + (rmax-a[r]);
            r--;
        }
        else{
            rmax = max(rmax,a[r]);
            r--;
        }
        }
      }
return ans ;
    }
};