#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H

#include <string>
#include <vector>
#include "Vector2.h"

using namespace std;

struct Object {
    string name;
    string type;
    Vector2 position;
};

struct ObjectLayer {
    string name;
    vector<Object> objects;
};

#endif /* OBJECTLAYER_H */
