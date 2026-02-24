#ifndef TILELAYER_H
#define TILELAYER_H

#include <string>
#include <vector>
#include "Tileset.h"
#include "Engine2D.h"

using namespace std;

class TileLayer {
    public:
        string name;
        bool visible;
        int width;
        int height;
        int zIndex;
        vector<vector<int>> tiles;

        void render(Engine2D* engine2D, const vector<Tileset>& tilesets);
};

#endif /* TILELAYER_H */