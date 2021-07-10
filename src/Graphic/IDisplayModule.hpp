/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <memory>
#include <utility>
#include <vector>
#include "IDrawable.hpp"

/**
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief all events handle by our games
 * @enum events_e
 * 
 */
enum events_e {
    CLOSE,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE,
    ESCAPE,
    NEXT,
    PREV,
    NOTHING,
    RESTART,
    NEXT_GAME,
    PREV_GAME
};

/**
 * @brief Interface for display module
 * @class IDisplayModule
 * 
 */
class IDisplayModule {
public:
    /**
     * @brief Destroy the IDisplayModule object
     * 
     */
    virtual ~IDisplayModule() = default;
    /**
     * @brief Get the Name object
     * 
     * @return const std::string& 
     */
    virtual const std::string &getName() const = 0;
    /**
     * @brief init a window
     * 
     */
    virtual void init() = 0;
    /**
     * @brief destroy window
     * 
     */
    virtual void destroy() = 0;
    /**
     * @brief clear window
     * 
     */
    virtual void clearWin() = 0;
    /**
     * @brief refresh window
     * 
     */
    virtual void refreshWin() = 0;
    /**
     * @brief draw object
     * 
     * @param drawable 
     * @param position 
     * @param name 
     */
    virtual void draw(std::vector<std::shared_ptr<IDrawable>> drawable,
        std::pair<int, int> position, const std::string &name
    ) = 0;
    /**
     * @brief draw text
     * 
     * @param string 
     * @param position 
     */
    virtual void drawText(const std::string &string,
        std::pair<int, int> position
    ) = 0;
    /**
     * @brief load texture
     * 
     * @param drawable 
     * @param name 
     */
    virtual void load(std::vector<std::shared_ptr<IDrawable>> drawable,
        const std::string &name
    ) = 0;
    virtual events_e pollEvent() = 0;
    virtual std::string getForm(std::string str) = 0;
};
}

extern "C" arcade::IDisplayModule *createGraphLib();
extern "C" std::string getType();