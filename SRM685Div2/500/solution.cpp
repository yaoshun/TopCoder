#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class DoubleWeights {
public:
    int minimalCost(vector<string> weight1, vector<string> weight2) {
        int n = weight1.size();
        
        // since each weight is below 10.
        // maximal 20 nodes and also result to be 200.
        int f[20][200];
        
        // The f array is tricky:
        // 1. The second dimension index represents the sum of weight in w1.
        // 2. The value represents the sum of weights in w2. 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 200; j++) {
                f[i][j] = 200;
            }
        }

        queue<pair<int, int>> q;
        f[0][0] = 0;
        q.push({0, 0});
        while (!q.empty()) {
            pair<int, int> a = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if (weight1[a.first][i] != '.') {
                    int w1 = weight1[a.first][i] - '0';
                    int w2 = weight2[a.first][i] - '0';

                    // Only when the equal w1 have lower w2, we replace the value to avoid unnecessary search.
                    if (f[a.first][a.second] + w2 < f[i][a.second + w1]) {
                        f[i][a.second + w1] = f[a.first][a.second] + w2;
                        q.push({i, a.second + w1});
                    }
                }
            }
        }

        // Here 1000000 only represent the maximal answer.
        int ans = 1000000;
        for (int j = 1; j < 200; j++) {
            if (f[1][j] < 200) {
                ans = min(ans, j * f[1][j]);
            }
        }

        if (ans == 1000000) {
            return -1;
        }
        return ans;
    }
};
