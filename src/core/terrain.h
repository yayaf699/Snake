/**
 * @file terrain.h
 * @author Yanisse FERHAOUI
 * @brief Module gerant un terrain
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _TERRAIN_H
#define _TERRAIN_H

#include <cassert>


class Terrain{
    
    private:

    enum TypeCase {SPACE=' ', WALL='#', FRUIT='F', SNAKE='o' };

    unsigned int dimx, dimy;

    TypeCase ter[100][100];

    public:

    Terrain();

    unsigned int getDimX() const;

    unsigned int getDimY() const;

    TypeCase getXY(const unsigned int &x, const unsigned int &y) const;

    char getXYAsChar(const unsigned int & x, const unsigned int & y)const;

    bool estPositionValide(const unsigned int x, const unsigned int y) const;

    

 
};



#endif