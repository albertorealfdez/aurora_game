#include <string>
#include <vector>

using namespace std;

struct Animation {
    string name;
    vector<int> frames;
    int row;
    float duration;
    bool loop = true;
};