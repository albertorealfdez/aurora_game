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


