#ifndef GAMEENGINE_HH_
# define GAMEENGINE_HH_

#pragma once
#include <Game.hh>
#include <SdlContext.hh>
#include <BasicShader.hh>
#include <iostream>
#include <vector>

#include "AObject.hpp"
#include "Cube.hpp"

/*
Class GameEngine qui herite de game
*/

class GameEngine : public gdl::Game
{
private:
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  std::vector<AObject*>	_objects;
public:
  GameEngine()
  {
  }
  bool initialize()
  {
    if (!_context.start(800, 600, "My bomberman!"))
      return false;
    glEnable(GL_DEPTH_TEST);
    if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER))
      std::cout << "Error basic.fp" << std::endl;
    if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER))
      std::cout << "Error basic.vp" << std::endl;
    if (!_shader.build())
      std::cout << "Error build" << std::endl;
    glm::mat4 projection;
    glm::mat4 transformation;
    projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 200.0f);
    transformation = glm::lookAt(glm::vec3(0, 20, -100), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    _shader.bind();
    _shader.setUniform("view", transformation);
    _shader.setUniform("projection", projection);
    AObject *cube = new Cube();
    if (cube->initialize() == false)
      return (false);
    _objects.push_back(cube);
    return true;
  }
  bool update()
  {
    if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
      return false;
    _context.updateClock(_clock);
    _context.updateInputs(_input);
    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->update(_clock, _input);
    return true;
  }
  void draw()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _shader.bind();
    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->draw(_shader, _clock);
    _context.flush();
  }
  ~GameEngine()
  {    
    for (size_t i = 0; i < _objects.size(); ++i)
      delete _objects[i];
  }
};

#endif
