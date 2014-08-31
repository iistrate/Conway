#ifndef WORLD_H
#define WORLD_H

#include <vector>
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
	std::vector < Cell* > Cells;

public:
	World();
	void update();
	void getImages(std::vector < Image* > &f_Images);
	Cell* getCellbyPos(int x, int y);
};

#endif