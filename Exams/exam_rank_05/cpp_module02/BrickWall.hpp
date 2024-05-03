#include "ATarget.hpp"

class BrickWall: public ATarget {
	public:
		BrickWall();
		~BrickWall();

		virtual BrickWall *clone() const;
};