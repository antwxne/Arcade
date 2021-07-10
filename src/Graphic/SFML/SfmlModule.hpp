/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "../ADisplayModule.hpp"

/**
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief sfml encapsulation
 * @class SFMLModule
 * 
 */
class SFMLModule : public arcade::ADisplayModule {
public:
    /**
     * @brief Construct a new SFMLModule object
     * 
     */
    SFMLModule();
    /**
     * @brief Destroy the SFMLModule object
     * 
     */
    ~SFMLModule() override;
    /**
     * @brief init a window
     * 
     */
    void init() override;
    /**
     * @brief destroy a window
     * 
     */
    void destroy() override;
    /**
     * @brief draw text
     * 
     * @param string 
     * @param position 
     */
    void drawText(const std::string &string, std::pair<int, int> position
    ) override;
    /**
     * @brief refresh window
     * 
     */
    void refreshWin() override;
    /**
     * @brief clear window
     * 
     */
    void clearWin() override;
    /**
     * @brief Get the Form object
     * 
     * @param str 
     * @return std::string 
     */
    std::string getForm(std::string str) override;
    /**
     * @brief draw object
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

private:
    /**
     * @brief window
     * 
     */
    sf::RenderWindow _window;
    /**
     * @brief textures
     * 
     */
    std::map<std::string, sf::Texture> _textures;
};
}

static const std::vector<std::string> TEXTURES_TO_LOAD = {"wall.png"};

static const std::vector<std::pair<sf::Keyboard::Key, arcade::events_e>> KEYS = {
    {sf::Keyboard::Escape, arcade::ESCAPE}, {sf::Keyboard::Key::Up, arcade::UP},
    {sf::Keyboard::Key::Down, arcade::DOWN},
    {sf::Keyboard::Key::Left, arcade::LEFT},
    {sf::Keyboard::Key::Right, arcade::RIGHT},
    {sf::Keyboard::Space, arcade::SPACE}, {sf::Keyboard::N, arcade::NEXT},
    {sf::Keyboard::P, arcade::PREV}, {sf::Keyboard::Q, arcade::CLOSE},
    {sf::Keyboard::R, arcade::RESTART}, {sf::Keyboard::G, arcade::PREV_GAME},
    {sf::Keyboard::H, arcade::NEXT_GAME}};

static const std::map<arcade::colors_e, sf::Color> COLORS = {
    {arcade::WHITE, sf::Color::White}, {arcade::BLACK, sf::Color::Black},
    {arcade::GREEN, sf::Color::Green}, {arcade::RED, sf::Color::Red},
    {arcade::BLUE, sf::Color::Blue}, {arcade::BLACK, sf::Color::Black},
    {arcade::CYAN, sf::Color::Cyan}, {arcade::MAGENTA, sf::Color::Magenta},
    {arcade::YELLOW, sf::Color::Yellow},
    {arcade::NONE, sf::Color::Transparent}};
