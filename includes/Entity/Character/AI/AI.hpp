#ifndef				AI_HPP_
# define			AI_HPP_

# include			"IAI.hpp"

class				AI : public IAI
{
public:
  AI();
  ~AI();
  eEntityType			getType() const;
private:

};

#endif				//AI_HPP_
