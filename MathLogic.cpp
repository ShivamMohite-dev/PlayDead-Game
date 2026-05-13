#include "MathLogic.h"
#include <cmath>
sf::Vector2f MathLogic::normalize(sf::Vector2f vector){   
    float mag = sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalize;
    if (mag != 0)
        return sf::Vector2f((vector.x / mag),(vector.y / mag));
    return sf::Vector2f(0,0);
}
bool MathLogic::checkCollision(sf::FloatRect rect1, sf::FloatRect rect2)
{
    if (rect1.left + rect1.width > rect2.left && rect2.left + rect1.width > rect1.left && rect2.top + rect2.height > rect1.top && rect1.top + rect1.height > rect2.top)
        return true;
    return false;
}