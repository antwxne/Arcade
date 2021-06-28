/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#pragma once

#include "StaticObject.hpp"
/**
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief objects that can move
 * @class MovableObject
 * 
 */
class MovableObject : public StaticObject {
public:
    /**
     * @brief Construct a new Movable Object object
     * 
     */
    MovableObject(const std::string &, std::vector<std::shared_ptr<IDrawable>>,
        std::pair<int, int>
    );
    /**
     * @brief Destroy the Movable Object object
     * 
     */
    ~MovableObject() = default;
    /**
     * @brief Set the Position object
     * 
     */
    void setPosition(std::pair<int, int>);
};
}