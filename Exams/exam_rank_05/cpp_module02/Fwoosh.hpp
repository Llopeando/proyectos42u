#include "ASpell.hpp"

class Fwoosh: public ASpell {
	public:
		Fwoosh();
		~Fwoosh();

		virtual Fwoosh *clone() const;
};