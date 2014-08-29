#ifndef CELL_H
#define CELL_H

#include "GameObject.h"

class Cell: public GameObject {
private:
	bool m_blife;
public:
	Cell();
	Cell(bool, int, int);

	bool isAlive();
	void setLife(bool);

};

#endif