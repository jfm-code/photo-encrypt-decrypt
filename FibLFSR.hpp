// Copyright 2023 Jessica Vu
#pragma once
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace PhotoMagic {
class FibLFSR {
 public:
    // Constructor to create LFSR with the given initial seed
    explicit FibLFSR(std::string seed);
    // Simulate one step and return the new bit as 0 or 1
    int step();
    // Simulate k steps and return a k-bit integer
    int generate(int k);
    // Accessor function
    std::vector<int> getBits() {
    return bits;
    }
 private:
    // Any fields that you need
    std::vector<int>bits;
};
    std::ostream& operator<<(std::ostream& out, FibLFSR& lfsr);

}  // namespace PhotoMagic
