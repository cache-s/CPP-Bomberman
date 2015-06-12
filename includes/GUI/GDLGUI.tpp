template <typename T>
GDLGUI<T>::GDLGUI(ISafeQueue<IEntity <T> *> &drawQueue, std::map<std::pair<int, int>, IEntity<T> *> &entityMap, std::map<std::pair<int, int>, IEntity<T> *> &characterMap) : _drawQueue(drawQueue), _charMap(characterMap), _entMap(entityMap)
{
  _floor = new gdl::Geometry();
  _cube = new gdl::Geometry();
  _factory = new Factory<T>();
  _lastKeyPressed = NONE;
  _time = 0;
  _updateCondVar = new CondVar(_updateMutex);
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
  initialize();
  drawMap();
}

template <class T>
void	GDLGUI<T>::createCube()
{
  _cube->pushVertex(glm::vec3(0.5 , -0.5, 0.5));
  _cube->pushVertex(glm::vec3(0.5 , 0.5, 0.5));
  _cube->pushVertex(glm::vec3(-0.5 , 0.5, 0.5));
  _cube->pushVertex(glm::vec3(-0.5 , -0.5, 0.5));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));

  _cube->pushVertex(glm::vec3(0.5 , -0.5, -0.5));  
  _cube->pushVertex(glm::vec3(0.5 , 0.5, -0.5));
  _cube->pushVertex(glm::vec3(-0.5 , 0.5, -0.5));
  _cube->pushVertex(glm::vec3(-0.5 , -0.5, -0.5));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));
  
  _cube->pushVertex(glm::vec3(0.5 , -0.5, -0.5));
  _cube->pushVertex(glm::vec3(0.5 , 0.5, -0.5));
  _cube->pushVertex(glm::vec3(0.5 , 0.5, 0.5));
  _cube->pushVertex(glm::vec3(0.5 , -0.5, 0.5));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));
  
  _cube->pushVertex(glm::vec3(-0.5 , -0.5, 0.5));
  _cube->pushVertex(glm::vec3(-0.5 , 0.5, 0.5));
  _cube->pushVertex(glm::vec3(-0.5 , 0.5, -0.5));
  _cube->pushVertex(glm::vec3(-0.5 , -0.5, -0.5));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));
  
  _cube->pushVertex(glm::vec3(0.5 , 0.5, 0.5));
  _cube->pushVertex(glm::vec3(0.5 , 0.5, -0.5));
  _cube->pushVertex(glm::vec3(-0.5 , 0.5, -0.5));
  _cube->pushVertex(glm::vec3(-0.5 , 0.5, 0.5));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));
  
  _cube->pushVertex(glm::vec3(0.5 , -0.5, -0.5));
  _cube->pushVertex(glm::vec3(0.5 , -0.5, 0.5));
  _cube->pushVertex(glm::vec3(-0.5 , -0.5, 0.5));
  _cube->pushVertex(glm::vec3(-0.5 , -0.5, -0.5));
  _cube->pushUv(glm::vec2(0.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 0.0f));
  _cube->pushUv(glm::vec2(1.0f, 1.0f));
  _cube->pushUv(glm::vec2(0.0f, 1.0f));
  _cube->build();
}

template <class T>
void	GDLGUI<T>::createFloor()
{
  _floor->pushVertex(glm::vec3(0.5 , -0.5, -0.5));
  _floor->pushVertex(glm::vec3(0.5 , -0.5, 0.5));
  _floor->pushVertex(glm::vec3(-0.5 , -0.5, 0.5));
  _floor->pushVertex(glm::vec3(-0.5 , -0.5, -0.5));
  _floor->pushUv(glm::vec2(0.0f, 0.0f));
  _floor->pushUv(glm::vec2(1.0f, 0.0f));
  _floor->pushUv(glm::vec2(1.0f, 1.0f));
  _floor->pushUv(glm::vec2(0.0f, 1.0f));
  _floor->build();
}

template <class T>
void	GDLGUI<T>::objectInit()
{
  createCube();
  createFloor();
}

template <typename T>
GDLGUI<T>::~GDLGUI()
{

}

