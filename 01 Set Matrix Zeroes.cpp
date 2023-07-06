class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<bool> rowZero(row, false);
        vector<bool> colZero(col, false);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j]==0){
                    rowZero[i] = true;
                    colZero[j] = true;
                }
            }
        }

        for(int i=0; i<row; i++){
            if(rowZero[i]){
                for(int j=0; j<col; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=0; j<col; j++){
            if(colZero[j]){
                for(int i=0; i<row; i++){
                    matrix[i][j] = 0;
                }
            }
        }

        // Space Complexity: O(m+n)
        // Time Complexity: O(m*n)
       
    }
};