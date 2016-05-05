#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

// This is a wrong algorithm that if originally there are three
// airlines form a just-connected triangle.
// Removing any of the edges the graph still have connectivity.
// However, we cannot split it into two groups that are also fully
// connected.

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
    cout << test.isPossible(3, {0,0,1}, {1,2,2})<< endl;
}
