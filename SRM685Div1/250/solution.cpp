#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

class MultiplicationTable2 {
public:
    int minimalGoodSet(vector<int> table) {
        // For each number i, i$i must be in th set.
        int m = table.size();
        int n = (int)sqrt((double)m);

        vector<int> arr;
        unordered_set<int> st;
        int res = n;

        for (int i = 0; i < n; i++) {
            arr.clear();
            st.clear();
            int lastpos = 0;
            st.insert(i);
            arr.push_back(i);

            // start from i to construct the set. 
            while (st.size() != lastpos) {
                int len = st.size();
                for (int j = lastpos; j < len; j++) {
                    for (int k = 0; k < len; k++) {
                        if (st.find(table[n * arr[j] + arr[k]]) == st.end()) {
                            st.insert(table[n * arr[j] + arr[k]]);
                            arr.push_back(table[n * arr[j] + arr[k]]);
                        }
                        if (st.find(table[n * arr[k] + arr[j]]) == st.end()) {
                            st.insert(table[n * arr[k] + arr[j]]);
                            arr.push_back(table[n * arr[k] + arr[j]]);
                        }
                    }
                }
                lastpos = len;
            }

            res = min(res, (int)st.size());
        }

        return res;
    }
};
