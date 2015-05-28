//
// Map.hh for cpp_bomber in /home/chazot_a/rendu/cpp_bomberman/tp
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Fri May  8 14:47:19 2015 Jordan Chazottes
// Last update Thu May 28 15:49:14 2015 Jordan Chazottes
//

#ifndef		MAP_HH_
# define	MAP_HH_

# include	<Texture.hh>
# include	<Geometry.hh>

# include	"AObject.hh"

class Map : public AObject
{
private:
  size_t		_height;
  size_t		_width;
  std::vector<AObject*>	_ground;
public:
		Map();
  Map(size_t, size_t);
  virtual	~Map();
  virtual bool	initialize();
  virtual void	update(gdl::Clock const& clock, gdl::Input& input);
  virtual void	draw(gdl::AShader& shader, gdl::Clock const& clock);
};

#endif //Map_HH_
