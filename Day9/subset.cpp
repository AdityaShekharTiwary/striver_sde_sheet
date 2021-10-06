void subset(vector<int> arr, vector<vector<int>> &res, vector<int> &temp, int n, int idx) {
    if (idx == n) {
        if (temp.size() > 0) {
            res.push_back(temp);
        }
        return;
    }
    // containing the current element
    temp.push_back(arr[idx]);
    subset(arr, res, temp, n, idx + 1);
    temp.pop_back();

    // not containing the current element
    subset(arr, res, temp, n, idx + 1);
}

void printAllSubsets(int n, vector<int> &arr) {
    vector<vector<int>> res;
    vector<int> temp;
    subset(arr, res, temp, n, 0);
    for (int i = 0; i < res.size(); i++) {
        sort(res[i].begin(), res[i].end());
        for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << " ";
        cout << endl;
    }

}