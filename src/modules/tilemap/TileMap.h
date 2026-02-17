#include <vector>
#include <string>
#include "tinyxml2.h"
#include "TileLayer.h"
#include "Tileset.h"

using namespace std;
using namespace tinyxml2;

class TileMap {
    private:
        int tileWidth;
        int tileHeight;
        int width;
        int height;
        vector<Tileset> tilesets;
        vector<TileLayer> layers;
    
    public:
        bool loadFromFile(const string& path);
        void processTilesets(XMLElement* mapNode);
        void processLayers(XMLElement* mapNode);
};