class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
          int m=arr.size();
        int n=arr[0].size();
        int left=0,right=n-1,top=0,down=m-1;
        vector<int>res;
        int dir=0;
        while(top<=down and left<=right)
        {
            if(dir==0) //left to right
            {
                for(int i=left;i<=right;i++)
                    res.push_back(arr[top][i]);
                top++;
            }else if(dir==1) //top to down
            {
                for(int i=top;i<=down ;i++)
                res.push_back(arr[i][right]);
                    right--;
            }else if(dir==2) //right to left
            {
                for(int i=right;i>=left;i--)
                    res.push_back(arr[down][i]);
                down--;
            }else if(dir==3) //down to top
            {
                for(int i=down;i>=top;i--)
                    res.push_back(arr[i][left]);
                left++;
            }
            dir=(dir+1)%4;
        }
        return res;
    }
};