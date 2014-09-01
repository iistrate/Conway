#ifndef WORLD_H
#define WORLD_H

#include <list>
#include <stdlib.h>
#include <time.h>

#include "GLOBALS.h"
#include "Cell.h"


class World {
private:
	//px h and w
	int m_iheight;
	int m_iwidth;

	//holds world's images
	std::list < Cell* > Cells;

public:
	World();
	void update();
	void getImages(std::list < Image* > &f_Images);
	Cell* getCellbyPos(int y, int x);
};

#endif