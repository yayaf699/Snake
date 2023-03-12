/**
 * @file txtJeu.cpp
 * @author Yanisse FERHAOUI
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "txtJeu.h"

void txtAff(WinTXT & win, const Jeu & jeu) {
	const Terrain& ter = jeu.getTerrain();
	const Snake& snk = jeu.getSnake();
	const Fruit& fr = jeu.getFruit();

	win.clear();

    // Affichage des murs
	for(unsigned int x=0;x<ter.getDimX();++x)
		for(unsigned int y=0;y<ter.getDimY();++y)
			win.print( x, y, ter.getXYAsChar(x,y));

    // Affichage du serpent
	win.print(snk.getXTete(), snk.getYTete(),'o');
	for(int i = 0; i < snk.getTaille(); i++){
		win.print(snk.getXCorps(i), snk.getYCorps(i),'o');
	}
	// Affichage du Fruit
	win.print(fr.getX(),fr.getY(),'F');

	win.draw();
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getTerrain().getDimX(),jeu.getTerrain().getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32


		c = win.getCh();
		switch (c) {
			case 'k':
				jeu.actionClavier('g');
				break;
			case 'm':
				jeu.actionClavier('d');
				break;
			case 'l':
				jeu.actionClavier('h');
				break;
			case 'o':
				jeu.actionClavier('b');
				break;
			case 'q':
				ok = false;
				break;
		}

	} while (ok);

}