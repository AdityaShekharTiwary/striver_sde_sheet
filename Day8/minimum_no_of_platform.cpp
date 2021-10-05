int calculateMinPatforms(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 0, j = 0;
    int cnt = 0, ans = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            i++;
            cnt++;
        }
        else {
            j++;
            cnt--;
        }
        ans = max(cnt, ans);
    }
    return ans;
}