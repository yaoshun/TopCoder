import java.util.Arrays;

public class Permutant {
    public int mod = 1000000007;
    public int counthis(int[] a) {
        int n = a.length;
        int m = 0;

        // m is all the possible prefix sum values
        // that should be considered.
        for (int x : a) m += x;

        // Calculate the combinations.
        long[][] comb = new long[m + 1][m + 1];
        comb[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
            }
        }

        // Calculate the factorials.
        long[] fact = new long[m + 1];
        fact[0] = 1;
        for (int i = 1; i <= m; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }

        // Calculate the results.
        long ret = 0;
        for (int last = 0; last < n; last++) {
            // What does dp array stores here.
            long[] dp = new long[m + 1];
            dp[a[last] - 1] = fact[a[last]];
            int cursum = a[last] - 1;
            for (int i = 0; i < n; i++) {
                if (last == i) continue;
                long[] next = new long[m + 1];
                for (int left = 1; left <= a[i]; left++) {
                    int right = a[i] - left;
                    for (int curright = 0; curright <= cursum && curright + right <= m; curright++) {
                        int curleft = cursum - curright;
                        long y = fact[a[i]-1] * comb[curleft+left][left] % mod * comb[curright+right][right] % mod;
                        next[curright+right] = (next[curright+right] + dp[curright] * y) % mod;
                    }
                }
                dp = next;
                cursum += a[i];
            }

            for (int i = 0; i <= m; i++) {
                ret = (ret + dp[i]) % mod;
            }
        }
        return (int)ret;
    }
}
