class Solution {
public:
    int Combination(int n, int r){
        long long result = 1;
        for(int i=0; i<r; i++){
            result = result * (n-i);
            result = result / (i+1);
        }
        return result;
    }

    vector<int> generateRow (int rowIndex){
        vector<int> row;
        for(int i=0; i<=rowIndex; i++){
            row.push_back(Combination(rowIndex, i));
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        if(numRows==0) return triangle;

        for(int i=0; i<numRows; i++){
            triangle.push_back(generateRow(i));
        }
        return triangle;
    }
    
};