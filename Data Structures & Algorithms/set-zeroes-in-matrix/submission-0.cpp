class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int v = 1;
        //mark for first row
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0){
                v = 0;
                break;
            }
        }
        //mark for first col
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                matrix[0][0]=0;
                break;
            }
        }
        //mark for row
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    break;
                }
            }
        }
        //mark for col
        for(int j=1;j<n;j++){
            for(int i=0;i<m;i++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    break;
                }
            }
        }
        //process col
        for(int j=1;j<n;j++){
           if(matrix[0][j]==0){
            for(int i=1;i<m;i++){
              matrix[i][j]=0;
            }
           }
        }
        //process row
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        //process first col
        if(matrix[0][0]==0){
            for(int i=1;i<m;i++)
              matrix[i][0]=0;
        }
        //process first row
        if(v==0){
            for(int j=0;j<n;j++){
                matrix[0][j] = 0;
            }
        }
    }
};

 