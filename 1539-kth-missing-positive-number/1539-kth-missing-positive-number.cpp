class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int no=1,cnt=0;
        unordered_set<int>s;
        for(auto it : arr)
        {
            s.insert(it);
        }
            while(cnt!=k)
            {
                if(!s.count(no)) cnt++;
                no++;
            }
        return no-1;
    }
};

