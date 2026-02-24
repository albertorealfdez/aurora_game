#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <string>
#include "tinyxml2.h"
#include "TileLayer.h"
#include "Tileset.h"
#include "ObjectLayer.h"
#include "MySprite.h"

using namespace std;
using namespace tinyxml2;

class TileMap {
    private:
        int tileWidth;
        int tileHeight;
        int width;
        int height;
        int collisionIndex;
        vector<Tileset> tilesets;
        vector<TileLayer> layers;
        vector<ObjectLayer> spwanLayers;
    
    public:
        bool loadFromFile(const string& path);
        void processTilesets(XMLElement* mapNode);
        void processLayers(XMLElement* mapNode);
        void processSpawns(XMLElement* mapNode);
        bool isCollision(Vector2 position);
        const ObjectLayer* getSpawnLayer() const;
        void render(Engine2D* engine2D, vector<int> zIndexes);
};

#endif /* TILEMAP_H */