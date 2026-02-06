#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <string>
#include <unordered_map>        
#include <SFML/Graphics/Texture.hpp>

using namespace std;

class TextureManager {
    private:
        unordered_map<string, sf::Texture> textures;
        string basePath;

    public:
        void load(const string& name, const string& filename);
        sf::Texture* get(const string& name);
};

#endif /* TEXTURE_MANAGER_H */