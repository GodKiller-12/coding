class Solution {
public:
struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second << 1);
    }
};

unordered_map<pair<int,int>,int, pair_hash> mp;

int rec(int i , int j , vector<int>& cuts){
    bool found = false;
    for(int k = 0; k < cuts.size(); k++){
        if(cuts[k] > i && cuts[k] < j){
            found = true;
        }
    }

    if(!found){
        return 0;
    }

    if(mp.count({i,j})) return mp[{i,j}];

    int ans = INT_MAX;
    for(int k = 0; k < cuts.size(); k++){
        if(cuts[k] > i && cuts[k] < j){
            ans = min(ans, (j - i) + rec(i, cuts[k], cuts) + rec(cuts[k], j, cuts));
        }
    }

    return mp[{i,j}] = ans;
}

int minCost(int n, vector<int>& cuts) {
    return rec(0, n, cuts);
}
};
