class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Xor=0;
        for(auto &num : nums)
            Xor^=num;
      
       return Xor;
    }
};