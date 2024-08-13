// Copyright 2023 Jessica Vu

#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"
using PhotoMagic::FibLFSR;

void PhotoMagic::transform(sf::Image& input_img, FibLFSR* input_seed) {
    // p is a pixelimage.getPixel(x, y);
    sf::Color p;
    sf::Vector2u img_size = input_img.getSize();
    // create photographic negative image of upper-left 200 px square
    for (unsigned int x = 0; x < img_size.x; x++) {
        for (unsigned int y = 0; y < img_size.y; y++) {
            // Generate a new integer to XOR for each pixel
            int new_redBit = (*input_seed).generate(8);
            int new_greenBit = (*input_seed).generate(8);
            int new_blueBit = (*input_seed).generate(8);
            // Do the XOR operation
            p = input_img.getPixel(x, y);
            p.r = p.r ^ new_redBit;
            p.g = p.g ^ new_greenBit;
            p.b = p.b ^ new_blueBit;
            input_img.setPixel(x, y, p);
        }
    }
}
