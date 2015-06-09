//
// GDLGUI.tpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Tue Jun  9 23:09:51 2015 Martin Porrès
// Last update Tue Jun  9 23:10:40 2015 Martin Porrès
//


template <typename T>
GDLGUI<T>::GDLGUI(ISafeQueue<IEntity <T> *> &drawQueue, ICondVar &drawCondVar, std::map<std::pair<int, int>, IEntity<T> *> &entityMap, std::map<std::pair<int, int>, IEntity<T> *> &characterMap) : _drawCondVar(drawCondVar), _drawQueue(drawQueue)
{
  std::cout << "Starting GUI" << std::endl;
  _lastKeyPressed = NONE;
  _time = 0;
  _updateCondVar = new CondVar(_updateMutex);
  _GUIThread = new Thread();
  _GUIThread->create(&draw_routine<T>, reinterpret_cast<void *>(this));
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
  windowInit();
  cameraInit();
  shaderInit();
  soundInit();
  assetsInit();
  drawMap(entityMap);
  drawMap(characterMap);
}

template <typename T>
GDLGUI<T>::~GDLGUI()
{
  _GUIThread->cancel();
}

template	<typename T>
void		*draw_routine(void *c)
{
  reinterpret_cast<GDLGUI<T> *>(c)->draw();
  return (NULL);
}

template <typename T>
void    GDLGUI<T>::draw(void)
{
  IEntity<T> *ent;
  
  (void)ent;
  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // _shader.bind();
  while (true)
    {
      _drawCondVar.wait();
      while ((_drawQueue.tryPop(&ent)) == true)
        {
          (this->*_drawFct[ent->getType()])(*ent);
          _context.flush();
        }
    }
}

template <typename T>
void	GDLGUI<T>::windowInit()
{
  if (!_context.start(1280, 720, "My bomberman!"))
    std::cout << "error window init" << std::endl;
}

template <typename T>
void	GDLGUI<T>::cameraInit()
{
  _camProj = glm::perspective(60.0f, 1280.0f / 720.0f, 0.1f, 2000.0f);
  _camTransf = glm::lookAt(T(0, 50, -30), T(0, 0, 0), T(0, 1, 0));
}

template <typename T>
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

template <typename T>
void	GDLGUI<T>::soundInit()
{

}

template <typename T>
void	GDLGUI<T>::assetsInit()
{
  _AM.init();
}

template <typename T>
bool	GDLGUI<T>::update()
{
  _time += _clock.getElapsed();
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  _updateCondVar->signal();
  return (true);
}

template <typename T>
bool	GDLGUI<T>::getKey()
{
  _updateCondVar->wait();
  _lastKeyPressed = NONE;
  if (_input.getKey(SDLK_ESCAPE, true) || _input.getInput(SDL_QUIT, true))
    _lastKeyPressed = QUIT;
  if (_input.getKey(SDLK_LEFT, true))
    _lastKeyPressed = LEFT1;
  if (_input.getKey(SDLK_RIGHT, true))
    _lastKeyPressed = RIGHT1;
  if (_input.getKey(SDLK_UP, true))
    _lastKeyPressed = UP1;
  if (_input.getKey(SDLK_DOWN, true))
    _lastKeyPressed = DOWN1;
  if (_input.getKey(SDLK_SPACE, true))
    _lastKeyPressed = BOMB1;
  if (_lastKeyPressed == NONE)
    return false;
  return true;
}

template <typename T>
void	GDLGUI<T>::drawMonster(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw Monster" << std::endl;
}

template <typename T>
void	GDLGUI<T>::drawAI(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw AI" << std::endl;
}

template <typename T>
void	GDLGUI<T>::drawBombNumber(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw bomb number" << std::endl;
}

template <typename T>
void	GDLGUI<T>::drawRadius(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw Radius" << std::endl;
}

template <typename T>
void	GDLGUI<T>::drawFlame(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw flame" << std::endl;
}

template <typename T>
void	GDLGUI<T>::drawSpeed(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw Speed" << std::endl;
}

template <typename T>
void	GDLGUI<T>::drawFloor(const IEntity<T> &ent) const
{
  (void)ent;
  std::cout << "draw floor" << std::endl;
}

template <typename T>
void	GDLGUI<T>::drawBrkWall(const IEntity<T> &ent) const
{
  (void)ent;
}
#include "unistd.h"

template <typename T>
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

template <typename T>
void	GDLGUI<T>::drawBomb(const IEntity<T> &ent) const
{
  (void)ent;
}

template <typename T>
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

template <typename T>
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

template <typename T>
void	GDLGUI<T>::setEntitiesToDraw(std::vector<IEntity<T> *> ent)
{
  _ents = ent;
}

template <typename T>
eKey	GDLGUI<T>::pollEvent()
{
  while (getKey() == false);
  return (_lastKeyPressed);
}

template <typename T>
void	GDLGUI<T>::pause()
{

}

template <typename T>
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

template <typename T>
bool GDLGUI<T>::initialize()
{
  return true;
}

// template <typename T>
// bool GDLGUI<T>::update()
// {
//   std::cout << "update bool" << std::endl;
//   return true;
// }

// template <typename T>
// void GDLGUI<T>::draw()
// {
//   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//   _shader.bind();
//   for (size_t i = 0; i < _ents.size(); i++)
//     (this->*_drawFct[_ents[i]->getType()])(*_ents[i]);
//   _context.flush();
// }

template <typename T>
void	GDLGUI<T>::translate(T const &v, IEntity<T> &ent) const
{
  ent.setPosition(ent.getPosition() + v);
}

template <typename T>
void	GDLGUI<T>::rotate(T const &axis, float angle, IEntity<T> &ent) const
{
  ent.setRotation(ent.getRotation() + (axis * angle));
}

template <typename T>
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

template <typename T>
double		GDLGUI<T>::getElapsedTime()
{
  return (_time + _clock.getElapsed());
}
