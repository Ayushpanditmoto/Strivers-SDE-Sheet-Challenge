class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix[0].size();
        if(n==0) return false;

        // int i=0,j=n-1;
        // while(i<m && j>=0){
        //     if(matrix[i][j]==target) return true;
        //     else if(matrix[i][j]>target) j--;
        //     else i++;
        // }

        int l=0,r=m*n-1;
        while(l<=r){
            int mid=(l+r)/2;
            int x=mid/n,y=mid%n;
            if(matrix[x][y]==target) return true;
            else if(matrix[x][y]>target) r=mid-1;
            else l=mid+1;
        }

        
        return false;
        
    }
   
};