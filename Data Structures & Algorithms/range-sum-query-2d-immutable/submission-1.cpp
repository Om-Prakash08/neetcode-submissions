class NumMatrix {
public:
    vector<vector<int>>prefixMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefixMatrix.resize(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(i!=0)
             prefixMatrix[0][i]=prefixMatrix[0][i-1]+matrix[0][i];
            else 
             prefixMatrix[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int>prefixSum(m,0);
            for(int j=0;j<m;j++){
                if(j!=0)
                  {
                    prefixSum[j]=prefixSum[j-1]+matrix[i][j];
                    prefixMatrix[i][j]=prefixMatrix[i-1][j]+prefixSum[j];
                  }
                else{
                    prefixSum[j]=matrix[i][j];
                    prefixMatrix[i][j]=prefixMatrix[i-1][j]+prefixSum[j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixMatrix[row2][col2]
                 -(row1>0?prefixMatrix[row1-1][col2]:0)
                 -(col1>0?prefixMatrix[row2][col1-1]:0)
                 +(row1>0&&col1>0?prefixMatrix[row1-1][col1-1]:0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */