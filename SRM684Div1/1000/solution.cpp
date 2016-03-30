#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
const ll P = 1000000007;

class Permutant {
public:
    int counthis(vector<int> a) {
        int n = a.size();
        int m = 0;

        for (int x : a) {
            m += x;
        }

        // Calculate the combinations.
        vector<vector<ll>> comb(m + 1, vector<ll>(m + 1, 0));
        comb[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % P;
            }
        }

        // Calculate the factorials.
        vector<ll> fact(m + 1, 0);
        fact[0] = 1;
        for (int i = 1; i <= m; i++) {
            fact[i] = fact[i - 1] * i % P;
        }

        ll ret = 0;
        for (int last = 0; last < n; last++) {
            vector<ll> dp(m + 1, 0);
            dp[a[last] - 1] = fact[a[last]];

            int cursum = a[last] - 1;
            for (int i = 0; i < n; i++) {
                if (last == i) continue;
                vector<ll> next(m + 1, 0);
                for (int left = 1; left <= a[i]; left++) {
                    int right = a[i] - left;
                    for (int curright = 0; curright <= cursum && curright + right <= m; curright++) {
                        int curleft = cursum - curright;
                        ll y = fact[a[i]-1] * comb[curleft+left][left] % P * comb[curright+right][right] % P; 
                        next[curright+right] = (next[curright+right] + dp[curright] * y) % P;
                    }
                }
                dp = next;
                cursum += a[i];
            }

            for (int i = 0; i <= m; i++) {
                ret = (ret + dp[i]) % P;
            }
        }

        return (int)ret;
    }
};
