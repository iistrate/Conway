#ifndef CELL_H
#define CELL_H

#include "GameObject.h"

class Cell: public GameObject {
private:
	bool m_blife;
public:
	Cell();
	Cell(bool alive, int y, int x);

	bool isAlive();
	void setLife(bool);

};

#endif