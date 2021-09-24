int modularExponentiation(int x, int n, int m) {
    if (n < 0) return (1 / x % m * modularExponentiation(1 / x, -(n + 1), m)) % m;
    if (n == 0) return 1 % m;
    if (n == 2) return (x * x) % m;
    if (n % 2 == 0) return modularExponentiation( modularExponentiation(x, n / 2, m), 2, m) % m;
    else return x % m * modularExponentiation( modularExponentiation(x, n / 2, m), 2, m) % m;
}