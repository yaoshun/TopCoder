#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

class MultiplicationTable2Easy {
public:
    string isGoodSet(vector<int> table, vector<int> t) {
        int m = table.size();
        int n = (int)sqrt(double(m));
        unordered_set<int> st;
        for (auto ele : t) {
            st.insert(ele);
        }

        for (int i = 0; i < t.size(); i++) {
            for (int j = i; j < t.size(); j++) {
                if (st.find(table[t[i] * n + t[j]]) == st.end()) {
                    return "Not Good";
                }
                if (st.find(table[t[j] * n + t[i]]) == st.end()) {
                    return "Not Good";
                }
            }
        }
        return "Good";
    }
};
