class Solution {
public:
void findCombination(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds) 
{
    //it reach at the end of arr and target is zero it means we get a combination
 if(ind == arr.size())
 {
     if(target == 0) ans.push_back(ds);
      return ; 
 }
 if(arr[ind] <= target) //suppose if target is 3 and arr[ind]==4 then we can't add them
     //that's why i wrote this if statement 
 {
    ds.push_back(arr[ind]);// here we have 2option ->we can add it or not 
     findCombination(ind,target-arr[ind],arr,ans,ds);
     ds.pop_back();
 }
findCombination(ind+1,target,arr,ans,ds); //skip arr[ind] and move to next
 }
vector<vector<int>> combinationSum(vector<int>& arr, int target) {
     vector<vector<int>>ans; // to store result
        vector<int>ds; //to store combination
        findCombination(0,target,arr,ans,ds);
        return ans;
    }
};