/*
TC : O(N)
SC : O(N)
Approach : Hashmap
*/

int findMajorityElement(int arr[], int n) {
    map<int, int> hash;
    for (int i = 0; i < n; i++) hash[arr[i]]++;
    for (auto it : hash) {
        if (it.second > n / 2) return it.first;
    }
    return -1;
}

/*
TC : O(N)
SC : O(1)
Approach :Moore Voting Algo
*/

int findMajorityElement(int arr[], int n) {
    int curr = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) curr = arr[i];
        if (curr == arr[i]) cnt++;
        else cnt--;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == curr) cnt++;
    }
    if (cnt > n / 2) return curr;
    else return -1;
}