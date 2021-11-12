#include "Pulpo.h"
Pulpo::Pulpo() { }
Pulpo::Pulpo(int _x, int _y): Base(_x, _y, 1, 1) { 
	fracMovX = 1;
	fracMovY = 1;
	max_col = 1;
	max_fil = 1;
	col = 0;
	fil = 0;
}
Pulpo::~Pulpo() { }
