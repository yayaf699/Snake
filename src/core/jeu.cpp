/**
 * @file jeu.cpp
 * @author Yanisse FERHAOUI
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "jeu.h"


const Terrain & Jeu::getTerrain() const{ return ter;}

const Snake & Jeu::getSnake() const{ return snk;}

const Fruit & Jeu::getFruit() const{ return fr;}

void Jeu::actionClavier(const char touche){
    switch(touche){
        case 'g':
        snk.gauche(ter);
        break;

        case 'd':
        snk.droite(ter);
        break;

        case 'h':
        snk.haut(ter);
        break;

        case 'b':
        snk.bas(ter);
        break;
    }
    snk.update_corps();
    snk.mange(fr, ter);
}