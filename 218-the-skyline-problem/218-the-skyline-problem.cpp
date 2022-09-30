class Solution {
public:
     vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        map<int, vector<pair<int, int>>> map; // key : pos, value : vector of <height, start|end> pairs
        for (auto &it : buildings) {
            map[it[0]].push_back({it[2], 0}); // add startpoint->type==0
            map[it[1]].push_back({it[2], 1}); // add endpoint->type==1
        }
        multiset<int> q;
        for (auto& [pos, heights] : map) {
            for (auto& [height, type] : heights) {
                if (type == 0) q.insert(height);
                else q.erase(q.find(height));
            }
            int newHeight = q.empty() ? 0 : *q.rbegin();
            if (!res.empty() && res.back()[1] == newHeight) continue;//pre & curr height are same
            else res.push_back(vector<int>({pos, newHeight}));//pre & curr height are not same 
        }
        return res;
    }
};