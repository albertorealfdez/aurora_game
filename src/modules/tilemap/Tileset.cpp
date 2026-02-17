#include "Tileset.h"

bool Tileset::contains(int gid) const {
    return gid >= firstGID && gid < firstGID + (columns * rows);
}