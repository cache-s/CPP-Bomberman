//
// AssetsManager.hpp for Bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:29:48 2015 Jordan Chazottes
// Last update Sun Jun 14 21:29:49 2015 Jordan Chazottes
//

#ifndef		ASSETSMANAGER_HPP_
# define	ASSETSMANAGER_HPP_

# include	<vector>
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
  gdl::Texture*					getTexture(eEntityType type) const;
  void	init();
private:
  gdl::Model					_model;
  std::vector<gdl::Texture>			_texture;
  std::map<eEntityType, gdl::Model*>		_models;
  std::map<eEntityType, gdl::Texture*>		_textures;
};

#endif		/* ASSETSMANAGER_HPP_ */
