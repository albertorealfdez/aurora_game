#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

using namespace std;

class Texture {
    public:
        virtual ~Texture() = default;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
        virtual bool loadFromFile(const string& path) = 0;
};

#endif /* TEXTURE_H */