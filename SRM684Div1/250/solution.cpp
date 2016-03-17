#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CliqueParty {
public:
    int maxsize(vector<int> a, int k) {
        sort(a.begin(), a.end());
        
        int res = 1;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Only when we fixed the last number and the first number
                // we can know the maximum number in the set is a[j] - a[i].
                // then we can only check the neighbors didn't have a small gap to satisfy the
                // condition.
                int last = a[i];
                int dist = a[j] - a[i];
                int cnt = 2;
                for (int m = i + 1; m < j; m++) {
                    // This is a greedy selection algorithm.
                    if ((a[m] - last) * k >= dist && (a[j] - a[m]) * k >= dist) {
                        cnt++;
                        last = a[m];
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};
