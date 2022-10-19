class Solution {
    static bool comp(pair<int,string> p1, pair<int,string> p2){
        if(p1.first>p2.first || (p1.first==p2.first && p1.second<p2.second))
            return true;
        return false;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
       unordered_map<string,int>map;
       for(auto word: words) map[word]++;
       vector<pair<int,string>>temp;
       for(auto it: map){
         temp.push_back({it.second,it.first});
       }
       sort(temp.begin(),temp.end(),comp);
       vector<string>ans;
       for(int i=0;i<k;i++){
         ans.push_back(temp[i].second);
       }
       return ans;
    }
};