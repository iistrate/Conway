#include "GameObject.h"

class Cell: public GameObject {
private:
	bool m_blife;
public:
	Cell();
	Cell(bool b);

	bool isAlive();
	void setLife(bool);

};