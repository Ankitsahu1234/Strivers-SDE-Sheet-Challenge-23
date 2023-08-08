class Solution {
    vector<string> temp;
public:
    bool isPal(string &str, int l, int r)
    {
        while(l<r)
        {
            if(str[l++]!=str[r--])
                return false;
        }
        return true;
    }

    void solveRec(string &s, int index, vector<vector<string>> &res)
    {
        if(index==s.length())
        {
            res.push_back(temp);
            return;
        }
        for(int i=index; i<s.length(); i++)
        {
            if(isPal(s, index, i))
            {
                temp.push_back(s.substr(index, i-index+1));
                solveRec(s, i+1, res);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        solveRec(s, 0, res);
        return res;
    }
};
