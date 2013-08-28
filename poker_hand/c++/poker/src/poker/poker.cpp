#include <iostream>
#include "poker.h"

namespace Poker {
    Face char_to_face(char c) {
        switch(c) {
            case '2': return Face::two;
            case '3': return Face::three;
            case '4': return Face::four;
            case '5': return Face::five;
            case '6': return Face::six;
            case '7': return Face::seven;
            case '8': return Face::eight;
            case '9': return Face::nine;
            case '0': return Face::ten;
            case 'J': return Face::jack;
            case 'Q': return Face::queen;
            case 'K': return Face::king;
            case 'A': return Face::ace;
            default: return Face::None;
        }
    }

    char face_to_char(Face f) {
        switch(f) {
            case Face::two: return '2';
            case Face::three: return '3';
            case Face::four: return '4';
            case Face::five: return '5';
            case Face::six: return '6';
            case Face::seven: return '7';
            case Face::eight: return '8';
            case Face::nine: return '9';
            case Face::ten: return '0';
            case Face::jack: return 'J';
            case Face::queen: return 'Q';
            case Face::king: return 'K';
            case Face::ace: return 'A';
            default: return ' ';
        }
    }

    void read_from_file(std::string file) {
        std::cout << "reading from: " << file << "\n";
    }
}
