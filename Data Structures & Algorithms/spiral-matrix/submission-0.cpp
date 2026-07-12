class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>ans;
        int row_min = 0;
        int row_max = m-1;
        int col_min = 0;
        int col_max = n-1;
        while(row_min<=row_max&&col_min<=col_max){
            for(int j=col_min;j<=col_max;j++){
                ans.push_back(matrix[row_min][j]);
            }
            row_min++;
            if(!(row_min<=row_max&&col_min<=col_max))
             return ans;
            for(int i=row_min;i<=row_max;i++){
                ans.push_back(matrix[i][col_max]);
            }
            col_max--;
            if(!(row_min<=row_max&&col_min<=col_max))
             return ans;
            for(int j=col_max;j>=col_min;j--){
                ans.push_back(matrix[row_max][j]);
            }
            row_max--;
            if(!(row_min<=row_max&&col_min<=col_max))
             return ans;
            for(int i=row_max;i>=row_min;i--){
                ans.push_back(matrix[i][col_min]);
            }
            col_min++;
        }
        return ans;
    }
};
