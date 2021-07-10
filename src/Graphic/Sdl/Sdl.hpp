/*
** EPITECH PROJECT, 2021
** Sdl.hpp.h
** File description:
** Sdl.hpp.h
*/

#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <SDL2/SDL_ttf.h>
#include <map>
#include "../ADisplayModule.hpp"

/**
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief sdl2 encapsulation
 * @class SDLModule
 * 
 */
class SDLModule : public arcade::ADisplayModule {
public:
    /**
     * @brief Construct a new SDLModule object
     * 
     */
    SDLModule();
    /**
     * @brief Destroy the SDLModule object
     * 
     */
    ~SDLModule() override;

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
     * @brief draw text
     * 
     * @param string 
     * @param position 
     */
    void drawText(const std::string &string, std::pair<int, int> position
    ) override;

private:
    /**
     * @brief sdl renderer
     * 
     */
    SDL_Renderer *_renderer;
    /**
     * @brief window
     * 
     */
    SDL_Window *_window;
    /**
     * @brief window status
     * 
     */
    bool _status;
};
}

static const std::vector<std::pair<SDL_Keycode, arcade::events_e>> KEYS = {
    {SDLK_ESCAPE, arcade::ESCAPE}, {SDLK_UP, arcade::UP},
    {SDLK_DOWN, arcade::DOWN}, {SDLK_LEFT, arcade::LEFT},
    {SDLK_RIGHT, arcade::RIGHT}, {SDLK_SPACE, arcade::SPACE},
    {SDLK_n, arcade::NEXT}, {SDLK_p, arcade::PREV}, {SDLK_q, arcade::CLOSE},
    {SDLK_r, arcade::RESTART}, {SDLK_g, arcade::PREV_GAME},
    {SDLK_h, arcade::NEXT_GAME}};

static const std::map<arcade::colors_e, SDL_Color> COLORS = {
    {arcade::WHITE, {(Uint8)255, (Uint8)255, (Uint8)255, (Uint8)255}},
    {arcade::BLACK, {(Uint8)0, (Uint8)0, (Uint8)0, (Uint8)255}},
    {arcade::GREEN, {(Uint8)125, (Uint8)255, (Uint8)0, (Uint8)255}},
    {arcade::RED, {(Uint8)250, (Uint8)125, (Uint8)125, (Uint8)255}},
    {arcade::BLUE, {(Uint8)0, (Uint8)200, (Uint8)255, (Uint8)255}},
    {arcade::CYAN, {(Uint8)176, (Uint8)224, (Uint8)230, (Uint8)255}},
    {arcade::MAGENTA, {(Uint8)255, (Uint8)20, (Uint8)147, (Uint8)255}},
    {arcade::YELLOW, {(Uint8)255, (Uint8)255, (Uint8)0, (Uint8)255}},
    {arcade::NONE, {(Uint8)255, (Uint8)255, (Uint8)0, (Uint8)255}},};

static const std::vector<std::string> TEXTURES = {"plouf.png"};