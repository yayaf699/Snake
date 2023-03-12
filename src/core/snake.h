/**
 * @file snake.h
 * @author Yanisse FERHAOUI
 * @brief 
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _SNAKE_H
#define _SNAKE_H

#include "terrain.h"
#include "fruit.h"
#include <vector>


struct Point{
    friend class Snake;
    unsigned int x, y, ox, oy;
};


class Snake{

    private:

    Point tete;
    std::vector<Point> corps;

    unsigned int taille; // taille du corps

    public:

    Snake();

    int getXTete()const;

    int getYTete()const;

    int getTaille() const;

    int getXCorps(unsigned int i) const;

    int getYCorps(unsigned int i) const;

    void gauche(Terrain & ter);

    void droite(Terrain & ter);

    void haut(Terrain & ter);

    void bas(Terrain & ter);

    void update_corps();

    void grandir();

    void mange(Fruit &Fr, Terrain &ter);



};

#endif 