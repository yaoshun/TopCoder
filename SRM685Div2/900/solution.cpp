#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

// The problem is asking whether there is a spanning tree that has
// one third of red edges, green edges and blue edges.

class RGBTree {
public:
    bool isOn(int i, int x) {
        return (x >> i) & 1;
    }
    int onBit(int i, int x) {
        return x | (1 << i);
    }
    string exist(vector<string> G) {
        int n, k;

        // With 4D dp array, we don't need to use dfs recursively.
        // the first index indicate the used mask.
        // When n is small, this idea should automatically come into
        // the mind.
        bool f[10000][5][5][5];

        n = (int)G.size();
        // n is in the range of 4, 7, 10, 13.
        // k is between 1 to 4.
        k = (n - 1)/3;
        memset(f, false, sizeof(f));
        // with zero edges for three colors, we can cover a set of node with
        // the mast of the first index.
        f[1][0][0][0] = true;

        for (int ms = 1; ms < (1 << n); ms++) {
            for (int r = 0; r <= k; r++) {
                for (int g = 0; g <= k; g++) {
                    for (int b = 0; b <= k; b++) {
                        if (f[ms][r][g][b]) {
                            vector<int> p0, p1;
                            for (int i = 0; i < n; i++) {
                                if (isOn(i, ms)) {
                                    p1.push_back(i);
                                } else {
                                    p0.push_back(i);
                                }
                            }

                            // This is a good way to iterate through
                            // all the possible edges.
                            for (auto u : p1) {
                                for (auto v : p0) {
                                    if(G[u][v] == 'R' && r < k) {
                                        f[onBit(v, ms)][r + 1][g][b] = true;
                                    } else if(G[u][v] == 'G' && g < k) {
                                        f[onBit(v, ms)][r][g + 1][b] = true;
                                    } else if(G[u][v] == 'B' && b < k) {
                                        f[onBit(v, ms)][r][g][b + 1] = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (f[(1<<n) - 1][k][k][k]) {
            return "Exist";
        } else {
            return "Doest not exist";
        }
    }
};

int main() {
    RGBTree test;
    // For vector we can directly use {1,2,3,4,5}
    cout << test.exist({".RGB", "R...", "G...", "B..."}) << endl;
}
