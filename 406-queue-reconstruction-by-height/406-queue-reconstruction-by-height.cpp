class Solution {
public:
    //Approach-1:=> Simply insert the people one by one into an empty array. The number k is the position we need to insert. For everyone, we should first insert the higher h person. For the person who has same h we should first insert the person has small k value. For each inserted person, it takes O(n) time to move the person behind him back one position, so it will take the O(n^2) time for all people.
// E.g.
// input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// sort: [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
// step1: [[7,0]]
// step2: [[7,0], [7,1]]
// step3: [[7,0], [6,1], [7,1]]
// step4: [[5,0], [7,0], [6,1], [7,1]]
// step5: [[5,0], [7,0], [5,2], [6,1], [7,1]]
// step6: [[5,0], [7,0], [5,2], [4,4], [6,1], [7,1]]
  //TC:=>O(N^2)+O(NLOGN)(sort the array)
  //SC:=>O(1)
  
   static bool comp(vector<int>&a, vector<int>&b){
        if(a[0]!=b[0]) return a[0]>b[0];
        else return a[1]<b[1];
    }
  
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
          sort(begin(people),end(people),comp);
          vector<vector<int>>ans;
          for(auto it : people){
              ans.insert(ans.begin()+it[1],it);
          }
          return ans;
    }
};



