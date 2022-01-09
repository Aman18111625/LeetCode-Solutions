class Solution {
public:
    bool isRobotBounded(string s) {
       vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}}; // N,E,S,W
        int n=s.length();
        int i=0,x=0,y=0;
        for(int j=0;j<n;j++){
            switch(s[j]){
                case 'G':
                    x+=dir[i][0];
                    y+=dir[i][1];
                    break;
                case 'L':
                    i=(i+3)%4;
                    break;
                case 'R':
                    i=(i+1)%4;
                    break;
            }
        }
        if((x==0 && y==0) || (i!=0)) return true;
        return false;
    }
};