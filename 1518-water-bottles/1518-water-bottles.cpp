class Solution {
public:
    int numWaterBottles(int num, int Exchange) {
        int ans=num;
        while(num>=Exchange)
        {
            ans+=num/Exchange;
            num=num/Exchange+num%Exchange;
        }
        return ans; 
    }
};