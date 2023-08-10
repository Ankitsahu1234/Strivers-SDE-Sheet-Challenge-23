// PROBLEM LINK: https://leetcode.com/problems/word-break-ii/description/

class Solution {
public:
    void solve(int index, string s, string temp, unordered_set<string> &myset, vector<string> &ans)
    {
        if(index==s.length())
        {
            temp.pop_back();
            ans.push_back(temp);
        }
        string str="";
        for(int i=index; i<s.length(); i++)
        {
            str+=s[i];
            if(myset.count(str))
            {
                solve(i+1, s, temp+str+" ", myset, ans);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> myset(wordDict.begin(), wordDict.end());
        vector<string> ans;
        string temp="";
        solve(0, s, temp, myset, ans);
        return ans;
    }
};
