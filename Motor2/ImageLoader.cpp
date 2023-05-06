#include "ImageLoader.h"
#include "IDManager.h"
#include "Error.h"

GLTexture ImageLoader::loadPNG(string filePath)
{
    vector<unsigned char> in;
    vector<unsigned char> out;
    unsigned long width, height;

    if (!IDManager::readFiletoBuffer(filePath, in)) {
        fatalError("Could not read " + filePath);
    }
    return GLTexture();
}
