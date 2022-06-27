class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(char digit: n){
          int val=digit-'0';
          maxi=max(maxi,val);
        }
        return maxi;
    }
};