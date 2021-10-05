#include<algorithm>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int>> hash;
    int n = start.size();
    for (int i = 0; i < n; i++) {
        hash.push_back({finish[i], start[i]});
    }
    sort(hash.begin(), hash.end());
    int cnt = 1, i = 1, curr = hash[0].first;
    while (i < n) {
        if (curr <= hash[i].second) {
            cnt++;
            curr = hash[i].first;
        }
        i++;
    }
    return cnt;
}