class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int a=c[0][0],b=c[0][1];
        int x=c[1][0]-c[0][0];
        int y=c[1][1]-c[0][1];
        for(int i=0;i<c.size();i++){
            if( (c[i][0]-a) * y  != x* (c[i][1]-b) )
                return false;
        }
        return true;
    }
};