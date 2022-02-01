class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
          int A=rect1[0],B=rect1[1],C=rect1[2],D=rect1[3];
          int E=rect2[0],F=rect2[1],G=rect2[2],H=rect2[3];
         if (!(A < G && B < H && E < C && F < D)) return false;
         return true;
    }
};