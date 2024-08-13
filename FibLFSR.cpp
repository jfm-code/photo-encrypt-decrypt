// Copyright 2023 Jessica Vu

#include "FibLFSR.hpp"
using PhotoMagic::FibLFSR;

// Constructor to create LFSR with the given initial seed
FibLFSR::FibLFSR(std::string seed) {
    for (char c : seed)
        bits.push_back(c-'0');  // Convert from char to int
}

// Simulate one step and return the new bit as 0 or 1
int FibLFSR::step() {
    // XOR the new bit first (15th, 13th, 12th, 10th bits)
    int new_bit = bits[0] ^ bits[2] ^ bits[3] ^ bits[5];

    // Shift the bits to the left
    for (size_t i = 0; i < bits.size() - 1; i++) {
        bits[i] = bits[i + 1];
    }
    bits[15] = new_bit;

    // Return the new rightmost bit
    return new_bit;
}

// Simulate k steps and return an integer made from extracting the right most k-bits
int FibLFSR::generate(int k) {
    // Call the step() function k times
    for (int i = 0; i < k; i++)
        this->step();

    // Extracting k bits after calling step() function
    if (k > 15) {
        // Cannot extract more than 16 bits. Extracting 16 bits now...
        k = 15;
    }
    int result = 0;
    size_t limit = 15-k;
    for (size_t i = this->bits.size() - 1; i > limit; i--) {
        if (this->bits[i] == 1)
            result += pow(2, 15-i);
    }
    return result;
}

std::ostream& PhotoMagic::operator<<(std::ostream& out, FibLFSR& lfsr) {
    std::vector<int> outputVect = lfsr.getBits();
    std::string result;
    for (int n : outputVect) {
        result.push_back(n+'0');  // Convert from int to char
    }
    return out << result;
}
