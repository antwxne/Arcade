/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/
#include <fstream>
#include <iostream>
#include <filesystem>
#include "Core/Core.hpp"
#include "LoadLib/LoadLib.hpp"
#include "Game/Object/IObject.hpp"

namespace arcade {

    Core::Core() {
        this->_loadLibs;
        this->_actualLibs;
        this->_loadGames;
        this->_actualGames;
    }

    void Core::OpenGame() {
        LoadLib ldb;
        std::string tmp;
        for (auto &p: std::filesystem::directory_iterator("./games")) {
            ldb.initHandler(p.path());
            auto libs = ldb.loadingLib<IGame *(void)>("GetGame")();
            tmp = p.path();
            tmp.erase(0, 12);
            _loadGames.push_back(std::pair<std::string, IGame *>(tmp, libs));
          //  std::cout << tmp << "\n";
        }
        std::cout << "name game === " << _loadGames[0].first << "\n";
    }

    void Core::OpenFirstLibs(std::string arg) {
        LoadLib ldb;
        ldb.initHandler(arg);
        auto libs = ldb.loadingLib<IDisplayModule *(void)>("createGraphLib")();
        arg.erase(0, 6);
        _actualLibs = arg;
        _loadLibs.push_back(std::pair<std::string, IDisplayModule *>(arg, libs));
    }

    void Core::OpenLibsInLibs(std::string arg) {
        LoadLib ldb;
        std::string tmp;
        for (auto &p: std::filesystem::directory_iterator("./lib")) {
            if (arg == p.path())
                continue;
            ldb.initHandler(p.path());
            auto libs = ldb.loadingLib<IDisplayModule *(void)>("createGraphLib")();
            tmp = p.path();
            tmp.erase(0, 6);
            _loadLibs.push_back(std::pair<std::string, IDisplayModule *>(tmp, libs));
            std::cout << tmp << "\n";
        }
    }

    void Core::switchLibs(events_e event) {
        if (event == arcade::NEXT) {
            for (long unsigned int i = 0; i != _loadLibs.size(); i++) {
                if (_loadLibs[i].first == _actualLibs) {
                    i++;
                    if (i >= _loadLibs.size())
                        i = 0;
                    _actualLibs = _loadLibs[i].first;
                }
            }
        }
        if (event == arcade::PREV) {
            for (long unsigned int i = 0; i != _loadLibs.size(); i++) {
                if (_loadLibs[i].first == _actualLibs) {
                    //std::cout << _loadLibs.size() << "\n";
                    if (i == 0)
                        i = _loadLibs.size() - 1;
                    else
                        i--;
                    _actualLibs = _loadLibs[i].first;
                }
            }
        }
    }

    void Core::gameLoop() {
        long unsigned int i = 0;

        for (; i != _loadLibs.size(); i++) {
            if (_loadLibs[i].first == _actualLibs)
                break;
        }
        auto gaming = _loadGames[0].second;
        auto k  = gaming->play(arcade::UP);
        auto n = k[1]->getDrawables();
        auto libs = _loadLibs[0].second;
        libs->init();
        while (1) {
            auto tmp = _actualLibs;
            if (libs->pollEvent() == arcade::CLOSE) {
                break;
            }
            libs->refreshWin();
            libs->clearWin();
            libs->getName();
            std::string s = "bite";
            libs->draw(n,std::pair<int, int>(10,150), s);
            switchLibs(libs->pollEvent());
            if (tmp != _actualLibs)
                for (long unsigned int a = 0; a != _loadLibs.size(); a++) {
                    if (_loadLibs[a].first == _actualLibs) {
                        libs->destroy();
                        libs = _loadLibs[a].second;
                        libs->init();
                        break;
                    }
                }
        }
    }
}
