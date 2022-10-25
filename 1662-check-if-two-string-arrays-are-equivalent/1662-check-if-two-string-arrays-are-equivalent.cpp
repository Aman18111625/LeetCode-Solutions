class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // string ans1,ans2;
        // for(auto str: word1) ans1+=str;
        // for(auto str: word2) ans2+=str;
        // return ans1==ans2;
        int n=word1.size(),m=word2.size();
        int i=0,j=0;
        int p=0,q=0;
        while(i<n && j<m){
           if (word1[i][p++] != word2[j][q++])
                return false;
            
            if (p >= word1[i].size())
                i++, p = 0;
            
            if (q >= word2[j].size())
                j++, q = 0;
        } 
        return i==n && j==m;
    }
};