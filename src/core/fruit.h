/**
 * @file fruit.h
 * @author Yanisse FERHAOUI
 * @brief 
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _FRUIT_H
#define _FRUIT_H

#include "terrain.h"
#include <stdlib.h>


class Fruit{

    private:

    unsigned int x, y;

    public:

    Fruit();

    unsigned int getX() const;

    unsigned int getY() const;

    void changePos(Terrain &ter);

};

#endif