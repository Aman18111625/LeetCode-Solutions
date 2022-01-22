class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int even=0,odd=0;
        int n=piles.size();
        for(int i=0;i<n;i+=2) even+=piles[i];
        for(int i=1;i<n;i+=2) odd+=piles[i];
        if(even!=odd) return true;
        return false;
    }
};