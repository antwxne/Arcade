/*
** EPITECH PROJECT, 2021
** pacman.hpp
** File description:
** pacman.hpp
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
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief pacman game class
 * @class Pacman
 * 
 */
class Pacman : public AGame {
public:
    /**
     * @brief Construct a new Pacman object
     * 
     */
    Pacman();
    /**
     * @brief Destroy the Pacman object
     * 
     */
    ~Pacman() override;
    /**
     * @brief move the player
     * 
     * @param dir direction to move
     */
    void move(arcade::events_e dir);
    /**
     * @brief play instructions
     * 
     * @return const std::vector<std::shared_ptr<IObject>> objects needed to be displayed
     */
    const std::vector<std::shared_ptr<IObject>> play(arcade::events_e) override;
    /**
     * @brief Get the Name object
     * 
     * @return const std::string& 
     */
    const std::string &getName() const override;
    /**
     * @brief check if the player has loose
     * 
     * @return true 
     * @return false 
     */
    bool isLost() override;

private:
    /**
     * @brief load the map
     * 
     */
    void loadMap();
    /**
     * @brief move player
     * 
     */
    void headMov();
    /**
     * @brief check if the player try to move into a wall
     * 
     * @param dir player's direction
     * @return true 
     * @return false 
     */
    bool collisionWall(arcade::events_e dir);
    /**
     * @brief init one object
     * 
     * @param is_static 
     * @param name 
     * @param drawables 
     * @param pos 
     * @return std::shared_ptr<arcade::IObject> new object
     */
    std::shared_ptr<arcade::IObject> init_object(bool is_static,
        const std::string &name,
        const std::vector<std::shared_ptr<arcade::IDrawable>> &drawables,
        std::pair<float, float> pos
    );
    /**
     * @brief init all objects
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
     * @brief upadate player's score
     * 
     * @return std::shared_ptr<arcade::IObject> score object
     */
    std::shared_ptr<arcade::IObject> updateScore();
    /**
     * @brief player eat a pacgum
     * 
     */
    void eatPacgum();
    /**
     * @brief move ai for ennemies
     * 
     */
    void enemiesMoves();
    /**
     * @brief move out the ennemies from the map's center
     * 
     */
    void enemiesGetOut();
    /**
     * @brief teleport players and ennemies when reach borders of the map
     * 
     */
    void checkTp();
    /**
     * @brief check player's stat
     * 
     */
    void checkStats();

private:
    /**
     * @brief player's direction to move
     * 
     */
    std::pair<float, float> _playerMov;
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
     * @brief game map
     * 
     */
    std::vector<std::string> _map;
    /**
     * @brief ennemies positions
     * 
     */
    std::vector<std::pair<float, float>> _enemies;
    /**
     * @brief ennemies direction to move
     * 
     */
    std::vector<std::pair<float, float>> _enemiesMov;
    /**
     * @brief objects needed to be displayer
     * 
     */
    std::vector<std::shared_ptr<arcade::IObject>> _objects;
    /**
     * @brief game started?
     * 
     */
    bool _started;
    /**
     * @brief consomable objects positions
     * 
     */
    std::vector<std::shared_ptr<arcade::IObject>> _comsomable;
    /**
     * @brief pacgum positions
     * 
     */
    std::vector<std::shared_ptr<arcade::IObject>> _special;
    /**
     * @brief players stats
     * 
     */
    bool _stats;
    /**
     * @brief slow ennemies
     * 
     */
    int _slow;
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
            {"O", 1, arcade::TEXT, arcade::BLUE}}}, {"stat",
        {{"./resources/enemi.png", 50, arcade::SPRITE, arcade::CYAN},
            {"Rect", 50, arcade::SHAPE, arcade::CYAN},
            {"O", 1, arcade::TEXT, arcade::CYAN}}}, {"apple",
        {{"./resources/apple.png", 50, arcade::SPRITE, arcade::NONE},
            {"Rect", 50, arcade::SHAPE, arcade::RED},
            {"A", 1, arcade::TEXT, arcade::RED}}}, {"ball",
        {{"./resources/ball.png", 50, arcade::SPRITE, arcade::NONE},
            {"Rect", 50, arcade::SHAPE, arcade::WHITE},
            {".", 1, arcade::TEXT, arcade::WHITE}}}, {"special",
        {{"./resources/special.png", 50, arcade::SPRITE, arcade::NONE},
            {"Rect", 50, arcade::SHAPE, arcade::MAGENTA},
            {"0", 1, arcade::TEXT, arcade::MAGENTA}}},};