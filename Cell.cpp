#include "Cell.h"

Cell::Cell(): m_blife(false) {
	m_Image->load("Assets/alivecell.png", 0, 0, 5, 5, 0, 0, 1, false, 1, 1, true);
}
Cell::Cell(bool alive) {
	if (alive == true) {
		m_Image->load("Assets/alivecell.png", 0, 0, 5, 5, 0, 0, 1, false, 1, 1, true);
	}
	else {
		m_Image->load("Assets/deadcell.png", 0, 0, 5, 5, 0, 0, 1, false, 1, 1, true);
	}
}

void Cell::setLife(bool alive) {
	m_blife = alive;
}
bool Cell::isAlive() {
	return m_blife;
}