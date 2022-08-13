class Solution {
public:
 bool checkSubstring(unordered_map<string,int>map, string s, int len) {
        for(int j=0; j<s.size(); j+=len) {
            string w = s.substr(j,len);
            if(map.find(w) != map.end()) {
                if(--map[w] == -1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int len = words[0].size();
        int n = s.size();
        int window = words.size() * len;
        
        unordered_map<string,int>map;
        for(auto word: words) {
            map[word]++;
        }
        
        int i = 0;
        while(i + window <= n) {
            if(checkSubstring(map, s.substr(i, window), len)) {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};

