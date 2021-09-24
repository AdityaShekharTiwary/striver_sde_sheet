/*
TC : O(N + Log(M))
SC : O(1)
Appraoch : Binary Seach
*/


class Solution {
public:

    bool binarySearch(vector<int> arr, int target) {
        int l = 0, r = arr.size() - 1;
        while (r >= l) {
            int mid = (l + r) / 2;
            if (arr[mid] > target) r = mid - 1;
            else if (arr[mid] < target) l = mid + 1;
            else return true;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        while ((row < matrix.size()) && matrix[row].back() < target) row++;
        if (row >= matrix.size()) return false;
        return binarySearch(matrix[row], target);
    }
};

/*
TC : O(Log(N*M))
SC : O(1)
Appraoch : Binary Seach (Treat the matrix as
           sorted array)
*/



bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int n = matrix.size(), m = matrix[0].size();
    if (matrix[0][0] > target || matrix[n - 1][m - 1] < target)  return false;
    int l = 0, r = n * m - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (matrix[mid / m][mid % m] < target) l = mid + 1;
        else if (matrix[mid / m][mid % m] > target) r = mid - 1;
        else return true;
    }
    return false;
}