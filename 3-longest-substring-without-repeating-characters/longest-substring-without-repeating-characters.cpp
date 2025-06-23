class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        map<int,int>mp;
        int j = 0;
        int i = 0;
        while(j<n){
          mp[s[j]]++;
          j++;
          if((j-i)==mp.size()){
            maxi = max(maxi,j-i);
          }
          else{
            while((j-i)!=mp.size()){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                  i++;
            }
          }
        }
        return maxi ;
    }
};