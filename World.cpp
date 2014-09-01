#include "World.h"
#include <iostream>

World::World() {
	for (int y = 0; y < GLOBALS::LEVEL_HEIGHT; y = y + 10) {
		for (int x = 0; x < GLOBALS::LEVEL_WIDTH; x = x+10) {
			Cells.push_back(new Cell(false, y, x));
		}
	}
	//pattern1
	getCellbyPos(50, 30)->setLife(true);
	getCellbyPos(50, 40)->setLife(true);
	getCellbyPos(50, 50)->setLife(true);

}
void World::update() {

	std::list < Cell* > kill;
	std::list < Cell* > revive;

	//setup
	int neighbours = 0;
	int cx = 0;
	int cy = 0;
	bool isalive = false;
	int width = 10;
	int height = 10;

	//look at each cell
	for (std::list < Cell* >::iterator it = Cells.begin(); it != Cells.end(); ++it) {
		//current cell
		cx = (*it)->getX();
		cy = (*it)->getY();
		isalive = (*it)->isAlive();
		neighbours = 0;
		//check if the cell's neighbour is alive
		if (cx + 10 < GLOBALS::LEVEL_WIDTH && cx - 10 >= 0 && cy - height > 0 && cy + height < GLOBALS::LEVEL_HEIGHT) {
			//look right
			if (getCellbyPos(cy, cx + width)->isAlive()) {
				neighbours++;
			}
			//look left
			if (getCellbyPos(cy, cx - width)->isAlive()) {
				neighbours++;
			}
			//look up
			if (getCellbyPos(cy - height, cx)->isAlive()) {
				neighbours++;
			}
			//look down
			if (getCellbyPos(cy + height, cx)->isAlive()) {
				neighbours++;
			}
			//look up right
			if (getCellbyPos(cy - height, cx + width)->isAlive()) {
				neighbours++;
			}
			//look up left
			if (getCellbyPos(cy - height, cx - width)->isAlive()) {
				neighbours++;
			}
			//look down right
			if (getCellbyPos(cy + height, cx + width)->isAlive()) {
				neighbours++;
			}
			//look down left
			if (getCellbyPos(cy + height, cx - width)->isAlive()) {
				neighbours++;
			}
		}
		//if dead
		if (!isalive) {
			//reproduce
			if (neighbours == 3) {
				revive.push_back(*it);
				std::cout << cy << " " << cx << " can reproduce!" << std::endl;
			}
		}
		if (isalive) {
			//die
			if (neighbours < 2) {
				kill.push_back(*it);
				std::cout << cy << " " << cx << " dies of loneliness!" << std::endl;
			}
			//live on
			else if (neighbours == 3 || neighbours == 2) {
				std::cout << cy << " " << cx << " can live on!" << std::endl;
			}
			//die overcrowding
			else if (neighbours > 3) {
				kill.push_back(*it);
				std::cout << cy << " " << cx << " dies of overcrowding!" << std::endl;
			}
		}
	} //outer
	//kill the cells
	for (std::list < Cell* >::iterator it = kill.begin(); it != kill.end(); ++it) {
		(*it)->setLife(false);
	}
	//revive the cells
	for (std::list < Cell* >::iterator it = revive.begin(); it != revive.end(); ++it) {
		(*it)->setLife(true);
	}
}
void World::getImages(std::list < Image* > &f_Images) {
	for (std::list < Cell* >::iterator it = Cells.begin(); it != Cells.end(); ++it) {
		//show only live cells
		f_Images.push_back((*it)->getImage());
	}
}
Cell* World::getCellbyPos(int y, int x) {
	for (std::list < Cell* >::iterator it = Cells.begin(); it != Cells.end(); ++it) {
		if ((*it)->getX() == x && (*it)->getY() == y) {
			return (*it);
		}
	}
}