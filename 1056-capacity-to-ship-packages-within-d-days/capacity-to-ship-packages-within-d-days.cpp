class Solution {
public:
bool check(int mid , vector<int>&a,int h){
    long long int count = 1;
    int n = a.size();
    int sum = mid;
    for(int i = 0;i<n;i++){
        if(mid<a[i]) return false ;
     if(sum<a[i]){
        count ++;
        sum = mid - a[i];
     }else{
        sum = sum - a[i];
     }
    }
    return count <= 1LL*h ;
}
    int shipWithinDays(vector<int>& a, int k) {
          long long  lo = 1;
        long long  hi = 1e9; 
        long long ans = INT_MAX;
        while(lo<=hi){
            long long  mid = (lo +hi)/2;
            if(check(mid,a,k)){
                hi = mid - 1;
                ans = min(ans,mid);
            }
            else{
                lo = mid + 1;
            }
        }
        if(ans==INT_MAX) return -1 ;
        return (int)ans ; 
    }
};