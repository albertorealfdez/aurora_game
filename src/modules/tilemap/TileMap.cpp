#include "TileMap.h"
#include <iostream>

bool TileMap::loadFromFile(const string& path) {
    bool loadSuccess = true;
    XMLDocument doc;
    XMLError docStatus = doc.LoadFile(path.c_str());

    if (docStatus == XML_SUCCESS) {
        XMLElement* mapNode = doc.FirstChildElement("map");

        if (mapNode) {
            mapNode->QueryIntAttribute("width", &width);
            mapNode->QueryIntAttribute("height", &height);
            mapNode->QueryIntAttribute("tilewidth", &tileWidth);
            mapNode->QueryIntAttribute("tileheight", &tileHeight);

            processTilesets(mapNode);
            processLayers(mapNode);
        } else {
            loadSuccess = false;
        }
    } else {
        cerr<<"Error loading tilemap tmx"<<endl;
        loadSuccess = false;
    }

    return loadSuccess;
}

void TileMap::processTilesets(XMLElement* mapNode) {
    XMLElement* tilesetNode;

    for (
        tilesetNode = mapNode->FirstChildElement("tileset");
        tilesetNode;
        tilesetNode = tilesetNode->NextSiblingElement("tileset")
    ) {
        Tileset tileset;

        tilesetNode->QueryIntAttribute("firstgid", &tileset.firstGID);
        tilesetNode->QueryIntAttribute("tilewidth", &tileset.tileWidth);
        tilesetNode->QueryIntAttribute("tileheight", &tileset.tileHeight);

        XMLElement* imgNode = tilesetNode->FirstChildElement("image");
        tileset.path = imgNode->Attribute("source");

        int imgWidht, imgHeight;

        tilesetNode->QueryIntAttribute("width", &imgWidht);
        tilesetNode->QueryIntAttribute("height", &imgHeight);

        tileset.columns = imgWidht / tileset.tileWidth;
        tileset.rows = imgHeight / tileset.tileHeight;

        tilesets.push_back(tileset);
    }
}

void TileMap::processLayers(XMLElement* mapNode) {
    XMLElement* layerNode;

    for (
        layerNode = mapNode->FirstChildElement("layer");
        layerNode;
        layerNode = layerNode->NextSiblingElement("layer")
    ) {
        TileLayer layer;

        layer.name = string(layerNode->Attribute("name"));
        layerNode->QueryIntAttribute("width", &layer.width);
        layerNode->QueryIntAttribute("height", &layer.height);

        layer.tiles.resize(layer.height, vector<int>(layer.width));

        XMLElement* data = layerNode->FirstChildElement("data");
        XMLElement* tileNode = data->FirstChildElement("tile");

        for (int y=0; y<layer.height; y++) {
            for (int x=0; x<layer.height; x++) {
                tileNode->QueryIntAttribute("gid", &layer.tiles[y][x]);
                tileNode = tileNode->NextSiblingElement("tile");
            }
        }
        layers.push_back(layer);
    }
}