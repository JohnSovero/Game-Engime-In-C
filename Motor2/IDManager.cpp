#include "IDManager.h"
#include <fstream>

bool IDManager::readFiletoBuffer(string filePath, vector<unsigned char>& buffer)
{   
    //leer el archivo, ver cuanto pesa, lo que pesa se setea todo a un vector unsigned char los bytes a convertir
    //leer la imagen, la imagen se vuelve bytes, los bytes se vuelve a imagen y luego a textura
    ifstream file(filePath, ios::binary);
    if (file.fail()) {
        return false;
    }
    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    file.seekg(0, ios::beg);
    fileSize -= file.tellg();
    buffer.resize(fileSize);
    file.read((char*)&(buffer[0]), fileSize);
    file.read();
    return false;
}
