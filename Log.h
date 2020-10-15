//
// Created by psifunction on 13.10.2020.
//

#ifndef ANIMATION_LOG_H
#define ANIMATION_LOG_H

extern const int meter;

#include <SFML/Graphics.hpp>

class Log : public sf::Sprite{
public:
    Log(const sf::Texture& texture, float x, bool nova = false) : sf::Sprite(texture) {
        sf::IntRect rect = this->getTextureRect();
        if (nova) {
            this->setOrigin(rect.width, rect.height/2);
            this->setScale(length*meter/rect.width/2, 1.f);

        }
        else {
            this->setOrigin(rect.width/2, rect.height/2);
            this->setScale(length * meter/rect.width, 1.f);

        }
        this->move(sf::Vector2f(x * meter , 150.f));
    }


    int getPos() {
        return this->getPosition().x;
    }

    float length = 6.2f;
    bool need_cut = true;
    sf::Time timer = sf::seconds(12.f);
};


#endif //ANIMATION_LOG_H
