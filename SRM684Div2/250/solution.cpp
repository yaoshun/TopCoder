nclude <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Istr {
public:
    int count(string s, int k) {
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        for (char&c : s) {
            mp[c]++;
        }
        for (auto pair : mp) {
            pq.push(pair.second);
        }
        while (k--) {
            int tmp = pq.top();
            pq.pop();
            tmp--;
            if (tmp > 0)
                pq.push(tmp);
        }
        
        int res = 0;
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            res += x * x;
        }
        return res;
    }
};
