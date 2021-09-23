/*
TC : O(N)
SC : O(N)
Approach : Storing the max value from
right
*/


#include<bits/stdc++.h>
int maximumProfit(vector<int> &prices) {
    vector<int> max_sp;
    int curr_max = -1e8;
    for (int i = prices.size() - 1; i >= 0; i--) {
        curr_max = max(curr_max, prices[i]);
        max_sp.push_back(curr_max);
    }
    reverse(max_sp.begin(), max_sp.end());
    int ans = INT_MIN;
    for (int i = 0; i < prices.size(); i++) {
        ans = max(ans, abs(prices[i] - max_sp[i]));
    }
    return ans == 0 ? 0 : ans;
}

/*
TC : O(N)
SC : O(1)
Approach : taking current min and max Profit


*/


int maximumProfit(vector<int> &prices) {
    int curr_min = INT_MAX;
    int profit = 0;
    for (int i = 0; i < prices.size(); i++) {
        curr_min = min(prices[i], curr_min);
        if (prices[i] > curr_min) {
            profit = max(profit, prices[i] - curr_min);
        }
    }
    return profit == 0 ? 0 : profit;
}