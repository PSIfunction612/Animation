//
// Created by psifunction on 13.10.2020.
//

#include "Game.h"
#include <iostream>
#include <string>
#include <sstream>

const int meter = 50;

Game::Game() :mWindow(sf::VideoMode(1920, 300), "LogAnim")
{
    if (!mFont.loadFromFile("arial.ttf"))
    {
        std::cerr << "Error while loading font" << std::endl;
    }

    if (!mLogTexture.loadFromFile("./brevno.png"))
    {
        std::cerr << "Error while load image" << std::endl;
    }
    createLog(line.coords[0] / meter + line.lengths[0]/2);

    mWindow.setVerticalSyncEnabled(true);
}

void Game::run() {
    sf::Clock clock;
    sf::Clock generator;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen()){
        timeSinceLastUpdate += clock.restart();
        if (generator.getElapsedTime().asSeconds() >= 30.f){
            createLog(line.coords[0] /meter + line.lengths[0]/2);
            generator.restart();
        }

        while( timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event)){
        switch (event.type){
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time deltaTime){
    for (auto iter = mLogs.begin(); iter < mLogs.end(); iter++){
       if (iter->getPos() > 2000) {
            mLogs.erase(iter);
       }

       if (iter->getPos() >= line.coords.at(line.coords.size() - 1) && iter->timer > sf::Time::Zero){
           iter->timer -= deltaTime;
           continue;
       }

        if (iter->need_cut && iter->timer <= sf::Time::Zero) {
            createLog(iter->getPos()/meter + 0.3f, true);
            mLogs[mLogs.size()-1].timer = sf::seconds(2);
            mLogs[mLogs.size()-1].need_cut = false;

            iter->need_cut = false;
            iter->move((iter->length -0.3f)* meter/4, 0);
            iter->setScale(iter->getScale().x*0.5f, 1.f);
            continue;
        }

        sf::Vector2f movement(0.f, 0.f);
        movement.x += line.getLogSpeed(iter->getPos()) / 60.f * meter;
        iter->move(movement * deltaTime.asSeconds() );
    }
}

void Game::render() {
    mWindow.clear();
    drawBack();
    for(auto log: mLogs){
        mWindow.draw(log);
    }
    mWindow.display();
}

void Game::createLog(float x, bool nova){
    mLogs.push_back(Log(mLogTexture, x, nova));
}

void Game::drawBack() {
    std::stringstream ss;
    for (int i = 0; i < line.getElemCount(); ++i){
        sf::Text text;
        text.setCharacterSize(24);
        text.setFont(mFont);
        text.setFillColor(sf::Color::Cyan);
        ss << line.names[i] << " ( " << line.speeds[i] << "m/s )";
        text.setString(ss.str());
        ss.str("");
        text.move(line.coords[i], 10);
        mWindow.draw(text);

        sf::Text text1;
        text1.setFont(mFont);
        text1.setCharacterSize(24);
        text1.setFillColor(sf::Color::Yellow);
        ss << line.lengths[i] << " m";
        text1.setString(ss.str());
        ss.str("");
        text1.move(line.coords[i] + meter*line.lengths[i]/2 - 30, 250);
        sf::RectangleShape rect(sf::Vector2f( line.lengths[i] * meter, 200.f));
        rect.move(line.coords[i], 50);

        mWindow.draw(rect);
        mWindow.draw(text1);
    }
}