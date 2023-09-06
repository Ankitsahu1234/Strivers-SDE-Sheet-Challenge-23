class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        if(n!=m)
            return false;
        unordered_map<char, int> mp;
        for(char ch: s)
        {
            mp[ch]++;
        }
        for(char ch: t)
        {
            if(mp.find(ch)==mp.end() || mp[ch]==0)
                return false;
            mp[ch]--;
        }
        return true;
    }
};
