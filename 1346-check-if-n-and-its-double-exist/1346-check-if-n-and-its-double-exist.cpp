class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
         unordered_map<int,int>mpp;
         for(auto num : arr){
             if(mpp.find(2*num)!=mpp.end()) return true;
             else if(num%2==0 and mpp.find(num/2)!=mpp.end()) return true;
             else 
                 mpp[num]++;
         }
        return false;
    }
};