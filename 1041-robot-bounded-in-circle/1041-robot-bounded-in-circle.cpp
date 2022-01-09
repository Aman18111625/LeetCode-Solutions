class Solution {
public:
    /*
    bool isRobotBounded(string s) {
       vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}}; // N,E,S,W
        int n=s.length();
        int i=0,x=0,y=0;//x,y->co-ordinates,i->current direction which is north
        for(int j=0;j<n;j++){
            switch(s[j]){
                case 'G':
                    x+=dir[i][0];//ATQ,go straight
                    y+=dir[i][1];
                    break;
                case 'L':
                    i=(i+3)%4;//turn 90 degree to the left
                    break;////left is West, which is 3 units in clockwise direction, so just turn left from your current facing position which is my current i value and we did %4 because we are moving in those direction given in the input array infinitely, so %4 basically gives you the correct index between 0 and last index.
                    break;
                case 'R'://turn 90 degree to the right 
                    i=(i+1)%4;//right is east which is 1 units in clockwise direction
                    break;
            }
        }
        if((x==0 && y==0) || (i!=0)) return true;
        return false;
    }*/
      bool isRobotBounded(string s)
    {
        vector position = {0, 0}, direction = {0, 1};
          int n=s.size();
        for (size_t i = 0; i < n; i++)
        {
            switch(s[i])
            {
                case 'L':
                    direction = {-direction[1], direction[0]};
                    break;
                case 'R':
                    direction = {direction[1], -direction[0]};
                    break;
                default:
                    position = {position[0] + direction[0], position[1] + direction[1]};
            }
        }
    return (position[0]==0 && position[1]==0)||(direction[0]!= 0|| direction[1]!=1)?true:false;
    }
};