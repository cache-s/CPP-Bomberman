#ifndef		ASSETSMANAGER_HPP_
# define	ASSETSMANAGER_HPP_

# include	<Texture.hh>
# include	<Model.hh>
# include	"IEntity.hpp"

class		AssetsManager
{
public:
  AssetsManager();
  ~AssetsManager();
  gdl::Model*					getModel(eEntityType type);
private:
  std::map<eEntityType, gdl::Model*>		_models;
};

#endif		/* ASSETSMANAGER_HPP_ */
