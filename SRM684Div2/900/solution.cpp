#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Autohamil {
public:
    string check(vector<int>& z0, vector<int>& z1) {
        int n = z0.size();
        vector<vector<bool>> conn(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            conn[i][i] = true;
        }

        for (int i = 0; i < n; i++) {
            conn[i][z0[i]] = true;
            conn[i][z1[i]] = true;
        }

        // This is Floyd graph algorithm to find the all-pairs shortest path.
        // O(n^3) complexity to get the connection graph.
        // it works, since we iterates through the connection in the outside.
        // after k = 0, all the connected parts that utilized k now didn't need zero any more.
        // Think from another perspective:
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    conn[i][j] = conn[i][j] || (conn[i][k] && conn[k][j]);
                }
            }
        }

        // since we are starting from 0.
        for (int i = 0; i < n; i++) {
            if (!conn[0][i]) {
                return "Does not exist";
            }
        }

        // 0 can reach i, 0 can reach j, but i cannot reach j(i cannot reach 0).
        // and j cannot reach i (j cannot reach back to 0)
        // which means both can never go back.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((!conn[i][j]) && (!conn[j][i])) {
                    return "Does not exist";
                }
            }
        }

        return "Exists";
    }
};

