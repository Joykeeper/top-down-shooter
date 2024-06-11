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

    static bool objectsCollide(GameObject const& ob1, GameObject const& ob2){
        auto rect1 = ob1.getSize();
        auto rect2 = ob2.getSize();

        return (ob1.getPos().x-rect1.x/2 < ob2.getPos().x+rect2.x/2 &&
                ob1.getPos().x+rect1.x/2 > ob2.getPos().x-rect2.x/2 &&
                ob1.getPos().y+rect1.y/2 > ob2.getPos().y-rect2.y/2 &&
                ob1.getPos().y-rect1.y/2 < ob2.getPos().y+rect2.y/2 ) ;
    }

    static bool objectInRadius(GameObject const& ob, float radius, sf::Vector2f radiusCenter){
        auto rect = ob.getSize();

        auto obPos = ob.getPos();

        auto circleDistance = sf::Vector2f();

        circleDistance.x = abs(radiusCenter.x - obPos.x);
        circleDistance.y = abs(radiusCenter.y - obPos.y);

        if (circleDistance.x > (rect.x/2 + radius)) { return false; }
        if (circleDistance.y > (rect.y/2 + radius)) { return false; }

        if (circleDistance.x <= (rect.x/2)) { return true; }
        if (circleDistance.y <= (rect.y/2)) { return true; }

        float cornerDistance_sq = (circleDistance.x - rect.x/2)*(circleDistance.x - rect.x/2) +
                (circleDistance.y - rect.y/2)*(circleDistance.y - rect.y/2);

        return (cornerDistance_sq <= (radius*radius));
    }

    static bool isPointInRect(sf::Vector2f position, sf::Vector2f size, sf::Vector2f point){
        if ((point.x <= position.x + size.x/2.f && point.x >= position.x - size.x/2.f) &&
        (point.y <= position.y + size.y/2.f && point.y >= position.y - size.y/2.f)){
            return true;
        }
        return false;
    }
};

