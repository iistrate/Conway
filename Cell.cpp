#include "Cell.h"
#include <iostream>

Cell::Cell(): m_blife(false) {
	m_Image = new Image("assets/alivecell.png", 0, 0, 5, 5, 0, 0, 1, false, 1, 1, true);
}
Cell::Cell(bool alive, int x, int y) {
	if (alive == true) {
		m_Image = new Image("assets/alivecell.png", x, y, 5, 5, 0, 0, 1, false, 1, 1, true);
	}
	else {
		m_Image = new Image("assets/deadcell.png", x, y, 5, 5, 0, 0, 1, false, 1, 1, true);
	}
}

void Cell::setLife(bool alive) {
	if (alive) {
		m_Image->load("assets/alivecell.png", m_x, m_y, 5, 5, 0, 0, 1, false, 1, 1, true);
	}
	else {
		m_Image->load("assets/deadcell.png", m_x, m_y, 5, 5, 0, 0, 1, false, 1, 1, true);
	}
	m_blife = alive;
}
bool Cell::isAlive() {
	return m_blife;
}