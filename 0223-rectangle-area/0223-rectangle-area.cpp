class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // Finding the area of two rectangles
        int a1 = abs(abs(A - C) * abs(B - D));
        int a2 = abs(abs(E - G) * abs(F - H));
        
        // If it does not meet the criteria for instersecting rectangles return the sum     
        if (!(A < G && B < H && E < C && F < D)) return a1 + a2;
        
        // Finding the corners of the intersection
        int a = max(A, E);
        int b = max(B, F);
        int c = min(C, G);
        int d = min(D, H);
        
        // Finding the area of the intersection
        int intersect = abs(abs(a - c) * abs(b - d));
        
        // the interset must be placed in the middle incase of int
        // overflow with two large a1 + a2
        return a1 - intersect + a2 ; 
    }
};