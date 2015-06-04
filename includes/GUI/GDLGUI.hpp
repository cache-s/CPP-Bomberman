#ifndef		GDLGUI_HPP_
# define	GDLGUI_HPP_

# include	<map>
# include	<vector>
# include	<iostream>
# include	<Game.hh>
# include       <glm/glm.hpp>
# include       <glm/gtc/matrix_transform.hpp>
# include	<BasicShader.hh>
# include	<SdlContext.hh>
# include       <Geometry.hh>
# include	"IGUI.hpp"
# include	"IEntity.hpp"
# include	"AssetsManager.hpp"

template <class T>
class GDLGUI : public IGUI<T>, public gdl::Game
{
public:
  GDLGUI();

  void windowInit();
  void cameraInit();
  void shaderInit();
  void soundInit();
  void assetsInit();
  bool initialize();
  bool update();
  void draw();
  bool update(std::vector<IEntity<T> *> ent);
  void translate(T const &v, IEntity<T> &ent) const;
  void rotate(T const &axis, float angle, IEntity<T> &ent) const;

  void setEntitiesToDraw(std::vector<IEntity<T> *> ent);
  void drawBomb(const IEntity<T> &ent) const;
  void drawMonster(const IEntity<T> &ent) const;
  void drawAI(const IEntity<T> &ent) const;
  void drawBombNumber(const IEntity<T> &ent) const;
  void drawRadius(const IEntity<T> &ent) const;
  void drawFlame(const IEntity<T> &ent) const;
  void drawSpeed(const IEntity<T> &ent) const;
  void drawBrkWall(const IEntity<T> &ent) const;
  void drawUbrkWall(const IEntity<T> &ent) const;
  void drawPlayer(const IEntity<T> &ent) const;
  void drawFloor(const IEntity<T> &ent) const;
  void drawMap(std::map<std::pair<int, int>, IEntity<T> *> entMap);
  void drawMenu(const std::string &image);

  glm::mat4 getTransformation(const IEntity<T> &ent) const;
  void pollEvent();
  void pause();
private:
  std::vector<IEntity<T> *> _ents;
  gdl::SdlContext	_context;
  glm::mat4		_camProj;
  glm::mat4		_camTransf;
  gdl::BasicShader	_shader;
  gdl::Input		_input;
  gdl::Texture		_texture;
  gdl::Clock		_clock;

  typedef void	(GDLGUI<T>::*drawFunc)(const IEntity<T> &ent) const;
  std::map<eEntityType, drawFunc> _drawFct;
  AssetsManager		_AM;
};

template <class T>
GDLGUI<T>::GDLGUI()
{
  std::cout << "Starting GUI" << std::endl;
  _drawFct[BOMB] = &GDLGUI<T>::drawBomb;
  _drawFct[MONSTER] = &GDLGUI<T>::drawMonster;
  _drawFct[ARTINT] = &GDLGUI<T>::drawAI;
  _drawFct[BBOMBNUMBER] = &GDLGUI<T>::drawBombNumber;
  _drawFct[BRADIUS] = &GDLGUI<T>::drawRadius;
  _drawFct[FLAME] = &GDLGUI<T>::drawFlame;
  _drawFct[BSPEED] = &GDLGUI<T>::drawSpeed;
  _drawFct[FLOOR] = &GDLGUI<T>::drawFloor;
  _drawFct[BRKWALL] = &GDLGUI<T>::drawBrkWall;
  _drawFct[UBRKWALL] = &GDLGUI<T>::drawUbrkWall;
  _drawFct[PLAYER] = &GDLGUI<T>::drawPlayer;
}

template <class T>
void	GDLGUI<T>::windowInit()
{
  if (!_context.start(1280, 720, "My bomberman!"))
    std::cout << "error window init" << std::endl;
}

template <class T>
void	GDLGUI<T>::cameraInit()
{
  _camProj = glm::perspective(60.0f, 1280.0f / 720.0f, 0.1f, 2000.0f);
  _camTransf = glm::lookAt(T(0, 50, -30), T(0, 0, 0), T(0, 1, 0));
}

template <class T>
void	GDLGUI<T>::shaderInit()
{
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./includes/LibBomberman/shaders/basic.fp", GL_FRAGMENT_SHADER))
    throw ("Error basic.fp");
  if (!_shader.load("./includes/LibBomberman/shaders/basic.vp", GL_VERTEX_SHADER))
    throw ("Error basic.vp");
  if (!_shader.build())
    throw ("Error build");
  _shader.bind();
  _shader.setUniform("view", _camTransf);
  _shader.setUniform("projection", _camProj);
}

