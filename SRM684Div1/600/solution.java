import java.util.Arrays;

public class DivFree {
    public int mod = 1000000007;
    public int LOGK = 18;

    public int dfcount(int n, int k) {
        dp = new long[k + 1][LOGK];
        for (long[] x : dp) Arrays.fill(x, -1);

        long[][] ans = new long[n + 1][2];
        ans[0][0] = 1;

        for (int curpos = 1; curpos <= n; curpos++) {
            for (int parity = 0; parity < 2; parity++) {
                for (int numbad = 0; numbad < curpos && numbad < LOGK; numbad++) {
                    ans[curpos][parity] += ans[curpos - numbad - 1][(numbad + 2 - parity) & 1] * nways(k, numbad) % mod; 
                }
                ans[curpos][parity] %= mod;
            }
        }
        return (int)((ans[n][0] + mod - ans[n][1]) % mod);
    }

    public long[][] dp;

    public long nways(int cap, int left) {
        if (left == 0) return cap;
        if (dp[cap][left] != -1) return dp[cap][left];
        long ans = 0;
        for (int j = 2; j <= cap; j++) {
            ans += nways(cap / j, left - 1);
        }
        dp[cap][left] = ans % mod;
        return dp[cap][left];
    }
}
