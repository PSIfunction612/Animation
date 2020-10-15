//
// Created by psifunction on 13.10.2020.
//

#ifndef ANIMATION_GAME_H
#define ANIMATION_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Log.h"
#include "Line.h"

#include <vector>

class Game {
public:
    Game();
    void run();

private:
    void update(sf::Time deltaTime);
    void processEvents();
    void render();

    void drawBack();
    void createLog(float x, bool nova = false);

private:
    sf::RenderWindow mWindow;
    sf::Time TimePerFrame = sf::seconds(1.f/60.f);
    sf::Texture mLogTexture;
    sf::Font mFont;

    std::vector<Log> mLogs;
    Line line;
};


#endif //ANIMATION_GAME_H
