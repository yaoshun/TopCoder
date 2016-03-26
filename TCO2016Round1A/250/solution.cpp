#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class EllysTimeMachine {
public:
    string getTime(string time) {
        string hour = time.substr(0, 2);
        string min = time.substr(3, 2);
        int reshour = stoi(min) / 5;
        int resmin = stoi(hour) * 5;
        if (reshour == 0) {
            reshour = 12;
        }
        if (resmin == 60) {
            resmin = 0;
        }
        return string(reshour < 10?"0":"") + to_string(reshour) + ":" + (resmin<10?"0":"") + to_string(resmin);
    }
};

