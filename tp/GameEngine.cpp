//
// GameEngine.cpp for cpp_bomber in /home/chazot_a/rendu/cpp_bomberman/tp
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Fri May  8 14:24:29 2015 Jordan Chazottes
// Last update Mon May 11 11:07:59 2015 Jordan Chazottes
//

#include "GameEngine.hh"

	GameEngine::GameEngine()
{
}

	GameEngine::~GameEngine()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
}

bool	GameEngine::initialize()
{
  glm::mat4	projection;

  if (!_context.start(1280, 720, "My bomberman!"))
    return false;
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER))
    std::cout << "Error basic.fp" << std::endl;
  if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER))
    std::cout << "Error basic.vp" << std::endl;
  if (!_shader.build())
    std::cout << "Error build" << std::endl;

  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 2000.0f);

  _transformation = glm::lookAt(glm::vec3(0, 100, -20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", projection);

  AObject *cube = new Cube(glm::vec3(17, 0, 0), glm::vec3(0, 0, 0), glm::vec3(10, 10, 10));
  _character = new Character(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0.05, 0.05, 0.05));

  if (cube->initialize() == false)
    return (false);
  if (_character->initialize() == false)
    return (false);
  _objects.push_back(cube);
  _objects.push_back(_character);
  return true;
}

glm::vec3 GameEngine::setCamPos()
{
  glm::vec3 ret;
  ret = _character->getPosition();
  ret.x += 1;
  ret.y += 90;
  ret.z += 70;
  return ret;
}

bool	GameEngine::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  _transformation = glm::lookAt(setCamPos(), _character->getPosition(),glm::vec3(0, 1, 0));
  _shader.setUniform("view", _transformation);
  return true;
}

void	GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  _context.flush();
}
