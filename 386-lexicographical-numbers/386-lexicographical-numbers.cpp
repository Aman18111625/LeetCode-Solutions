class Solution {
public:
  /*
    vector<int> lexicalOrder(int n) {
        vector<string>s;
        for(int i=1;i<=n;i++) s.push_back(to_string(i));
        sort(s.begin(),s.end());
        vector<int>res;
        for(int i=0;i<n;i++) res.push_back(stoi(s[i]));
        return res;
    }*/
    vector<int>ans;
    void rec(int n, int s){
        if(s>n) return;
        ans.push_back(s);
        rec(n, s*10);
        if((s+1)%10) rec(n, s+1);
    }
    vector<int> lexicalOrder(int n) {
        ans.clear();
        rec(n,1);
        return ans;
    }
};