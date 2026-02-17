#include "TileLayer.h"
#include "MySprite.h"

void TileLayer::render(Engine2D* engine2D, const vector<Tileset>& tilesets) {
    MySprite sprite;

    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            int gid = tiles[y][x];

            if (gid > 0) {
                const Tileset* tileset = nullptr;

                for (const Tileset& ts: tilesets) {
                    if (ts.contains(gid)) {
                        tileset = &ts;
                    }
                }

                if (tileset) {
                    int localID = gid - tileset->firstGID;
                    int tileX = (localID % tileset->columns) * tileset->tileWidth;
                    int tileY = (localID / tileset->columns) * tileset->tileHeight;

                    sprite.setTexture(tileset->texture);
                    sprite.setTextureRect(tileX, tileY, tileset->tileWidth, tileset->tileHeight);
                    sprite.setPosition(x * tileset->tileWidth, y * tileset->tileHeight);

                    engine2D->drawSprite(sprite);
                }
            }
        }
    }
}