template <typename T>
void    GDLGUI<T>::draw(void)
{
  //IEntity<T> *ent;

  //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //_shader.bind();
  //while ((_drawQueue.tryPop(&ent)) == true)
    drawMap();
  //_context.flush();
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
  _camTransf = glm::lookAt(T(100, 200, -70), T(100, 0, 100), T(0, 1, 0));
  // _camTransf = glm::lookAt(T(100, 200, -60), T(100, 0, 0), T(0, 1, 0));
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

template <class T>
void	GDLGUI<T>::menuInit()
{
  glm::mat4		projection;
  glm::mat4		transformation;

  //CAMERA
  projection = glm::perspective(58.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(T(20, 11, -20), T(20, 11, 0), T(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  //GEOMETRY
  _geometryMenu.pushVertex(glm::vec3(40, 0, 0));
  _geometryMenu.pushVertex(glm::vec3(0, 0, 0));
  _geometryMenu.pushVertex(glm::vec3(0, 22, 0));
  _geometryMenu.pushVertex(glm::vec3(40, 22, 0));
  _geometryMenu.pushUv(glm::vec2(0.0f, 0.0f));
  _geometryMenu.pushUv(glm::vec2(1.0f, 0.0f));
  _geometryMenu.pushUv(glm::vec2(1.0f, 1.0f));
  _geometryMenu.pushUv(glm::vec2(0.0f, 1.0f));
  _geometryMenu.build();
}

template <typename T>
bool	GDLGUI<T>::update()
{
  _time += _clock.getElapsed();
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  _updateCondVar->signal();
  _shader.bind();
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
glm::vec3 GDLGUI<T>::setCamPos()
{
  glm::vec3 ret;
  ret = _p1->getPosition();
  ret.x += 1;
  ret.y += 90;
  ret.z += 70;
  return ret;
}


template <typename T>
bool	GDLGUI<T>::getMenuKey()
{
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

template <class T>
void	GDLGUI<T>::drawMonster(const IEntity<T> &ent)
{
  (void)ent;
  std::cout << "draw Monster" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawAI(const IEntity<T> &ent)
{
  (void)ent;
  std::cout << "draw AI" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawBombNumber(const IEntity<T> &ent)
{
  (void)ent;
  std::cout << "draw bomb number" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawRadius(const IEntity<T> &ent)
{
  (void)ent;
  std::cout << "draw Radius" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawFlame(const IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(FLAME);
  
  _cube->build();
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawSpeed(const IEntity<T> &ent)
{
  (void)ent;
  std::cout << "draw Speed" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawFloor(const IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(FLOOR);
  
  _floor->build();
  texture->bind();
  _floor->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawBrkWall(const IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(BRKWALL);
  
  _cube->build();
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawUbrkWall(const IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(UBRKWALL);
  
  _cube->build();
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawBomb(const IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(BOMB);
  
  _cube->build();
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <typename T>
void	GDLGUI<T>::drawPlayer(const IEntity<T> &ent)
{
  gdl::Texture texture;
  gdl::Model	model;

  _texture.bind();
  _AM.getModel(PLAYER)->draw((gdl::AShader&) _shader, getTransformation(ent), _clock.getElapsed());
  _AM.getModel(PLAYER)->setCurrentAnim(1, false);
}

template <typename T>
void	GDLGUI<T>::drawMap()
{
  typename std::map<std::pair<int, int>, IEntity<T> *>::const_iterator it_e;
  typename std::map<std::pair<int, int>, IEntity<T> *>::const_iterator it_p;
  static int once = 0;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  it_e = _entMap.begin();
  for (it_e = _entMap.begin(); it_e != _entMap.end(); it_e++)
    {
      if (it_e->second != NULL)
	(this->*_drawFct[it_e->second->getType()])(*it_e->second);
      else
	(this->*_drawFct[FLOOR])(*(_factory->createEntity(FLOOR, std::get<0>(it_e->first), std::get<1>(it_e->first))));  
    }
  it_p = _charMap.begin();
  for (it_p = _charMap.begin(); it_p != _charMap.end(); it_p++)
    {
      if (it_p->second != NULL)
	{
	  (this->*_drawFct[it_p->second->getType()])(*it_p->second);
	  if (once == 0)
	    _p1 = it_p->second;
	  if (once == 1)
	    _p2 = it_p->second;
	  once++;
	}
    }
  // _camTransf = glm::lookAt(setCamPos(), _p1->getPosition(), glm::vec3(0, 1, 0));
  // _shader.setUniform("view", _camTransf);
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
eKey	GDLGUI<T>::menuPollEvent()
{
  while (getMenuKey() == false)
    {
      _context.updateInputs(_input);
      usleep(1000);
    }
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

  if (ent.getType() != PLAYER)
    transform = glm::translate(transform, ent.getPosition() * ent.getScale());
  else
    transform = glm::translate(transform, ent.getPosition() * T(10, 10, 10));
  transform = glm::rotate(transform, ent.getRotation().x, T(1, 0, 0));
  transform = glm::rotate(transform, ent.getRotation().y, T(0, 1, 0));
  transform = glm::rotate(transform, ent.getRotation().z, T(0, 0, 1));
  transform = glm::scale(transform, ent.getScale());
  return transform;
}

template <typename T>
bool GDLGUI<T>::initialize()
{
  windowInit();
  cameraInit();
  shaderInit();
  soundInit();
  assetsInit();
  objectInit();
  return true;
}

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

template <class T>
void    GDLGUI<T>::menuLoadTexture(const std::vector<std::string> & images)
{
  //DELETE OLD VECTOR
  for (unsigned int i = 0; i < _textureMenu.size(); ++i)
    delete _textureMenu[i];
  _textureMenu.clear();

  //LOAD TEXTURE
  for (unsigned int i = 0; i < images.size(); ++i)
    {
      _textureMenu.push_back(new gdl::Texture());
      if (_textureMenu[i]->load(images[i]) == false)
        exit(0);//throw
    }
}

template <class T>
void	GDLGUI<T>::drawMenu(int i)
{
  glm::mat4		transformMenu(1);

  std::cout << "MENU" << std::endl;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _textureMenu[i]->bind();
  _geometryMenu.draw(_shader, transformMenu, GL_QUADS);
  _context.flush();
}


template <typename T>
double		GDLGUI<T>::getElapsedTime()
{
  return (_time + _clock.getElapsed());
}
