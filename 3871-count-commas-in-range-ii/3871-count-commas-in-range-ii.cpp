class Solution {
public:
    long long countCommas(long long n) {
        return max(0LL,n-999) + max(0LL, n-999999) + max(0LL, n-999999999) + max(0LL,n-999999999999) + max(0LL, n-999999999999999);
    }
};