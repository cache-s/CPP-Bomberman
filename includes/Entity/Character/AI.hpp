#ifndef				AI_HPP_
# define			AI_HPP_

# include			"IAI.hpp"

template <class T>
class				AI : public IAI<T>
{
public:
  AI();
  ~AI();
  eEntityType			getType() const;
private:

};

#endif				//AI_HPP_
