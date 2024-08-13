// Copyright 2023 Jessica Vu

#include <iostream>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

using PhotoMagic::FibLFSR;

int main(int argc, char* argv[]) {
    // The first argument in the command line should be the input file name
    sf::Image image;
    if (!image.loadFromFile(argv[1]))
        return -1;
    // The third argument in the command line is the seed
    std::string input_seed = argv[3];
    FibLFSR str(input_seed);
    FibLFSR* seed = &str;

    // The texture of the image before encrypted
    sf::Texture texture1;
    texture1.loadFromImage(image);
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);

    // Call transform() function to encrypt image
    transform(image, seed);

    // The texture of the image after encrypted
    sf::Texture texture2;
    texture2.loadFromImage(image);
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);

    sf::Vector2u size = image.getSize();
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Source Image");
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encrypted Image");

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window1.close();
        }

        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window2.close();
        }

        // Display the original picture
        window1.clear();
        window1.draw(sprite1);
        window1.display();

        // Display the encrypted picture
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }

    if (!image.saveToFile(argv[2]))
        return -1;

    return 0;
}
