#include "Cell.h"
#include <iostream>

Cell::Cell(): m_blife(false) {
	int width = 10;
	int height = 10;

	m_Image = new Image("assets/deadcell.png", 0, 0, width, height, 0, 0, 1, false, 1, 1, true);
}
Cell::Cell(bool alive, int y, int x) {
	int width = 10;
	int height = 10;


	//load image
	if (alive == true) {
		m_Image = new Image("assets/alivecell.png", x, y, width, height, 0, 0, 1, false, 1, 1, true);
	}
	else {
		m_Image = new Image("assets/deadcell.png", x, y, width, height, 0, 0, 1, false, 1, 1, true);
	}
	//set pos
	setX(x);
	setY(y);
	//set life state
	m_blife = alive;
}

void Cell::setLife(bool alive) {
	int width = 10;
	int height = 10;

	m_blife = alive;

	if (alive) {
		m_Image->load("assets/alivecell.png", m_x, m_y, width, height, 0, 0, 1, false, 1, 1, true);
	}
	else {
		m_Image->load("assets/deadcell.png", m_x, m_y, width, height, 0, 0, 1, false, 1, 1, true);
	}
}
bool Cell::isAlive() {
	return m_blife;
}