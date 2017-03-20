/*
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable
 *
 * Medium (23.56%)
 * Total Accepted:    28807
 * Total Submissions: 122192
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 * 
 * 
 * 
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 * 
 * 
 * Example:
 * 
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 * 
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 * 
 * 
 */
class NumMatrix {
public:
    vector<vector<int>> vv;

    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size(); if (m == 0) return;
        int n = matrix[0].size(); if (n == 0) return;

        vv.resize(m);
        for (auto &v : vv) v.resize(n);

        vv[0][0] = matrix[0][0];
        for (int i = 1; i < m; ++i) vv[i][0] = vv[i-1][0] + matrix[i][0];
        for (int j = 1; j < n; ++j) vv[0][j] = vv[0][j-1] + matrix[0][j];

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                vv[i][j] = vv[i][j-1] + vv[i-1][j] - vv[i-1][j-1] + matrix[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (col1 == 0 && row1 == 0) return vv[row2][col2];
        else if (col1 == 0) return vv[row2][col2] - vv[row1-1][col2];
        else if (row1 == 0) return vv[row2][col2] - vv[row2][col1-1];
        else return vv[row2][col2]-vv[row2][col1-1]-vv[row1-1][col2]+vv[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
