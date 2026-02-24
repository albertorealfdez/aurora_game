#include <iostream>
#include <algorithm>
#include "TileMap.h"
#include "SFMLTexture.h"

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
        tileset.texture = new SFMLTexture();
        tileset.texture->loadFromFile(tileset.path);
        int imgWidht, imgHeight;

        imgNode->QueryIntAttribute("width", &imgWidht);
        imgNode->QueryIntAttribute("height", &imgHeight);

        tileset.columns = imgWidht / tileset.tileWidth;
        tileset.rows = imgHeight / tileset.tileHeight;
        
        tilesets.push_back(tileset);
    }
}

void TileMap::processLayers(XMLElement* mapNode) {
    XMLElement* layerNode;
    int index = 0;
    collisionIndex = 1; // TODO: change from tmx

    for (
        layerNode = mapNode->FirstChildElement("layer");
        layerNode;
        layerNode = layerNode->NextSiblingElement("layer")
    ) {
        TileLayer layer;

        layer.zIndex = index; // TODO: change from tmx
        layer.visible = true; // TODO: change from tmx
        layer.name = string(layerNode->Attribute("name"));
        layerNode->QueryIntAttribute("width", &layer.width);
        layerNode->QueryIntAttribute("height", &layer.height);

        layer.tiles.resize(layer.height, vector<int>(layer.width));

        XMLElement* data = layerNode->FirstChildElement("data");
        XMLElement* tileNode = data->FirstChildElement("tile");

        for (int y=0; y<layer.height; y++) {
            for (int x=0; x<layer.width; x++) {
                tileNode->QueryIntAttribute("gid", &layer.tiles[y][x]);
                tileNode = tileNode->NextSiblingElement("tile");
            }
        }
        layers.push_back(layer);
        index++;
    }
}

void TileMap::processSpawns(XMLElement* mapNode) {
    XMLElement* layerNode;

    for (
        layerNode = mapNode->FirstChildElement("objectgroup");
        layerNode;
        layerNode = layerNode->NextSiblingElement("objectgroup")
    ) {
        ObjectLayer layer;
        XMLElement* objectNode;

        for (
            objectNode = layerNode->FirstChildElement("object");
            objectNode;
            objectNode = objectNode->NextSiblingElement("object")
        ) {
            Object object; 
            object.name = string(objectNode->Attribute("name"));
            object.type = string(objectNode->Attribute("type"));
            
            Vector2 objectPos;
            objectNode->QueryFloatAttribute("x", &objectPos.x);
            objectNode->QueryFloatAttribute("y", &objectPos.y);
            object.position = objectPos;

            layer.objects.push_back(object);
        }
    spwanLayers.push_back(layer);
    }
}

bool TileMap::isCollision(Vector2 position) {
    int tileX = position.x  / tileWidth;
    int tileY = position.y / tileHeight;

    int collisionGID = layers[collisionIndex].tiles[tileY][tileX];

    return collisionGID != 0;
}

const ObjectLayer* TileMap::getSpawnLayer() const {
    for (const ObjectLayer& layer: spwanLayers) {
        if (layer.name == "Spawns") {
            return &layer;
        }
    }
    return nullptr;
}


void TileMap::render(Engine2D* engine2D, vector<int> zIndexes) {
    for (TileLayer& layer: layers) {
        if (layer.visible && find(zIndexes.begin(), zIndexes.end(), layer.zIndex) != zIndexes.end()) {
            layer.render(engine2D, tilesets);
        }
    }
}