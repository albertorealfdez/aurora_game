#include <string>
#include <vector>

using namespace std;

struct Animation {
    string textureName;
    vector<int> frames;
    float duration = 0.1f;
    int frameWidth;
    int frameHeight;
    int columns;
    bool loop = true;
    float footOffset = 10.f;
};