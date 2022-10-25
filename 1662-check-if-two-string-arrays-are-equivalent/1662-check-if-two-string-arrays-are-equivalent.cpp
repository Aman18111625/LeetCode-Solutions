class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1,ans2;
        for(auto str: word1) ans1+=str;
        for(auto str: word2) ans2+=str;
        return ans1==ans2;
    }
};