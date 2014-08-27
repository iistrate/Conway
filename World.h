#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "GLOBALS.h"
#include "Cell.h"


class World {
private:
	//px h and w
	int m_iheight;
	int m_iwidth;

	//holds world's images
	std::vector < std::vector < GameObject* > > Map;

public:
	World();
	void getImages(std::vector < Image* > &f_Images);

};

#endif