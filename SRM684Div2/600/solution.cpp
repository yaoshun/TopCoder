#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

class DivFreed2 {
private:
    const ll P = 1000000007;
public:
    int count (int n, int k) {
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
        for (int i = 1; i <= k; i++) {
            dp[1][i] = 1;
        }
        
        for (int i = 2; i <= n; i++) {
            ll sum = 0;
            for (int j = 1; j <= k; j++) {
                sum += dp[i-1][j];
                sum %= P;
            }
            
            for (int j = 1; j <= k; j++) {
                dp[i][j] = sum;
                for (int m = 2 * j; m <= k; m += j) {
                    dp[i][j] = (dp[i][j] + P - dp[i - 1][m]) % P;
                }
            }
        }
        
        ll res = 0;
        for (int i = 1; i <= k; i++) {
            res += dp[n][i];
            res %= P;
        }
        return (int)res;
    }
};
