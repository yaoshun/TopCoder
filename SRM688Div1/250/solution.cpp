#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

char temp[1001];

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

char flip(char a) {
    if (a == '(') {
        return ')';
    } else {
        return '(';
    }
}

class ParenthesesDiv1Easy {
private:
    bool dfs(string &s, int steps, vector<int>& res) {
        if (isValid(s)) {
            return true;
        }
        if (steps == 10) {
            return false;
        }
        
        for (int L = 0; L < s.size(); L++) {
            for (int R = L; R < s.size(); R++) {
                for (int i = L; i <= R; i++) {
                    temp[i] = flip(s[L + R - i]);
                }
                for (int i = L; i <= R; i++) {
                    s[i] = temp[i];
                }
                res.push_back(L);
                res.push_back(R);
                if(dfs(s, steps + 1, res)) {
                    return true;
                }
                res.pop_back();
                res.pop_back();
                for (int i = L; i <= R; i++) {
                    temp[i] = flip(s[L + R - i]);
                }
                for (int i = L; i <= R; i++) {
                    s[i] = temp[i];
                }
            }
        }
        return false;
    }
    
public:
    vector<int> correct(string s) {
        int n = s.size();
        vector<int> res;
        if (n % 2 == 1) {
            res.push_back(-1);
            return res;
        }
        
        if (dfs(s, 0, res)) {
            return res;
        } else {
            res.clear();
            res.push_back(-1);
            return res;
        }
    }
};

// Brute force method:
// 10 times 1000 * 1000 * 1000
// magic flip is just mirror left and right a subsequence of it.
// 2^10 > 1000, means there might be a universal method, but divide and conquer would not work easily.
int main() {
    ParenthesesDiv1Easy test;
    // For vector we can directly use {1,2,3,4,5}
    cout << test.correct(string(")("))[0] << endl;
}
