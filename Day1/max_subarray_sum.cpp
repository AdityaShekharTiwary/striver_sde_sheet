/*
TC : O(N)
SC : O(1)
Approach : Kadane's Algo

*/


long long maxSubarraySum(int arr[], int n)
{
    long long int max_sum = -1e6 + 2, curr_sum = 0;
    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];
        if (curr_sum < 0) curr_sum = 0;
        max_sum = max(max_sum, curr_sum);
    }
    max_sum = max(curr_sum, max_sum);
    return max_sum;
}