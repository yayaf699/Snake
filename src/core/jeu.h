/**
 * @file jeu.h
 * @author Yanisse FERHAOUI
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _JEU_H
#define _JEU_H

#include "terrain.h"
#include "snake.h"
#include "fruit.h"

class Jeu{

    private:

    Terrain ter;
    Snake snk;
    Fruit fr;

    public:

    const Terrain & getTerrain() const;

    const Snake & getSnake() const;

    const Fruit & getFruit() const;

    void actionClavier(const char touche);

};


#endif