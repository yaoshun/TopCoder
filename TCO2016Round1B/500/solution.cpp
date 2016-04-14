#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;
vector<int> tags;
vector<int> digits;

int calc() {
    sort(digits.begin(), digits.end());
    int res = 0;
    // Change the smallest digit with the biggest tag.
    for (int digit : digits) {
        if (!tags.empty() && digit < tags.back()) {
            res += tags.back() - digit;
            tags.pop_back();
        } else {
            break;
        }
    }
    return res;
}

class ReplacingDigit {
public:
    // Length of A is between 1 and 50 with elments between 1 and 10^6.
    // Length of D is 9 elements and each element of D will be between 0
    // and 10^3.
    int getMaximumStockWorth(vector<int> A, vector<int> D) {
        // Using a greedy algorithm to get the best solution.
        tags.clear();
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < D[i - 1]; j++) {
                tags.push_back(i);
            }
        }

        int res = accumulate(A.begin(), A.end(), 0);
        int POW = 1000000;
        for (int len = 6; len >= 0; len--) {
            digits.clear();
            for (int a : A) {
                if (a >= POW) {
                    digits.push_back(a / POW % 10);
                }
            }
            int subRes = calc();
            res += subRes * POW;
            POW /= 10;
        }
        return res;
    }
};

int main() {
    ReplacingDigit test;
    // For vector we can directly use {1,2,3,4,5}
    cout << test.getMaximumStockWorth({9}, {1, 1, 1, 1, 1, 1, 1, 1, 0}) << endl;
    cout << test.getMaximumStockWorth({123456}, {9,8,7,6,5,4,3,2,1}) << endl;
    cout << test.getMaximumStockWorth({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {111, 111, 111, 111, 111, 111, 111, 111, 111}) << endl;
}

