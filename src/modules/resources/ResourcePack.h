#include "ResourceManager.h"
#include "SFMLTexture.h"
#include "SFMLFont.h"

struct ResourcePack {
    ResourceManager<SFMLTexture> textureManager;
    ResourceManager<SFMLFont> fontManager;
};
