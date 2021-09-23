vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> res;
    for (int i = 0; i < n; i++) {
        vector<long long int> row(i + 1, 1);
        for (int j = 1; j < i; j++) {
            row[j] = res[i - 1][j] + res[i - 1][j - 1];
        }
        res.push_back(row);
    }
    return res;
}
