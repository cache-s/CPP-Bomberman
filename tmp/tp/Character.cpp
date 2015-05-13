//
// Character.cpp for cpp_bomber in /home/chazot_a/rendu/cpp_bomberman/tp
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Fri May  8 17:14:47 2015 Jordan Chazottes
// Last update Wed May 13 11:32:02 2015 Sebastien Cache-Delanos
//

#include	"Character.hh"

Character::Character()
{
}

Character::Character(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
{
  _position = position;
  _rotation = rotation;
  _scale = scale;
}

Character::~Character()
{
}

bool	Character::initialize()
{
  _speed = 10.0f;
  if (_model.load("./LibBomberman_linux_x64/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load the character texture" << std::endl;
      return false;
    }
  return true;
}

void	Character::update(gdl::Clock const& clock, gdl::Input& input)
{
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * (_speed*4));
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * (_speed*4));
  if (input.getKey(SDLK_LEFT))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * (_speed*4));
  if (input.getKey(SDLK_RIGHT))
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * (_speed*4));
  if (input.getKey(SDLK_s))
    {
      translate(glm::vec3(0, -1, 0) * static_cast<float>(clock.getElapsed()) * (_speed*4));
      _model.setCurrentAnim(0, false);
    }
  if (input.getKey(SDLK_z))
    translate(glm::vec3(0, 1, 0) * static_cast<float>(clock.getElapsed()) * (_speed*4));
  if (input.getKey(SDLK_q))
    rotate(glm::vec3(_position.x, _position.y, _position.z) * static_cast<float>(clock.getElapsed()) * (_speed*4), 20);
  if (input.getKey(SDLK_d))
    rotate(glm::vec3(_position.x, _position.y, _position.z) * static_cast<float>(clock.getElapsed()) * (_speed*4), 20);
  std::cout << "X = " << _position.x << "\nY = " << _position.y << "\nZ = " << _position.z << std::endl;
}

void	Character::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  _texture.bind();
  _model.draw(shader, getTransformation(), clock.getElapsed());
}

glm::vec3	Character::getPosition() const
{
  return (_position);
}
