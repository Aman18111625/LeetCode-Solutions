class Solution {
public:
    bool wordPattern(string pat, string s) {
        vector<string>temp;
        stringstream ss(s);
        string word;
        while(ss>>word) temp.push_back(word);
        if(pat.size()!=temp.size()) return false;
        unordered_map<char,string>mpp;
        set<string>st;
        for(int i=0;i<pat.size();i++)
        {
            if(mpp.find(pat[i])==mpp.end())
            {
                if(st.count(temp[i])>=1) return false;
                mpp[pat[i]]=temp[i];
                st.insert(temp[i]);
                
            }else
            {
                if(mpp[pat[i]]!=temp[i]) return false;
            }
        }
        return true;
    }
};