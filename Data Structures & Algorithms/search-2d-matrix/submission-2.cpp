class Solution {
public:

    int binarysearch(vector<vector<int>>& matrix,int target, int row){
        int low = 0;
        int high = matrix[0].size()-1;

        while(low <= high){ 
        int mid = low + (high - low)/2;

            if (matrix[row][mid] == target){
                return mid;
            }
            if(target < matrix[row][mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
       int r = matrix.size();
       int c = matrix[0].size();
       int row = -1;
         
            for(int i = 0; i < r; i++){
                if(target <= matrix[i][c-1]){
                    row = i;
                    break;
                }
            }

        if (row == -1){
            return false;
        }
        int ans = binarysearch(matrix, target, row);
        if (ans != -1){
            return true;
        }
        else return false;
    }
};
