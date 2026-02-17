#ifndef TILESET_H
#define TILESET_H

#include <string>
#include "Texture.h"

using namespace std;

class Tileset {
    public:
        int firstGID;
        int tileWidth;
        int tileHeight;
        int columns;
        int rows;
        string path;
        Texture* texture;
    
        bool contains(int gid) const;
};

#endif /* TILESET_H */