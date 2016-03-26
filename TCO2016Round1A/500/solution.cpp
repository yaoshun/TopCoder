#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class EllysSocks {
public:
    int getDifference(vector<int> S, int P) {
        sort(S.begin(), S.end());
        vector<int> nums;
        for (int i = 1; i < S.size(); i++) {
            nums.push_back(S[i] - S[i - 1]);
        }
        int st = 0;
        int ed = 1000000000;
        while (st < ed) {
            int mid = st + (ed - st) / 2;
            int cnt = 0;
            int prev = false;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid && prev == false) {
                    cnt++;
                    prev = true;
                } else {
                    prev = false;
                }
            }
            if (cnt >= P) {
                ed = mid;
            } else {
                st = mid + 1;
            }
        }
        return ed;
    }
};
