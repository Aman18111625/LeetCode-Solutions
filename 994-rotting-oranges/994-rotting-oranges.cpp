class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int>dir{-1,0,1,0,-1}; // for finding all 4-adjacent
        int m=grid.size(); //no of row
        int n=grid[0].size(); //no of col
        queue<pair<int,int>>q; 
        int fresh=0;//To keep track of all fresh oranges left
        for(int i=0;i<m;i++) //
        {
            for(int j=0;j<n;j++)
            {
              if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
            auto p=q.front();
            q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 and r<m and c>=0 and c<n and grid[r][c]==1) 
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--;// decrement by 1 foreach fresh orange that now is rotten
                    }
                }
            }
            ans++;//incremented after each minute passes
        }
        if(fresh>0) return -1;//if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0;//there were no oranges it'd take 0 mins.
        return ans;
    }
};