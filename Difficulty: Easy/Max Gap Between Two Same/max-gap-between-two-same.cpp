class Solution {
public:

int maxCharGap(string &s) {
    const int size = s.size();
    int ans = -1;
    vector<int> mp(26, -1);
    
    for(int i = 0; i < size; i++) {
        // Difference between first and latest occurance
        if(mp[s[i] - 'a'] != -1) {
            ans = max(ans, i - mp[s[i] - 'a'] - 1);
        }
        // First occurance
        else {
            mp[s[i] - 'a'] = i;
        }
    }
    
    return ans;
}

};