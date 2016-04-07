#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
// It is obviously that A[n] - 1 is still Fibonacci seq.
// Since A[n] - 1 = A[n - 1] - 1 + A[n - 2] - 1

class AlmostFibonacciKnapsack {
public:
    vector<int> (long long x) {
        vector<int> res;

        ll A[1000];
        A[1] = 2;
        A[2] = 3;
        int n = 2;
        for (; A[n] < x; n++) {
            A[n + 1] = A[n] + A[n - 1] - 1;
        }

        for (int i = n; i; i--) {
            // Greedily selecting the largest number to substract 
            // from x, it is the best choice since we haven't use the small numbers.
            // At the same time, we reduce the problem to a small one.
            if (A[i] <= x && A[i] != x - 1) {
                res.push_back(i);
                x -= A[i];
            }
        }
        if (x != 0) {
            return vector<int> {-1};
        }
        sort(res.begin(), res.end());
        return res;

    }
};
