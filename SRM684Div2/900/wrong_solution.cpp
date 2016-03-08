#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Autohamil {
private:
    vector<unordered_set<int>> adj;
    bool dfs(vector<bool>& visited, int& cnt, int cur) {
        if (cnt == visited.size()) {
            return true;
        } else if (visited[cur] == true) {
            return false;
        } else {
            visited[cur] = true;
            cnt++;
            for (auto x : adj[cur]) {
                if(dfs(visited, cnt, x)) {
                    cnt--;
                    visited[cur] = false;
                    return true;
                }
            }
            cnt--;
            visited[cur] = false;
            return false;
        }
    }
public:
    string check(vector<int>& z0, vector<int>& z1) {
        int n = z0.size();
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            adj[i].insert(z0[i]);
            adj[i].insert(z1[i]);
        }
        vector<bool> visited(n, false);
        int cnt = 0;
        if(dfs(visited, cnt, 0)) {
            return "Exists";
        } else {
            return "Does not exists";
        }
    }
};

