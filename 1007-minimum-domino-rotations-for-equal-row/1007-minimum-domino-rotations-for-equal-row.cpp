class Solution {
  /*
      int countDifference(vector<int>& A, vector<int>& B, int& num) {
        int countA = 0, countB = 0;
        int n=A.size();
        for (int i=0; i<n; i++) {
            // if we have a domino which doesn't have num at all, num can't be the whole row:
            if ((A[i] != num) && (B[i] != num)) return -1;
            if (A[i] != num) countA++;
            if (B[i] != num) countB++;
        }
        return min(countA, countB);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       int res1=countDifference(tops,bottoms,tops[0]);
       int res2=countDifference(tops,bottoms,bottoms[0]);
       return min(res1,res2)>0?min(res1,res2):max(res1,res2);
    }*/
  public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();  
        // faceA for counting the occurence in tops
    		// faceB for counting occurence of numbers in bottoms
        // same for counting when both tops and bottoms have same occurences
        vector<int> faceA(7), faceB(7), same(7);  
        for(int i = 0; i < n; ++i)
        {
            ++faceA[tops[i]];
            ++faceB[bottoms[i]];
            if(tops[i] == bottoms[i])
                ++same[tops[i]];
        }
        int minRotation = INT_MAX; 
		    // all possibilities from 1 to 6
        for(int i = 1; i<=6; ++i)
        {
            if(faceA[i] + faceB[i] - same[i] == n)
                minRotation = min(minRotation , min(faceA[i],faceB[i]) - same[i]);
        }
        
        return minRotation == INT_MAX ? -1 : minRotation;
        
    }
};