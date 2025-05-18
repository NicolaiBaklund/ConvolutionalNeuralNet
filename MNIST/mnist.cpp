#include <fstream>
#include <vector>
#include "matrix.h"

std::vector<Matrix> loadMNISTImages(const std::string& filename, bool invert = true) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) throw std::runtime_error("Cannot open file " + filename);

    uint32_t magic, numImages, numRows, numCols;

    file.read((char*)&magic, 4);
    file.read((char*)&numImages, 4);
    file.read((char*)&numRows, 4);
    file.read((char*)&numCols, 4);

    // MNIST is big-endian
    magic = __builtin_bswap32(magic);
    numImages = __builtin_bswap32(numImages);
    numRows = __builtin_bswap32(numRows);
    numCols = __builtin_bswap32(numCols);

    std::vector<Matrix> images;
    for (uint32_t i = 0; i < numImages; ++i) {
        Matrix img(numRows, numCols);
        for (uint32_t r = 0; r < numRows; ++r) {
            for (uint32_t c = 0; c < numCols; ++c) {
                unsigned char pixel;
                file.read((char*)&pixel, 1);
                double val = pixel / 255.0;
                if (invert) val = 1.0 - val;
                img.at(r, c) = val;
            }
        }
        images.push_back(img);
    }

    return images;
}

std::vector<Matrix> loadMNISTOneHotLabels(const std::string& filename, int numClasses = 10) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) throw std::runtime_error("Cannot open file " + filename);

    uint32_t magic, numLabels;
    file.read((char*)&magic, 4);
    file.read((char*)&numLabels, 4);

    magic = __builtin_bswap32(magic);
    numLabels = __builtin_bswap32(numLabels);

    std::vector<Matrix> oneHotLabels;
    for (uint32_t i = 0; i < numLabels; ++i) {
        unsigned char label;
        file.read((char*)&label, 1);

        Matrix encoded(numClasses, 1);
        encoded.at(label, 0) = 1.0;
        oneHotLabels.push_back(encoded);
    }

    return oneHotLabels;
}