template <class T>
void	GDLGUI<T>::soundInit()
{

}

template <class T>
void	GDLGUI<T>::assetsInit()
{
  _AM.init();
}

template <class T>
bool	GDLGUI<T>::update(std::vector<IEntity<T> *> ent)
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  if (_input.getKey(SDLK_LEFT))
    {
      // ent[0]->setRotation(glm::rotate(ent[0]->getRotation(), ent[0]->getRotation().y, glm::vec3(0, 90, 0)));
      ent[0]->setRotation(T(0, 90, 0));
      ent[0]->setPosition(T((ent[0]->getPosition().x + 1), ent[0]->getPosition().y, ent[0]->getPosition().z));
      // translate(glm::vec3(0, 0, 1) * static_cast<float>(_clock.getElapsed()) * (10.0f*4), *ent[0]);
    }
  if (_input.getKey(SDLK_RIGHT))
    {
      // ent[0]->setRotation(glm::rotate(ent[0]->getRotation(), ent[0]->getRotation().y, glm::vec3(0, 270, 0)));
      ent[0]->setRotation(T(0, 270, 0));
      ent[0]->setPosition(T((ent[0]->getPosition().x - 1), ent[0]->getPosition().y, ent[0]->getPosition().z));
      // translate(glm::vec3(0, 0, 1) * static_cast<float>(_clock.getElapsed()) * (10.0f*4), *ent[0]);
    }
  if (_input.getKey(SDLK_UP))
    {
      ent[0]->setRotation(T(0, 0, 0));
      ent[0]->setPosition(T(ent[0]->getPosition().x, ent[0]->getPosition().y, (ent[0]->getPosition().z + 1)));
      // translate(glm::vec3(0, 0, 1) * static_cast<float>(_clock.getElapsed()) * (10.0f*4), *ent[0]);
    }
  if (_input.getKey(SDLK_DOWN))
    {
      ent[0]->setRotation(T(0, 180, 0));
      ent[0]->setPosition(T(ent[0]->getPosition().x, ent[0]->getPosition().y, (ent[0]->getPosition().z - 1)));
      // translate(glm::vec3(0, 0, 1) * static_cast<float>(_clock.getElapsed()) * (10.0f*4), *ent[0]);
    }
  // if (_input.getKey(SDLK_q))
  //   rotate(glm::vec3(, 1, 0) * static_cast<float>(_clock.getElapsed()) * (ent[0]->getSpeed()*4), 90, *ent[0]);
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  (void)ent;
  // for (size_t i = 0; i < ent.size(); i++)
  //   (this->*_drawFct[ent[i]->getType()])(*ent[i]);
  // _camTransf = glm::lookAt(glm::vec3(0, 150, -20), glm::vec3(0, 0, 0),glm::vec3(0, 1, 0));
  // _shader.setUniform("view", _camTransf);
  return true;
}

