class Solution {
    /*
     void solve(string & s, int index,vector<string>&res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        solve(s, index + 1, res);
        swap(s[i], s[index]);
      }
     }
public:
    string getPermutation(int n, int k) {
        string s;
        vector<string>res;
        for(int i=1;i<=n;i++){
            s+=(i+'0');
        }
        solve(s,0,res);
        sort(res.begin(),res.end());
        auto it=res.begin()+(k-1);
        return *it;
    }*/
    public:
    string getPermutation(int n,int k){
        string ans="";
        vector<int>number;
        int fact=1;
        for(int i=1;i<n;i++){
            fact*=i;
            number.push_back(i);
        }
        number.push_back(n);
        k--;//doing this because we're finding our res in 0th based index
        while(true){
            ans+=to_string(number[k/fact]);
             number.erase(number.begin()+k/fact);
            if(number.size()==0) break;
            k=k%fact;
            fact/=number.size();
        }
        return ans;
    }
};