#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;

class BracketSequenceDiv1 {
public:
    long long count(string s) {
        int n = s.size();
        vector<vector<ll>> dp(n, vector<ll>(n,0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i > 0) {
                dp[i][i - 1] = 1;
            }
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j + i < n; j++) {
                // case of delete s[j];
                dp[j][j+i] += dp[j][j+i-1];
                
                // case of keep s[j]
                if (s[j+i] == ')') {
                    if (s[j] == '(') {
                        dp[j][j+i] += dp[j + 1][j+i-1];
                    }
                    for (int k = j + 1; k < j+i; k++) {
                        if (s[k] == '(') {
                            dp[j][j+i] += dp[j][k - 1] * dp[k + 1][j+i-1];
                        }
                    }
                }
                
                // case of keep s[j]
                if (s[j+i] == ']') {
                    if (s[j] == '[') {
                        dp[j][j+i] += dp[j + 1][j+i-1];
                    }
                    for (int k = j + 1; k < j+i; k++) {
                        if (s[k] == '[') {
                            dp[j][j+i] += dp[j][k - 1] * dp[k + 1][j+i-1];
                        }
                    }
                }
            }
        }
        
        return dp[0][n - 1] - 1;
    }
};
