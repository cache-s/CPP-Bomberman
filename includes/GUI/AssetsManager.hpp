#ifndef		ASSETSMANAGER_HPP_
# define	ASSETSMANAGER_HPP_

# include	<iostream>
# include	<Geometry.hh>
# include	<Texture.hh>
# include	<Model.hh>
# include	"IEntity.hpp"

class		AssetsManager
{
public:
  AssetsManager();
  ~AssetsManager();
  gdl::Model*					getModel(eEntityType type) const;
  void	init();
private:
  gdl::Model					_model;
  std::map<eEntityType, gdl::Model*>		_models;
};

#endif		/* ASSETSMANAGER_HPP_ */
