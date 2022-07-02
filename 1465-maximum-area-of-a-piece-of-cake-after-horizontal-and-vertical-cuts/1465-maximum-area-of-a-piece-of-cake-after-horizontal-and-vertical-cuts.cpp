class Solution {
public:
/*Intution:=>
If a cake is only cut horizontally and vertically, then the longest height of the pieces will be the longest gap in the horizontal cuts and the longest width of the pieces will be the longest gap in the vertical cuts.
Now just observe, for each possible height of pieces (gap between the horizontal cuts) there is all possible width of the pieces (gap between the vertical cuts). This is bacause when a cake is cut horizontally it is divided into number of pieces of different lenghts. After cutting the cake vertically each of those sections are divided into pieces of different breadths. So the maximum area is the product of the maximum height and maximum length.
*/
  
  //TC:=>O(NLOGN+MLOGM)
  //SC:=>O(1)
  
    const int mod=1e9+7;
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
          hCuts.push_back(h);
          sort(hCuts.begin(),hCuts.end());
          int maxHeight=hCuts[0];
          int n=hCuts.size();
          for(int i=1;i<n;i++){
            maxHeight=max(maxHeight,hCuts[i]-hCuts[i-1]);
          }
          
          vCuts.push_back(w);
          sort(vCuts.begin(),vCuts.end());
          int maxWidth=vCuts[0],m=vCuts.size();
          for(int i=1;i<m;i++){
            maxWidth=max(maxWidth,vCuts[i]-vCuts[i-1]);
          }
          return (1LL*maxHeight*maxWidth)%mod;
    }
};

 