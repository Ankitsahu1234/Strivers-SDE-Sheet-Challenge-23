class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        // Transposing the Matrix;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reversing each row of the Matrix
        for(int i=0; i<n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
