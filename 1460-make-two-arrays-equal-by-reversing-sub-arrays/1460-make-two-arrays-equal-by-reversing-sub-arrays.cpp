class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
     /* if(target.size()!=arr.size()) return false;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
      return target==arr;*/
         map<int,int>mp;
        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]]++;
            mp[target[i]]--;
        }
        for(auto it : mp) if(it.second) return false;
        return true;
    }
};