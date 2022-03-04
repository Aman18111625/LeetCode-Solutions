class NumMatrix {
    vector<vector<int>>res;
public:
    NumMatrix(vector<vector<int>>& mat) {
          res=mat;
          for(auto &row : res) 
            for(int i = 1; i < row.size(); i++) 
                row[i] += row[i - 1];  
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
          int sum=0;
         for(int row=row1;row<=row2;row++)
          sum += res[row][col2] - (col1 ? res[row][col1 - 1] : 0);
         return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */