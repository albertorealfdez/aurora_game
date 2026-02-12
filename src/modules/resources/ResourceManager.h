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
        void load(const string& id, const string& path) {
            if (!resources.count(id)) {
                T* resource = new T();
                if (resource->loadFromFile(path)) {
                    resources[id] = resource;
                } else {
                    cerr<<"Error loading resurce: "<<path<<endl;
                    delete resource;
                }
            }
        }

        T* get(const string& id) {
               if (resources.count(id)) {
                return resources[id];
            }
            return nullptr;
        }
};

#endif /* RESOURCE_MANAGER_H */