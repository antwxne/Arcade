/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#pragma once

#include <string>
#include "IDrawable.hpp"

namespace arcade {
    class ADisplayModule : public arcade::IDrawable {
        public:
            void setSize(int size);
            int getSize();

        protected:
            int _size;
    };
}