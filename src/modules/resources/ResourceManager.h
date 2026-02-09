#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <unordered_map>        
#include <SFML/Graphics/Texture.hpp>

using namespace std;

template <typename T>

class ResourceManager {
    private:
        unordered_map<string, T*> resources;
        string basePath;

    public:
        T* load(const string& name, const string& path) {
            if (resources.count(name)) {
                return resources[name];
            }
            T* resource = new T();
            if (resource->loadFromFile(path)) {
                resources[name] = resource;
                return resource;
            }
            return nullptr;

        }

        T* get(const string& name) {
               if (resources.count(name)) {
                return &resources[name];
            }
            return nullptr;
        }
};

#endif /* RESOURCE_MANAGER_H */