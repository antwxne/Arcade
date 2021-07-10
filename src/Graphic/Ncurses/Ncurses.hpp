/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo
*/

#pragma once

#include <memory>
#include <ncurses.h>
#include <vector>
#include <map>
#include "ADisplayModule.hpp"

/**
 * @brief arcade's objects
 * @namespace arcade 
 * 
 */
namespace arcade {
/**
 * @brief ncurses encapsulation
 * @class Ncurses
 * 
 */
class Ncurses : public arcade::ADisplayModule {
public:
    /**
     * @brief Construct a new Ncurses object
     * 
     */
    Ncurses();
    /**
     * @brief Destroy the Ncurses object
     * 
     */
    ~Ncurses() override;
    /**
     * @brief init a window in ncurses
     * 
     */
    void init() override;
    /**
     * @brief destroy a window
     * 
     */
    void destroy() override;
    /**
     * @brief clear a window
     * 
     */
    void clearWin() override;
    /**
     * @brief refresh window
     * 
     */
    void refreshWin() override;
    /**
     * @brief draw objects
     * 
     * @param drawable 
     * @param position 
     * @param name 
     */
    void draw(std::vector<std::shared_ptr<IDrawable>> drawable,
        std::pair<int, int> position, const std::string &name
    ) override;
    /**
     * @brief manage events
     * 
     * @return events_e 
     */
    events_e pollEvent() override;
    /**
     * @brief load textures
     * 
     * @param drawable 
     * @param name 
     */
    void load(std::vector<std::shared_ptr<IDrawable>> drawable,
        const std::string &name
    ) override;
    /**
     * @brief Get the Form object
     * 
     * @param str 
     * @return std::string 
     */
    std::string getForm(std::string str) override;
    /**
     * @brief draw text in screen
     * 
     * @param string 
     * @param position 
     */
    void drawText(const std::string &string, std::pair<int, int> position
    ) override;

private:
    /**
     * @brief x size
     * 
     */
    int _screen_x;
    /**
     * @brief y size
     * 
     */
    int _screen_y;
    /**
     * @brief map
     * 
     */
    std::string map;
    /**
     * @brief all sprites
     * 
     */
    std::map<std::string, char> _sprites;
};
}

static const std::vector<std::pair<int, arcade::events_e>> KEYS = {
    {KEY_UP, arcade::UP}, {KEY_DOWN, arcade::DOWN}, {KEY_LEFT, arcade::LEFT},
    {KEY_RIGHT, arcade::RIGHT}, {' ', arcade::SPACE}, {'n', arcade::NEXT},
    {'p', arcade::PREV}, {'q', arcade::CLOSE}, {'r', arcade::RESTART},
    {'g', arcade::PREV_GAME}, {'h', arcade::NEXT_GAME}, {27, arcade::ESCAPE},};
