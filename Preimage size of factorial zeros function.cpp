class Solution {
public:
    long long trailingZeroes(long long n) {
        long long count = 0;
        while (n > 0) {
            n /= 5;
            count += n;
        }
        return count;
    }

    long long find(long long k) {
        long long low = 0, high = 5LL * (k + 1);
        while (low < high) {
            long long mid = (low + high) / 2;
            if (trailingZeroes(mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int preimageSizeFZF(int k) {
        long long a = find(k);
        long long b = find(k + 1);
        return b - a;
    }
};