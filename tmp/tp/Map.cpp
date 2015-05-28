//
// Map.cpp for cpp_bomber in /home/chazot_a/rendu/cpp_bomberman/tp
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Fri May  8 14:54:16 2015 Jordan Chazottes
// Last update Thu May 28 16:11:10 2015 Jordan Chazottes
//

#include	"Cube.hh"
#include	"Map.hh"

Map::Map()
{
}

Map::Map(size_t height, size_t width)
{
  _height = height;
  _width = width;
}

Map::~Map()
{
}

bool	Map::initialize()
{
  for (size_t y = 0; y < _width; y += 10)
    {
      for (size_t x = 0; x < _height; x += 10)
	{
	  std::cout << "positionning cube at : " << x << ", " << y << std::endl;
	  AObject *cube = new Cube(glm::vec3(x, 0, y), glm::vec3(0, 0, 0), glm::vec3(10, 10, 10));
	  _ground.push_back(cube);
	}
    } 
  return true;
}

void	Map::update(gdl::Clock const& clock, gdl::Input& input)
{
  for (size_t i = 0; i < _ground.size(); ++i)
    _ground[i]->update(clock, input);
}

void	Map::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  for (size_t i = 0; i < _ground.size(); ++i)
    _ground[i]->draw(shader, clock);
}
