/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by theo,
*/

#pragma once

#include <string>
#include <array>

/**
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief colors handled
 * @enum colors_e
 * 
 */
enum colors_e {
    WHITE,
    BLACK,
    GREEN,
    RED,
    BLUE,
    CYAN,
    MAGENTA,
    YELLOW,
    NONE
};
/**
 * @brief diferent objects type
 * @enum type_e
 * 
 */
enum type_e {
    SPRITE,
    SHAPE,
    TEXT,
    NO_TYPE
};
/**
 * @brief Interface for drawable objects
 * @class IDrawable
 * 
 */
class IDrawable {
public:
    /**
     * @brief Destroy the IDrawable object
     * 
     */
    virtual ~IDrawable() = default;
    /**
     * @brief Get the String object
     * 
     * @return const std::string& 
     */
    virtual const std::string &getString() const = 0;
    /**
     * @brief Get the Type object
     * 
     * @return type_e 
     */
    virtual type_e getType() const = 0;
    /**
     * @brief Get the Size object
     * 
     * @return std::size_t 
     */
    virtual std::size_t getSize() const = 0;
    /**
     * @brief Get the Color object
     * 
     * @return colors_e 
     */
    virtual colors_e getColor() const = 0;
};
}