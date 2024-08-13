// Copyright 2023 Jessica Vu
#pragma once
#include "FibLFSR.hpp"

namespace PhotoMagic {
// Transforms image using FibLFSR
void transform(sf::Image&, FibLFSR*);
// Display an encrypted copy of the picture, using the LFSR to do the encryption
}
