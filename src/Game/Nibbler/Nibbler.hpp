/*
** EPITECH PROJECT, 2021
** nibbler.hpp.h
** File description:
** nibbler.hpp.h
*/

#pragma once

#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <utility>
#include <iostream>
#include <functional>

#include "AGame.hpp"
#include "IGame.hpp"
#include "Object/IObject.hpp"
#include "Graphic/Drawable.hpp"
#include "Object/StaticObject.hpp"
#include "Object/MovableObject.hpp"
/**
 * @brief arcade objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief nibbler game class
 * @class Nibbler
 * 
 */
class Nibbler : public AGame {
public:
    /**
     * @brief Construct a new Nibbler object
     * 
     */
    Nibbler();
    /**
     * @brief Destroy the Nibbler object
     * 
     */
    ~Nibbler() override;

    /**
     * @brief generate Apple in map
     * 
     */
    void AppleGenerator();
    /**
     * @brief update the snake
     * 
     */
    void updateSnake();
    /**
     * @brief move the snake
     * 
     * @param dir direction to move
     */
    void move(arcade::events_e dir);
    /**
     * @brief game instructions
     * 
     * @return const std::vector<std::shared_ptr<IObject>> all objects needed to be displayed
     */
    const std::vector<std::shared_ptr<IObject>> play(arcade::events_e) override;
    /**
     * @brief Get the Name object
     * 
     * @return const std::string& 
     */
    const std::string &getName() const override;
    /**
     * @brief is the game lost
     * 
     * @return true 
     * @return false 
     */
    bool isLost() override;

private:
    /**
     * @brief load map from file
     * 
     */
    void loadMap();
    /**
     * @brief move snake's head
     * 
     */
    void headMov();
    /**
     * @brief check if the snake try to move into a wall
     * 
     * @param dir 
     * @return true 
     * @return false 
     */
    bool collisionWall(arcade::events_e dir);
    /**
     * @brief place object on map
     * 
     * @param is_static  
     * @param name 
     * @param drawables 
     * @param pos 
     * @return std::shared_ptr<arcade::IObject> 
     */
    std::shared_ptr<arcade::IObject> init_object(bool is_static,
        const std::string &name,
        const std::vector<std::shared_ptr<arcade::IDrawable>> &drawables,
        std::pair<float, float> pos
    );
    /**
     * @brief init all objects on the map
     * 
     */
    void init_all_object();
    /**
     * @brief Create a Drawable Vector object
     * 
     * @param name 
     * @return std::vector<std::shared_ptr<arcade::IDrawable>> 
     */
    std::vector<std::shared_ptr<arcade::IDrawable>> createDrawableVector(
        const std::string &name
    ) const;
    /**
     * @brief check if the snake hit an apple
     * 
     */
    void eatApple();
    /**
     * @brief update the player score
     * 
     * @return std::shared_ptr<arcade::IObject> score object
     */
    std::shared_ptr<arcade::IObject> updateScore();

private:
    /**
     * @brief apple's position
     * 
     */
    std::pair<float, float> _applePosition;
    /**
     * @brief vector for direction move
     * 
     */
    std::pair<int, int> _playerMov;
    /**
     * @brief player's score
     * 
     */
    unsigned long int _score;
    /**
     * @brief player's name
     * 
     */
    std::string _name;
    /**
     * @brief map
     * 
     */
    std::vector<std::string> _map;
    /**
     * @brief enemies positions
     * 
     */
    std::vector<std::pair<float, float>> _enemies;
    /**
     * @brief objects to be displayed
     * 
     */
    std::vector<std::shared_ptr<arcade::IObject>> _objects;
    /**
     * @brief apple on map?
     * 
     */
    bool _isApple;
    /**
     * @brief game started?
     * 
     */
    bool _started;
};
}

static const std::map<std::string, std::vector<arcade::Drawable>> DRAWABLE_LIST = {
    {"Wall", {{"./resources/wall.jpeg", 50, arcade::SPRITE, arcade::NONE},
        {"Rect", 50, arcade::SHAPE, arcade::YELLOW},
        {"#", 1, arcade::TEXT, arcade::YELLOW}}}, {"player",
        {{"./resources/player.png", 50, arcade::SPRITE, arcade::NONE},
            {"Rect", 50, arcade::SHAPE, arcade::GREEN},
            {"X", 1, arcade::TEXT, arcade::GREEN}}}, {"enemie",
        {{"./resources/enemi.png", 50, arcade::SPRITE, arcade::NONE},
            {"Rect", 50, arcade::SHAPE, arcade::BLUE},
            {"O", 1, arcade::TEXT, arcade::BLUE}}}, {"apple",
        {{"./resources/apple.png", 50, arcade::SPRITE, arcade::NONE},
            {"Rect", 50, arcade::SHAPE, arcade::RED},
            {"A", 1, arcade::TEXT, arcade::RED}}},};