/*
TC : O(N*M)
SC : O(N+M)
Approach : Store idx with value 1 then
set to corresponding rows and col with 1

*/

void setMatrixOnes(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> row(n, -1);
    vector<int> col(m, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 1;
            }
        }
    }
}


/*
    Time Complexity: O(N * M)
    Space Complexity: O(1)

    where 'N' is the number of rows and
    'M' is the number of columns of grid.
*/

void setMatrixOnes(vector<vector<int>> &MAT, int n, int m)
{
    int firstRow = 0;
    int firstColumn = 0;

    for (int i = 0; i < n; i++)
    {
        // If value at first column of 'i-th' row is 1
        if (MAT[i][0] == 1)
        {
            firstColumn = 1;
        }

        // Check all the columns
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && MAT[i][j] == 1)
            {
                firstRow = 1;
            }

            /*
            If any cell MAT[i][j] has value 1, set first column of 'i-th' row
            and first row of 'j-th' column as 1.
            */
            if (MAT[i][j] == 1)
            {
                MAT[i][0] = 1;
                MAT[0][j] = 1;
            }
        }
    }

    /*
    Set value of cells to 1, if either first column of 'i-th' row
    and first row of 'j-th' column is 1.
    */
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (MAT[i][0] == 1 || MAT[0][j] == 1)
            {
                MAT[i][j] = 1;
            }
        }
    }

    // Set value of first row.
    if (firstRow == 1)
    {
        for (int j = 0; j < m; j++)
        {
            MAT[0][j] = 1;
        }
    }

    // Set value of first column
    if (firstColumn == 1)
    {
        for (int i = 0; i < n; i++)
        {
            MAT[i][0] = 1;
        }
    }
}
