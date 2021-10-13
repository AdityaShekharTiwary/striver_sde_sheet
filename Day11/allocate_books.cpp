class Solution
{
public:
    //Function to find minimum number of pages.

    bool isPossible(int mid, int arr[], int M, int n) {
        int student = 1, pages = 0;
        for (int i = 0; i < n; i++) {
            pages += arr[i];
            if (pages > mid) {
                student++;
                pages = arr[i];
            }
            if (student > M) return false;
        }
        return true;
    }

    int findPages(int arr[], int n, int M)
    {
        int low = 0;
        int high = 0;
        int res = -1;
        for (int i = 0; i < n; i++) {
            low = max(low, arr[i]);
            high += arr[i];
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid, arr, M, n)) {
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};