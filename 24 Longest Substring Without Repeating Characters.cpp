class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0){
            return 0;
        }
        int res = 0;
        int cnt = 0;
        map<char,int> mp;
        for(int i = 0; i < len; i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = i;
                cnt++;
            }
            else{
                res = max(res,cnt);
                cnt = 0;
                i = mp[s[i]];
                mp.clear();
            }
        }
        res = max(res,cnt);
        return res;
        
    }
};