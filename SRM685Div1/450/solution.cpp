#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class FoxAirline2 {
public:
    // biconnected compoenent in the graph.
    string isPossible(int n, vector<int> a, vector<int> b) {
        // Is it possbiel to split a and b to two set.
        // so that the result after the split is still connected.
        // If there is an critical edge, then we cannot split.

        // If it is a biconnected graph, we can split the graph
        // according to its two connected path.

        int m = a.size();

        bool res = true;
        for (int i = 0; i < m ;i ++) {
            // check delete an edge will make the graph disconnected.
            vector<vector<int>> adj(n);
            for (int j = 0; j < m; j++) {
                if (j != i) {
                    adj[a[j]].push_back(b[j]);
                    adj[b[j]].push_back(a[j]);
                }
            }

            // check whether it is still connected. 
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(0);
            visited[0] = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            for (int j = 0; j < n; j++) {
                if (visited[j] == false) {
                    res = false;
                    break;
                }
            }
            if (!res) {
                break;
            }
        }

        if (res) {
            return "Possible";
        } else {
            return "Impossible";
        }
    }
};

int main() {
    FoxAirline2 test;
    int n = 4;
    vector<int> a = {0,0,0,1,1,2};
    vector<int> b = {1,2,3,2,3,3};
    cout << test.isPossible(n,a,b)<< endl;
}
