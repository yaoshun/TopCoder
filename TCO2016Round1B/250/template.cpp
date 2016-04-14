#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

vector<bool> primes(100001, true);

void preprocessing() {
    primes[0] = false;
    primes[1] = false;
    for (int i = 0; i * i <= 100000; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= 100000; j += i) {
                primes[j] = false;
            }
        }
    }
}

// The size of n is 10^9. 
// Therefore we only need to have the primes before 10^5.
bool isPrime(int n) {
    if (n <= 100000) {
        return primes[n];
    } else {
        for (int i = 2; i <= 100000; i++) {
            if (primes[i] && n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int nextEle(int n) {
    int res = 0;
    while (n) {
        res += (n%10) * (n%10);
        n /= 10;
    }
    return res;
}

class ExploringNumbers {
public:
    int numberOfSteps(int n) {
        preprocessing();

        unordered_set<int> st;
        int cur = n;
        st.insert(cur);
        int res = 1;
        while (n--) {
            if (isPrime(cur)) {
                return res;
            } else {
                cur = nextEle(cur);
                if (st.find(cur) != st.end()) {
                    return -1;
                } else {
                    st.insert(cur);
                }
                res++;
            }
        }
        return -1;
    }
};

int main() {
    ExploringNumbers test;
    // For vector we can directly use {1,2,3,4,5}
    cout << test.numberOfSteps(5) << endl;
    cout << test.numberOfSteps(1) << endl;
    cout << test.numberOfSteps(6498501) << endl;
}
