#include "SFML/Graphics.hpp"
#include <cmath>

class Utils {
public:
    static sf::Vector2f normalizeVector(sf::Vector2f vec) {
        if (sqrt(vec.x * vec.x + vec.y * vec.y) != 0) {
            vec /= (float) sqrt(vec.x * vec.x + vec.y * vec.y);
        }
        return vec;
    };
};

