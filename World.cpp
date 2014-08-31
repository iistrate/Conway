#include "World.h"
#include <iostream>

World::World() {
	for (int i = 0; i < GLOBALS::LEVEL_WIDTH; i = i+10) {
		for (int j = 0; j < GLOBALS::LEVEL_HEIGHT; j = j+10) {
			Cells.push_back(new Cell(false, i, j));
		}
	}
	//pattern1
	getCellbyPos(20, 50)->setLife(true);
	getCellbyPos(30, 50)->setLife(true);
	getCellbyPos(40, 50)->setLife(true);
}
void World::update() {
	//setup
	enum look {
		UP,
		RIGHT,
		DOWN,
		LEFT,
		UP_LEFT,
		UP_RIGHT,
		DOWN_LEFT,
		DOWN_RIGHT
	};
	int neighbours = 0;
	int cx = 0;
	int cy = 0;
	bool isalive = false;
	int width = 10;
	int height = 10;

	//look at each cell
	for (int i = 0; i < Cells.size(); i++) {
		//current cell
		cx = Cells[i]->getX();
		cy = Cells[i]->getY();
		isalive = Cells[i]->isAlive();
		neighbours = 0;
		
		//check if the cell's neighbour is alive
		//look right
		if (cx + 10 < GLOBALS::LEVEL_WIDTH && cx - 10 >= 0 && cy - height > 0 && cy + height < GLOBALS::LEVEL_HEIGHT) {
			if (getCellbyPos(cx + width, cy)->isAlive()) {
				neighbours++;
			}
			//look left
			if (getCellbyPos(cx - width, cy)->isAlive()) {
				neighbours++;
			}
			//look up
			if (getCellbyPos(cx, cy - height)->isAlive()) {
				neighbours++;
			}
			//look down
			if (getCellbyPos(cx, cy + height)->isAlive()) {
				neighbours++;
			}
			//look up right
			if (getCellbyPos(cx + width, cy - height)->isAlive()) {
				neighbours++;
			}
			//look up left
			if (getCellbyPos(cx - width, cy - height)->isAlive()) {
				neighbours++;
			}
			//look down right
			if (getCellbyPos(cx + width, cy + height)->isAlive()) {
				neighbours++;
			}
			//look down left
			if (getCellbyPos(cx - width, cy + height)->isAlive()) {
				neighbours++;
			}
		}
		if (isalive) {
			//die
			if (neighbours < 2) {
				//Cells[i]->setLife(false);
				std::cout << cy << " " << cx << " dies of loneliness!" << std::endl;
			}
			//live on
			else if (neighbours == 3 || neighbours == 2) {
				std::cout << cy << " " << cx << " can live on!" << std::endl;
			}
			//die overcrowding
			else if (neighbours > 3) {
				//Cells[i]->setLife(false);
				std::cout << cy << " " << cx << " dies of overcrowding!" << std::endl;
			}
		}
		//if dead
		else {
			//reproduce
			if (neighbours == 3) {
				//Cells[i]->setLife(true);
				std::cout << cy << " " << cx << " can reproduce!" << std::endl;
			}
		}

	} //outer
}
void World::getImages(std::vector < Image* > &f_Images) {
	for (int i = 0; i < Cells.size(); i++) {
		//show only live cells
		if (Cells[i]->isAlive()) {
			f_Images.push_back(Cells[i]->getImage());
		}
	}
}
Cell* World::getCellbyPos(int x, int y) {
	for (int i = 0; i < Cells.size(); i++) {
		if (Cells[i]->getX() == x && Cells[i]->getY() == y) {
			return Cells[i];
		}
	}
}