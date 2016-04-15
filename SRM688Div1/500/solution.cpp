#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class ParenthesesDiv1Medium {
public:
    int minSwaps(string s, vector<int> L, vector<int> R) {
        vector<pair<int, int>> intervals;
        for (int i = 0; i < L.size(); i++) {
            intervals.push_back({L[i], R[i]});
        }
        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> temp;
        for (int i = 0; i < intervals.size(); i++) {
            if(temp.empty() || intervals[i].first >= temp.back().second) {
                temp.push_back(intervals[i]);
            } else {
                int val = temp.back().second;
                temp.back().second = intervals[i].first - 1;        
                intervals.push_back({intervals[i].first, val});
                intervals.push_back({val + 1, intervals[i].second});
            }
        }

        // Solve all the intervals.
        
    }
};

int main() {
    ParenthesesDiv1Medium test;
    // For vector we can directly use {1,2,3,4,5}
    cout << test.minSwaps() << endl;
}
