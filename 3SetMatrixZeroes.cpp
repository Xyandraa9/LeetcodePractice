// bruteforce solution
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         vector<int> row(m,0);
//         vector<int> col(n,0);

//         for(int i =0; i<m; i++){
//             for(int j =0; j<n;j++){
//                 if(matrix[i][j]== 0){
//                     row[i]=1;
//                     col[j]=1;
//                 }
//             }
//         }
//         for(int i =0; i<m; i++){
//             for(int j =0; j<n;j++){
//                 if(row[i]==1 ||col[j]==1){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//     }
// };

//optimal
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
    int n = matrix[0].size();

    int col0 = 1;

    // Step 1: Mark rows and cols using first row and first col
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) col0 = 0;

        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;   // mark row
                matrix[0][j] = 0;   // mark col
            }
        }
    }

    // Step 2: Fill zeros based on markers (go backwards)
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }

        // handle first column separately
        if (col0 == 0) {
            matrix[i][0] = 0;
        }
    }
    }
};

