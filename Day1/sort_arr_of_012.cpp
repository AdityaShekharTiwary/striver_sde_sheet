/*
TC :- O(N)
SC :- O(1)
Approach :- Three Pointers
*/

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1, mid = 0;
        while (mid <= high) {
            if (arr[mid] == 0) swap(arr[mid++], arr[low++]);
            else if (arr[mid] == 1) mid++;
            else swap(arr[mid], arr[high--]);
        }
    }
};



/*
TC :- O(N)
SC :- O(1)
Approach :- Counting the frequency of 0 1 2
*/

void sort012(int *arr, int n)
{
    int i = 0;
    int count[3] = { 0, 0, 0 };

    //  Storing Count of 0s, 1s and 2s
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    i = 0;

    //  First filling 0
    while (count[0]--) {
        arr[i++] = 0;
    }

    //  Then filling 1
    while (count[1]--) {
        arr[i++] = 1;
    }

    // Then filling 2
    while (count[2]--) {
        arr[i++] = 2;
    }
}