template <class T>
void	GDLGUI<T>::drawMonster(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw Monster" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawAI(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw AI" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawBombNumber(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw bomb number" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawRadius(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw Radius" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawFlame(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw flame" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawSpeed(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw Speed" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawFloor(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw floor" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawBrkWall(const IEntity<T> &ent) const
{
  (void)ent;
}
#include "unistd.h"

template <class T>
void	GDLGUI<T>::drawUbrkWall(const IEntity<T> &ent) const
{
  gdl::Texture  _texture;
  gdl::Geometry _geometry;
  (void)ent;
  if (_texture.load("./assets/grass.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return;
    }
  // std::cout << "pos = " << ent.getPosX() <<  " " << ent.getPosY() << "  scale = " << ent.getScale().x  << " " << ent.getScale().y << " " << ent.getScale().z << std::endl;
  _geometry.setColor(glm::vec4(0, 1, 0, 1)); // VERT                                                                  
  _geometry.pushVertex(glm::vec3(1, 0.5, 1));
  _geometry.pushVertex(glm::vec3(1, 0.5, -1));
  _geometry.pushVertex(glm::vec3(-1, 0.5, -1));
  _geometry.pushVertex(glm::vec3(-1, 0.5, 1));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();
  _texture.bind();
  _geometry.draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawBomb(const IEntity<T> &ent) const
{
  (void)ent;
}

template <class T>
void	GDLGUI<T>::drawPlayer(const IEntity<T> &ent) const
{
  gdl::Texture texture;
  gdl::Model	model;

  // std::cout << "Player" << std::endl;
  // std::cout << "pos = " << ent.getPosX() <<  " " << ent.getPosY() << "  scale = " << ent.getScale().x  << " " << ent.getScale().y << " " << ent.getScale().z << std::endl;
  _texture.bind();
  _AM.getModel(PLAYER)->draw((gdl::AShader&) _shader, getTransformation(ent), _clock.getElapsed());
  _AM.getModel(PLAYER)->setCurrentAnim(1, false);
}

template <class T>
void	GDLGUI<T>::drawMap(std::map<std::pair<int, int>, IEntity<T> *> entMap)
{
  (void)entMap;
  gdl::Texture  _texture;
  gdl::Geometry _geometry;
  if (_texture.load("./assets/grass.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return;
    }

  typename std::map<std::pair<int, int>, IEntity<T> *>::const_iterator it;

  it = entMap.begin();
  ++it;
  // for (it = entMap.begin(); it != entMap.end(); it++)
  //   {
  //     if (it->second != NULL)
  // 	(this->*_drawFct[it->second->getType()])(*it->second);
  //   }
  _geometry.setColor(glm::vec4(0, 1, 0, 1)); // VERT                                                                  
  _geometry.pushVertex(glm::vec3(1, 0.5, 1));
  _geometry.pushVertex(glm::vec3(1, 0.5, -1));
  _geometry.pushVertex(glm::vec3(-1, 0.5, -1));
  _geometry.pushVertex(glm::vec3(-1, 0.5, 1));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();
  _texture.bind();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  // _shader.setUniform("view", transformation);
  // _shader.setUniform("projection", projection);

  _geometry.draw((gdl::AShader&) _shader, getTransformation(*it->second), GL_QUADS);
  _context.flush();
}

template <class T>
void	GDLGUI<T>::setEntitiesToDraw(std::vector<IEntity<T> *> ent)
{
  _ents = ent;
}

template <class T>
void	GDLGUI<T>::pollEvent()
{

}

template <class T>
void	GDLGUI<T>::pause()
{

}

template <class T>
glm::mat4	GDLGUI<T>::getTransformation(const IEntity<T> &ent) const
{
  glm::mat4	transform(1);

  transform = glm::translate(transform, ent.getPosition());
  transform = glm::rotate(transform, ent.getRotation().x, T(1, 0, 0));
  transform = glm::rotate(transform, ent.getRotation().y, T(0, 1, 0));
  transform = glm::rotate(transform, ent.getRotation().z, T(0, 0, 1));
  transform = glm::scale(transform, ent.getScale());
  return transform;
}

template <class T>
bool GDLGUI<T>::initialize()
{
  return true;
}

template <class T>
bool GDLGUI<T>::update()
{
  std::cout << "update bool" << std::endl;
  return true;
}

template <class T>
void GDLGUI<T>::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; i < _ents.size(); i++)
    (this->*_drawFct[_ents[i]->getType()])(*_ents[i]);
  _context.flush();
}

template <class T>
void	GDLGUI<T>::translate(T const &v, IEntity<T> &ent) const
{
  ent.setPosition(ent.getPosition() + v);
}

template <class T>
void	GDLGUI<T>::rotate(T const &axis, float angle, IEntity<T> &ent) const
{
  ent.setRotation(ent.getRotation() + (axis * angle));
}

template <class T>
void	GDLGUI<T>::drawMenu(const std::string &image)
{
  glm::mat4		transformMenu(1);
  gdl::Geometry		_geometryMenu;
  gdl::Texture		_textureMenu;
  glm::mat4		projection;
  glm::mat4		transformation;

  if (_textureMenu.load(image) == false)
    exit(0);

  _geometryMenu.pushVertex(glm::vec3(40, 0, 0));
  _geometryMenu.pushVertex(glm::vec3(0, 0, 0));
  _geometryMenu.pushVertex(glm::vec3(0, 22, 0));
  _geometryMenu.pushVertex(glm::vec3(40, 22, 0));

  _geometryMenu.pushUv(glm::vec2(0.0f, 0.0f));
  _geometryMenu.pushUv(glm::vec2(1.0f, 0.0f));
  _geometryMenu.pushUv(glm::vec2(1.0f, 1.0f));
  _geometryMenu.pushUv(glm::vec2(0.0f, 1.0f));

  _geometryMenu.build();
  _textureMenu.bind();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  projection = glm::perspective(58.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(T(20, 11, -20), T(20, 11, 0), T(0, 1, 0));

  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  _geometryMenu.draw(_shader, transformMenu, GL_QUADS);
  _context.flush();
}

#endif		/* GDLGUI_HPP_*/
