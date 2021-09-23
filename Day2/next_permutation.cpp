vector<int> nextPermutation(vector<int> &arr, int n)
{
    if (n == 1) return arr;
    int idx1 = 0, idx2 = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            idx1 = i;
            break;
        }
    }
    if (idx1 == 0 && arr[0] > arr[1]) {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    else {
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] > arr[idx1]) {
                idx2 = i;
                break;
            }
        }
        swap(arr[idx1], arr[idx2]);
        reverse(arr.begin() + idx1 + 1, arr.end());
    }
    return arr;
}