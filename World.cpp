#include "World.h"
#include <iostream>

World::World() {
	/*
	//rand
	srand(time(NULL));
	
	//coordinates seed
	int seed_x;
	int seed_y;
	
	//life seed
	int seed_b;
	
	bool life = true;
	bool seeded = false;
	int cellnr = 500;

	for (int i = 0; i < cellnr; i++) {
		seed_x = rand() % GLOBALS::SCREEN_WIDTH / 4 + GLOBALS::SCREEN_WIDTH / 8;
		seed_y = rand() % GLOBALS::SCREEN_HEIGHT / 2 + GLOBALS::SCREEN_HEIGHT / 4;
		seed_b = rand() % 2;
		//compare seedx and seedy to cellsx and cellsy
		for (int i = 0; i < Cells.size(); i++) {
			int cellx = Cells[i]->getX();
			int celly = Cells[i]->getY();
			int cellh = Cells[i]->getH();
			int cellw = Cells[i]->getW();

			if ((seed_x >= cellx + cellw) && (seed_x <= cellx - cellw)
				|| (seed_y <= celly + cellh) && (seed_y >= celly - celly)
				) {
				//account for width and height
				seeded = true;
				std::cout << i << " second loop" << std::endl; 
			}
		}
		//if it has been seeded skip loop and lower flag
		if (seeded) {
			std::cout << "seeded" << std::endl;
			seeded = false;
		}
		else {
			Cells.push_back(new Cell(seed_b, seed_x, seed_y));
		}
	}
	*/
	for (int i = 0; i < 1200; i = i+5) {
		for (int j = 0; j < 900; j = j+5) {
			Cells.push_back(new Cell(false, i, j));
		}
	}
	//pattern1
	Cell* c1 = new Cell(true, 400, 400);
	Cell* c2 = new Cell(true, 405, 400);
	Cell* c3 = new Cell(true, 410, 400);
	Cells.push_back(c1);
	Cells.push_back(c2);
	Cells.push_back(c3);
}
void World::update() {
	int neighbours = 0;
	for (int i = 0; i < Cells.size(); i++) {
		int cx = Cells[i]->getX();
		int cy = Cells[i]->getY();
		for (int j = 0; j < Cells.size(); j++) {
			//if it is alive and next to our cell neighoubrs gp up
			if (Cells[i]->isAlive()) {
				//right
				if (cx + 5 == Cells[i]->getX()) {
					neighbours++;
				}
				//left
				if (cx - 5 == Cells[i]->getX()) {
					neighbours++;
				}
				//up
				if (cy - 5 == Cells[i]->getY()) {
					neighbours++;
				}
				//down
				if (cy + 5 == Cells[i]->getY()) {
					neighbours++;
				}
				//upright
				if (cx + 5 == Cells[i]->getX() && cy - 5 == Cells[i]->getY()) {
					neighbours++;
				}
				//upleft
				if (cx - 5 == Cells[i]->getX() && cy - 5 == Cells[i]->getY()) {
					neighbours++;
				}
				//downleft
				if (cx - 5 == Cells[i]->getX() && cy + 5 == Cells[i]->getY()) {
					neighbours++;
				}
				//downright
				if (cx + 5 == Cells[i]->getX() && cy - 5 == Cells[i]->getY()) {
					neighbours++;
				}
			} //inner
		} //outer
		if (neighbours == 3) {
			Cells[i]->setLife(true);
			neighbours = 0;
		}
		else if (neighbours == 2) {
			void;
		}
		else {
			Cells[i]->setLife(false);
		}
	}
}
void World::getImages(std::vector < Image* > &f_Images) {
	for (int i = 0; i < Cells.size(); i++) {
			f_Images.push_back(Cells[i]->getImage());
	}
}