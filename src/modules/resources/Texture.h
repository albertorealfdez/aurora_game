#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
    public:
        virtual ~Texture() = default;
        virtual int getWidth() const = 0;
        virtual int getHeight() const = 0;
};

#endif /* TEXTURE_H */