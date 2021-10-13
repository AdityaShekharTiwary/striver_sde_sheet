double multiply(double mid, int n) {
    double ans = 1.0;
    for (int i = 1; i <= n; i++) ans *= mid;
    return ans;
}

double findNthRootOfM(int n, long long m) {
    double low = 1, high = m;
    double eps = 1e-7;
    while ((high - low) > eps) {
        double mid = (high + low) / 2.0;
        if (multiply(mid, n) < m) low = mid;
        else high = mid;
    }
    return low;
}
