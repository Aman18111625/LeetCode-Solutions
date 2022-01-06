class Solution {
public:
    /*
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int res=0;
        for(int i=0;i<(n/3);i++){
            res+=piles[n-2*i-2];
        }
        return res;
    }*/
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size(),res=0;
        for(int i=n/3;i<n;i+=2){
            res+=piles[i];
        }
        return res;
    }
};