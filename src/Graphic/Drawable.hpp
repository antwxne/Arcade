/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#pragma once

#include <string>
#include <vector>
#include "IDrawable.hpp"

/**
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief info about a drawable object
 * @class Drawable
 * 
 */
class Drawable : public arcade::IDrawable {
public:
    /**
     * @brief Construct a new Drawable object
     * 
     * @param obj name
     * @param size 
     * @param type 
     * @param color 
     */
    Drawable(const std::string &obj = "NONE", std::size_t size = 0,
        arcade::type_e type = arcade::NO_TYPE, colors_e color = arcade::NONE
    );
    /**
     * @brief Destroy the Drawable object
     * 
     */
    ~Drawable() override = default;
    /**
     * @brief Get the String object
     * 
     * @return const std::string& 
     */
    const std::string &getString() const override;
    /**
     * @brief Get the Size object
     * 
     * @return std::size_t 
     */
    std::size_t getSize() const override;
    /**
     * @brief Get the Type object
     * 
     * @return type_e 
     */
    type_e getType() const override;
    /**
     * @brief Get the Color object
     * 
     * @return colors_e 
     */
    colors_e getColor() const override;
    /**
     * @brief Set the String object
     * 
     * @param name 
     */
    void setString(const std::string &name)
    {
        _infos = name;
    };

protected:
    /**
     * @brief name
     * 
     */
    std::string _infos;
    /**
     * @brief size
     * 
     */
    std::size_t _size;
    /**
     * @brief type
     * 
     */
    arcade::type_e _type;
    /**
     * @brief color
     * 
     */
    colors_e _color;
};
}