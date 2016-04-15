#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

bool isValid(string& s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            count++;
        } else {
            count--;
        }   
        if (count < 0) {
            return false;
        }   
    }   
    return count == 0;
}

int score(string s) {
    int res = 0;
    int depth = 0;
    while(!s.empty()) {
        depth++;
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == '(' && s[i + 1] == ')') {
                res += depth * depth;
                s.erase(i, 2);
                i--;
            }
        }
    }
    return res;
}

class ParenthesesDiv1Hard {
public:
    int minCost(string s) {
        if (!isValid(s)) {
            return -1;
        }

        string a;
        string b;
        int deptha = 0;
        int depthb = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (deptha > depthb) {
                    depthb++;
                    b.push_back(s[i]);
                } else {
                    deptha++;
                    a.push_back(s[i]);
                }
            } else {
                if (deptha > depthb) {
                    deptha--;
                    a.push_back(s[i]);
                } else {
                    depthb--;
                    b.push_back(s[i]);
                }
            }
        }

        return score(a) + score(b);
    }
};

int main() {
    ParenthesesDiv1Hard test;
    // For vector we can directly use {1,2,3,4,5}
    cout << test.minCost("(())") << endl;
}
