#include <string>
#include <vector>

using namespace std;

class TileLayer {
    public:
        string name;
        bool visible;
        int width;
        int height;
        vector<vector<int>> tiles;
};