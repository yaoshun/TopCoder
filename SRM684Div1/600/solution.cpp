#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class DivFree {
private:
    const ll P = 1000000007;
public:
    int dfcount(int n, int k) {
        // This is the cnt with a single element.
        vector<ll> count(k + 1, 1);
        count[0] = k;

        // We calculate one more cycle to make count[0]
        // to be the sum therefore the results.
        for (int i = 1; i <= n; i++) {
            ll sum = 0;
            for (int j = 1; j <= k; j++) {
                sum += count[j];
                sum %= P;
            }
            
            vector<ll> nxt(k + 1, sum);
            for (int j = 1; j <= k; j++) {
                for (int m = 2 * j; m <= k; m += j) {
                    nxt[j] -= count[m];
                    nxt[j] = (nxt[j] + P) % P;
                }
            }
            count = nxt;
        }
        return (int)count[0];
    }
};
