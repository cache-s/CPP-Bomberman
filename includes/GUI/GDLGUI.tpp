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
  _drawFct[MAPWALL] = &GDLGUI<T>::drawUbrkWall;
  _drawFct[UBRKWALL] = &GDLGUI<T>::drawUbrkWall;
  _drawFct[PLAYER] = &GDLGUI<T>::drawPlayer;

  _numbers['0'] = "./assets/menu/0.tga";
  _numbers['1'] = "./assets/menu/1.tga";
  _numbers['2'] = "./assets/menu/2.tga";
  _numbers['3'] = "./assets/menu/3.tga";
  _numbers['4'] = "./assets/menu/4.tga";
  _numbers['5'] = "./assets/menu/5.tga";
  _numbers['6'] = "./assets/menu/6.tga";
  _numbers['7'] = "./assets/menu/7.tga";
  _numbers['8'] = "./assets/menu/8.tga";
  _numbers['9'] = "./assets/menu/9.tga";

  _letters['A'] = "./assets/menu/a.tga";
  _letters['B'] = "./assets/menu/b.tga";
  _letters['C'] = "./assets/menu/c.tga";
  _letters['D'] = "./assets/menu/d.tga";
  _letters['E'] = "./assets/menu/e.tga";
  _letters['F'] = "./assets/menu/f.tga";
  _letters['G'] = "./assets/menu/g.tga";
  _letters['H'] = "./assets/menu/h.tga";
  _letters['I'] = "./assets/menu/i.tga";
  _letters['J'] = "./assets/menu/j.tga";
  _letters['K'] = "./assets/menu/k.tga";
  _letters['L'] = "./assets/menu/l.tga";
  _letters['M'] = "./assets/menu/m.tga";
  _letters['N'] = "./assets/menu/n.tga";
  _letters['O'] = "./assets/menu/o.tga";
  _letters['P'] = "./assets/menu/p.tga";
  _letters['Q'] = "./assets/menu/q.tga";
  _letters['R'] = "./assets/menu/r.tga";
  _letters['S'] = "./assets/menu/s.tga";
  _letters['T'] = "./assets/menu/t.tga";
  _letters['U'] = "./assets/menu/u.tga";
  _letters['V'] = "./assets/menu/v.tga";
  _letters['W'] = "./assets/menu/w.tga";
  _letters['X'] = "./assets/menu/x.tga";
  _letters['Y'] = "./assets/menu/y.tga";
  _letters['Z'] = "./assets/menu/z.tga";

  _inputFct[0] = &GDLGUI<T>::inputUp;
  _inputFct[1] = &GDLGUI<T>::inputQuit;
  _inputFct[2] = &GDLGUI<T>::inputRight;
  _inputFct[3] = &GDLGUI<T>::inputDown;
  _inputFct[4] = &GDLGUI<T>::inputLeft;
  _inputFct[5] = &GDLGUI<T>::inputBomb;
  _p1 = characterMap[std::make_pair(-1, -1)];
  _p2 = characterMap[std::make_pair(-2, -2)];
  initialize();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawMap();
  _context.flush();
}
template <typename T>
bool	GDLGUI<T>::getMenuKey()
{
  _lastKeyPressed = NONE;
  for (size_t i = 0; i < _inputFct.size(); i++)
    (this->*_inputFct[i])(1);
  for (size_t j = 0; j < _inputFct.size(); j++)
    (this->*_inputFct[j])(2);
  if (_lastKeyPressed == NONE)
    return false;
  return true;
}

template <typename T>
bool    GDLGUI<T>::inputQuit(int p)
{
  (void)p;
  if (_input.getKey(SDLK_ESCAPE, true) || _input.getInput(SDL_QUIT, true))
    {
      _lastKeyPressed = QUIT;
      return (true);
    }
  return (false);
}

template <typename T>
bool    GDLGUI<T>::inputLeft(int p)
{
  if (p == 1 && _input.getKey(SDLK_LEFT, true))
    {
      _lastKeyPressed = LEFT1;
      return (true);
    }
  if (p == 2 && _input.getKey(SDLK_q, true))
    {
      _lastKeyPressed = LEFT2;
      return (true);
    }
  return (false);
}

template <typename T>
bool    GDLGUI<T>::inputRight(int p)
{
  if (p == 1 && _input.getKey(SDLK_RIGHT, true))
    {
      _lastKeyPressed = RIGHT1;
      return (true);
    }
  if (p == 2 && _input.getKey(SDLK_d, true))
    {
      _lastKeyPressed = RIGHT2;
      return (true);
    }
  return (false);
}

template <typename T>
bool    GDLGUI<T>::inputDown(int p)
{
  if (p == 1 && _input.getKey(SDLK_DOWN, true))
    {
      _lastKeyPressed = DOWN1;
      return (true);
    }
  if (p == 2 && _input.getKey(SDLK_s, true))
    {
      _lastKeyPressed = DOWN2;
      return (true);
    }
  return (false);
}

template <typename T>
bool    GDLGUI<T>::inputUp(int p)
{
  if (p == 1 && _input.getKey(SDLK_UP, true))
    {
      _lastKeyPressed = UP1;
      return (true);
    }
  if (p == 2 && _input.getKey(SDLK_z, true))
    {
      _lastKeyPressed = UP2;
      return (true);
    }
  return (false);
}

template <typename T>
bool    GDLGUI<T>::inputBomb(int p)
{
  if (p == 1 && _input.getKey(SDLK_KP_0, true))
    {
      _lastKeyPressed = BOMB1;
      return (true);
    }
  if (p == 2 && (_input.getKey(SDLK_SPACE, true) || _input.getKey(SDLK_RETURN, true)))
    {
      _lastKeyPressed = BOMB2;
      return (true);
    }
  return (false);
}

template <typename T>
bool    GDLGUI<T>::getKey()
{
  _updateCondVar->wait();
  _lastKeyPressed = NONE;
  for (size_t i = 0; i < _inputFct.size(); i++)
    (this->*_inputFct[i])(1);
  for (size_t j = 0; j < _inputFct.size(); j++)
    (this->*_inputFct[j])(2);
  if (_lastKeyPressed == NONE)
    return false;
  return true;
}

template <typename T>
GDLGUI<T>::~GDLGUI()
{
  delete _floor;
  delete _cube;
  delete _factory;
  delete _updateCondVar;
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
void    GDLGUI<T>::draw(void)
{
  //IEntity<T> *ent;
  //_shader.bind();
  //while ((_drawQueue.tryPop(&ent)) == true)
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0, 0, 640, 360);
  drawMap();
  _camTransf = glm::lookAt(glm::vec3((_p1->getPosition().x*10)+1, (_p1->getPosition().y*10)+100, _p1->getPosition().z*10-50), glm::vec3(_p1->getPosition().x * 10+0, _p1->getPosition().y, _p1->getPosition().z * 10), glm::vec3(0, 1, 0));
  _shader.setUniform("view", _camTransf);
  glViewport(480, 0, 640, 360);
  drawMap();
  _camTransf = glm::lookAt(glm::vec3((_p2->getPosition().x*10)+1, (_p2->getPosition().y*10)+100, _p2->getPosition().z*10-50), glm::vec3(_p2->getPosition().x * 10+0, _p2->getPosition().y, _p2->getPosition().z * 10), glm::vec3(0, 1, 0));
  // _camTransf = glm::lookAt(glm::vec3(_p2->getPosX(), _p2->getPosY() + 100, -100), _p2->getPosition(), glm::vec3(0, 1, 0));
  _shader.setUniform("view", _camTransf);
  _context.flush();
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
  _camTransf = glm::lookAt(glm::vec3((_p1->getPosition().x*10)+1, (_p1->getPosition().y*10)+100, _p1->getPosition().z*10-50), glm::vec3(_p1->getPosition().x * 10+0, _p1->getPosition().y, _p1->getPosition().z * 10), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", _camTransf);
  _shader.setUniform("projection", _camProj);
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

template <class T>
void	GDLGUI<T>::drawString(const std::string & string, int pos)
{
  glm::mat4		transform(1);
  gdl::Texture		texture;

  gdl::Geometry		geometryUpArrow;
  gdl::Geometry		geometryDownArrow;

  gdl::Geometry		geometryLetter1;

  gdl::Geometry		geometryLetter2;

  gdl::Geometry		geometryLetter3;

  int			x1;
  int			x2;

  if (pos == 0)
    {
      x1 = 13;
      x2 = 11;
    }
  if (pos == 1)
    {
      x1 = 11;
      x2 = 9;
    }
  if (pos == 2)
    {
      x1 = 9;
      x2 = 7;
    }
  geometryUpArrow.pushVertex(glm::vec3(x1, 11, -1));
  geometryUpArrow.pushVertex(glm::vec3(x2, 11, -1));
  geometryUpArrow.pushVertex(glm::vec3(x2, 13, -1));
  geometryUpArrow.pushVertex(glm::vec3(x1, 13, -1));
  geometryUpArrow.pushUv(glm::vec2(0.0f, 0.0f));
  geometryUpArrow.pushUv(glm::vec2(1.0f, 0.0f));
  geometryUpArrow.pushUv(glm::vec2(1.0f, 1.0f));
  geometryUpArrow.pushUv(glm::vec2(0.0f, 1.0f));
  geometryUpArrow.build();

  geometryDownArrow.pushVertex(glm::vec3(x1, 7, -1));
  geometryDownArrow.pushVertex(glm::vec3(x2, 7, -1));
  geometryDownArrow.pushVertex(glm::vec3(x2, 9, -1));
  geometryDownArrow.pushVertex(glm::vec3(x1, 9, -1));
  geometryDownArrow.pushUv(glm::vec2(0.0f, 0.0f));
  geometryDownArrow.pushUv(glm::vec2(1.0f, 0.0f));
  geometryDownArrow.pushUv(glm::vec2(1.0f, 1.0f));
  geometryDownArrow.pushUv(glm::vec2(0.0f, 1.0f));
  geometryDownArrow.build();

  geometryLetter1.pushVertex(glm::vec3(13, 9, -1));
  geometryLetter1.pushVertex(glm::vec3(11, 9, -1));
  geometryLetter1.pushVertex(glm::vec3(11, 11, -1));
  geometryLetter1.pushVertex(glm::vec3(13, 11, -1));
  geometryLetter1.pushUv(glm::vec2(0.0f, 0.0f));
  geometryLetter1.pushUv(glm::vec2(1.0f, 0.0f));
  geometryLetter1.pushUv(glm::vec2(1.0f, 1.0f));
  geometryLetter1.pushUv(glm::vec2(0.0f, 1.0f));
  geometryLetter1.build();

  geometryLetter2.pushVertex(glm::vec3(11, 9, -1));
  geometryLetter2.pushVertex(glm::vec3(9, 9, -1));
  geometryLetter2.pushVertex(glm::vec3(9, 11, -1));
  geometryLetter2.pushVertex(glm::vec3(11, 11, -1));
  geometryLetter2.pushUv(glm::vec2(0.0f, 0.0f));
  geometryLetter2.pushUv(glm::vec2(1.0f, 0.0f));
  geometryLetter2.pushUv(glm::vec2(1.0f, 1.0f));
  geometryLetter2.pushUv(glm::vec2(0.0f, 1.0f));
  geometryLetter2.build();

  geometryLetter3.pushVertex(glm::vec3(9, 9, -1));
  geometryLetter3.pushVertex(glm::vec3(7, 9, -1));
  geometryLetter3.pushVertex(glm::vec3(7, 11, -1));
  geometryLetter3.pushVertex(glm::vec3(9, 11, -1));
  geometryLetter3.pushUv(glm::vec2(0.0f, 0.0f));
  geometryLetter3.pushUv(glm::vec2(1.0f, 0.0f));
  geometryLetter3.pushUv(glm::vec2(1.0f, 1.0f));
  geometryLetter3.pushUv(glm::vec2(0.0f, 1.0f));
  geometryLetter3.build();

  /*DRAW DES FLECHES*/
  if (texture.load("./assets/menu/UpArrow.tga") == false)
    exit(0);//throw
  texture.bind();
  geometryUpArrow.draw(_shader, transform, GL_QUADS);
  if (texture.load("./assets/menu/DownArrow.tga") == false)
    exit(0);//throw
  texture.bind();
  geometryDownArrow.draw(_shader, transform, GL_QUADS);

  /*DRAW DES LETTRES*/
  if (texture.load(_letters[string[0]]) == false)
    exit(0);//throw
  texture.bind();
  geometryLetter1.draw(_shader, transform, GL_QUADS);
  if (texture.load(_letters[string[1]]) == false)
    exit(0);//throw
  texture.bind();
  geometryLetter2.draw(_shader, transform, GL_QUADS);
  if (texture.load(_letters[string[2]]) == false)
    exit(0);//throw
  texture.bind();
  geometryLetter3.draw(_shader, transform, GL_QUADS);
  _context.flush();
}

template <class T>
void	GDLGUI<T>::drawNumber(const std::string & number)
{
  glm::mat4		transformNumber(1);
  gdl::Geometry		geometryLeftArrow;
  gdl::Geometry		geometryRightArrow;
  gdl::Geometry		geometryNumber1;
  gdl::Geometry		geometryNumber2;
  gdl::Geometry		geometryNumber3;
  gdl::Texture		textureNumber;

  geometryRightArrow.pushVertex(glm::vec3(4, 12, -1));
  geometryRightArrow.pushVertex(glm::vec3(2, 12, -1));
  geometryRightArrow.pushVertex(glm::vec3(2, 14, -1));
  geometryRightArrow.pushVertex(glm::vec3(4, 14, -1));
  geometryRightArrow.pushUv(glm::vec2(0.0f, 0.0f));
  geometryRightArrow.pushUv(glm::vec2(1.0f, 0.0f));
  geometryRightArrow.pushUv(glm::vec2(1.0f, 1.0f));
  geometryRightArrow.pushUv(glm::vec2(0.0f, 1.0f));
  geometryRightArrow.build();

  geometryLeftArrow.pushVertex(glm::vec3(12, 12, -1));
  geometryLeftArrow.pushVertex(glm::vec3(10, 12, -1));
  geometryLeftArrow.pushVertex(glm::vec3(10, 14, -1));
  geometryLeftArrow.pushVertex(glm::vec3(12, 14, -1));
  geometryLeftArrow.pushUv(glm::vec2(0.0f, 0.0f));
  geometryLeftArrow.pushUv(glm::vec2(1.0f, 0.0f));
  geometryLeftArrow.pushUv(glm::vec2(1.0f, 1.0f));
  geometryLeftArrow.pushUv(glm::vec2(0.0f, 1.0f));
  geometryLeftArrow.build();

  geometryNumber1.pushVertex(glm::vec3(6, 12, -1));
  geometryNumber1.pushVertex(glm::vec3(4, 12, -1));
  geometryNumber1.pushVertex(glm::vec3(4, 14, -1));
  geometryNumber1.pushVertex(glm::vec3(6, 14, -1));
  geometryNumber1.pushUv(glm::vec2(0.0f, 0.0f));
  geometryNumber1.pushUv(glm::vec2(1.0f, 0.0f));
  geometryNumber1.pushUv(glm::vec2(1.0f, 1.0f));
  geometryNumber1.pushUv(glm::vec2(0.0f, 1.0f));
  geometryNumber1.build();

  geometryNumber2.pushVertex(glm::vec3(8, 12, -1));
  geometryNumber2.pushVertex(glm::vec3(6, 12, -1));
  geometryNumber2.pushVertex(glm::vec3(6, 14, -1));
  geometryNumber2.pushVertex(glm::vec3(8, 14, -1));
  geometryNumber2.pushUv(glm::vec2(0.0f, 0.0f));
  geometryNumber2.pushUv(glm::vec2(1.0f, 0.0f));
  geometryNumber2.pushUv(glm::vec2(1.0f, 1.0f));
  geometryNumber2.pushUv(glm::vec2(0.0f, 1.0f));
  geometryNumber2.build();

  geometryNumber3.pushVertex(glm::vec3(10, 12, -1));
  geometryNumber3.pushVertex(glm::vec3(8, 12, -1));
  geometryNumber3.pushVertex(glm::vec3(8, 14, -1));
  geometryNumber3.pushVertex(glm::vec3(10, 14, -1));
  geometryNumber3.pushUv(glm::vec2(0.0f, 0.0f));
  geometryNumber3.pushUv(glm::vec2(1.0f, 0.0f));
  geometryNumber3.pushUv(glm::vec2(1.0f, 1.0f));
  geometryNumber3.pushUv(glm::vec2(0.0f, 1.0f));
  geometryNumber3.build();

  if (textureNumber.load("./assets/menu/leftArrowSelected.tga") == false)
    exit(0);//throw
  textureNumber.bind();
  geometryLeftArrow.draw(_shader, transformNumber, GL_QUADS);
  if (textureNumber.load("./assets/menu/rightArrowSelected.tga") == false)
    exit(0);//throw
  textureNumber.bind();
  geometryRightArrow.draw(_shader, transformNumber, GL_QUADS);

  if (textureNumber.load(_numbers[number[2]]) == false)
    exit(0);//throw
  textureNumber.bind();
  geometryNumber1.draw(_shader, transformNumber, GL_QUADS);
  if (textureNumber.load(_numbers[number[1]]) == false)
    exit(0);//throw
  textureNumber.bind();
  geometryNumber2.draw(_shader, transformNumber, GL_QUADS);
  if (textureNumber.load(_numbers[number[0]]) == false)
    exit(0);//throw
  textureNumber.bind();
  geometryNumber3.draw(_shader, transformNumber, GL_QUADS);
}

template <class T>
void    GDLGUI<T>::drawScore(const std::string & score)
{
  glm::mat4		transformNumber(1);
  gdl::Geometry		geometryNumber1;
  gdl::Geometry		geometryNumber2;
  gdl::Geometry		geometryNumber3;
  gdl::Texture		textureNumber;

  geometryNumber1.pushVertex(glm::vec3(13, 13, -1));
  geometryNumber1.pushVertex(glm::vec3(11, 13, -1));
  geometryNumber1.pushVertex(glm::vec3(11, 15, -1));
  geometryNumber1.pushVertex(glm::vec3(13, 15, -1));
  geometryNumber1.pushUv(glm::vec2(0.0f, 0.0f));
  geometryNumber1.pushUv(glm::vec2(1.0f, 0.0f));
  geometryNumber1.pushUv(glm::vec2(1.0f, 1.0f));
  geometryNumber1.pushUv(glm::vec2(0.0f, 1.0f));
  geometryNumber1.build();

  geometryNumber2.pushVertex(glm::vec3(11, 13, -1));
  geometryNumber2.pushVertex(glm::vec3(9, 13, -1));
  geometryNumber2.pushVertex(glm::vec3(9, 15, -1));
  geometryNumber2.pushVertex(glm::vec3(11, 15, -1));
  geometryNumber2.pushUv(glm::vec2(0.0f, 0.0f));
  geometryNumber2.pushUv(glm::vec2(1.0f, 0.0f));
  geometryNumber2.pushUv(glm::vec2(1.0f, 1.0f));
  geometryNumber2.pushUv(glm::vec2(0.0f, 1.0f));
  geometryNumber2.build();

  geometryNumber3.pushVertex(glm::vec3(9, 13, -1));
  geometryNumber3.pushVertex(glm::vec3(7, 13, -1));
  geometryNumber3.pushVertex(glm::vec3(7, 15, -1));
  geometryNumber3.pushVertex(glm::vec3(9, 15, -1));
  geometryNumber3.pushUv(glm::vec2(0.0f, 0.0f));
  geometryNumber3.pushUv(glm::vec2(1.0f, 0.0f));
  geometryNumber3.pushUv(glm::vec2(1.0f, 1.0f));
  geometryNumber3.pushUv(glm::vec2(0.0f, 1.0f));
  geometryNumber3.build();

  if (textureNumber.load(_numbers[score[2]]) == false)
    exit(0);//throw
  textureNumber.bind();
  geometryNumber1.draw(_shader, transformNumber, GL_QUADS);
  if (textureNumber.load(_numbers[score[1]]) == false)
    exit(0);//throw
  textureNumber.bind();
  geometryNumber2.draw(_shader, transformNumber, GL_QUADS);
  if (textureNumber.load(_numbers[score[0]]) == false)
    exit(0);//throw
  textureNumber.bind();
  geometryNumber3.draw(_shader, transformNumber, GL_QUADS);
}

template <class T>
void    GDLGUI<T>::getHighScore(int index, std::string & score, std::string & name)
{
  std::ifstream file (".highScore.txt");
  std::ostringstream    oss117;
  std::string           line;

  if (file.is_open())
    {
      while (getline(file,line) && index-- != 0);
      oss117 << line[0] << line[1] << line[2];
      name = oss117.str();
      oss117.str("");
      oss117 << line[3] << line[4] << line[5];
      score = oss117.str();
      file.close();
    }
}

template <class T>
void    GDLGUI<T>::drawHighScore()
{
  glm::mat4             transform(1);
  gdl::Texture          texture;
  int                   y1 = 13;
  int                   y2 = 15;
  std::string           name;
  std::string           score;

  for (unsigned int i = 0; i < 3; ++i)
    {
      gdl::Geometry             geometryLetter1;
      gdl::Geometry             geometryLetter2;
      gdl::Geometry             geometryLetter3;
      gdl::Geometry             geometryNumber1;
      gdl::Geometry             geometryNumber2;
      gdl::Geometry             geometryNumber3;

      getHighScore(i, score, name);
      geometryNumber1.pushVertex(glm::vec3(18, y1, -1));
      geometryNumber1.pushVertex(glm::vec3(16, y1, -1));
      geometryNumber1.pushVertex(glm::vec3(16, y2, -1));
      geometryNumber1.pushVertex(glm::vec3(18, y2, -1));
      geometryNumber1.pushUv(glm::vec2(0.0f, 0.0f));
      geometryNumber1.pushUv(glm::vec2(1.0f, 0.0f));
      geometryNumber1.pushUv(glm::vec2(1.0f, 1.0f));
      geometryNumber1.pushUv(glm::vec2(0.0f, 1.0f));
      geometryNumber1.build();

      geometryNumber2.pushVertex(glm::vec3(16, y1, -1));
      geometryNumber2.pushVertex(glm::vec3(14, y1, -1));
      geometryNumber2.pushVertex(glm::vec3(14, y2, -1));
      geometryNumber2.pushVertex(glm::vec3(16, y2, -1));
      geometryNumber2.pushUv(glm::vec2(0.0f, 0.0f));
      geometryNumber2.pushUv(glm::vec2(1.0f, 0.0f));
      geometryNumber2.pushUv(glm::vec2(1.0f, 1.0f));
      geometryNumber2.pushUv(glm::vec2(0.0f, 1.0f));
      geometryNumber2.build();

      geometryNumber3.pushVertex(glm::vec3(14, y1, -1));
      geometryNumber3.pushVertex(glm::vec3(12, y1, -1));
      geometryNumber3.pushVertex(glm::vec3(12, y2, -1));
      geometryNumber3.pushVertex(glm::vec3(14, y2, -1));
      geometryNumber3.pushUv(glm::vec2(0.0f, 0.0f));
      geometryNumber3.pushUv(glm::vec2(1.0f, 0.0f));
      geometryNumber3.pushUv(glm::vec2(1.0f, 1.0f));
      geometryNumber3.pushUv(glm::vec2(0.0f, 1.0f));
      geometryNumber3.build();

      if (texture.load(_numbers[score[2]]) == false)
        exit(0);//throw
      texture.bind();
      geometryNumber1.draw(_shader, transform, GL_QUADS);
      if (texture.load(_numbers[score[1]]) == false)
        exit(0);//throw
      texture.bind();
      geometryNumber2.draw(_shader, transform, GL_QUADS);
      if (texture.load(_numbers[score[0]]) == false)
        exit(0);//throw
      texture.bind();
      geometryNumber3.draw(_shader, transform, GL_QUADS);

      geometryLetter1.pushVertex(glm::vec3(27, y1, -1));
      geometryLetter1.pushVertex(glm::vec3(25, y1, -1));
      geometryLetter1.pushVertex(glm::vec3(25, y2, -1));
      geometryLetter1.pushVertex(glm::vec3(27, y2, -1));
      geometryLetter1.pushUv(glm::vec2(0.0f, 0.0f));
      geometryLetter1.pushUv(glm::vec2(1.0f, 0.0f));
      geometryLetter1.pushUv(glm::vec2(1.0f, 1.0f));
      geometryLetter1.pushUv(glm::vec2(0.0f, 1.0f));
      geometryLetter1.build();

      geometryLetter2.pushVertex(glm::vec3(25, y1, -1));
      geometryLetter2.pushVertex(glm::vec3(23, y1, -1));
      geometryLetter2.pushVertex(glm::vec3(23, y2, -1));
      geometryLetter2.pushVertex(glm::vec3(25, y2, -1));
      geometryLetter2.pushUv(glm::vec2(0.0f, 0.0f));
      geometryLetter2.pushUv(glm::vec2(1.0f, 0.0f));
      geometryLetter2.pushUv(glm::vec2(1.0f, 1.0f));
      geometryLetter2.pushUv(glm::vec2(0.0f, 1.0f));
      geometryLetter2.build();

      geometryLetter3.pushVertex(glm::vec3(23, y1, -1));
      geometryLetter3.pushVertex(glm::vec3(21, y1, -1));
      geometryLetter3.pushVertex(glm::vec3(21, y2, -1));
      geometryLetter3.pushVertex(glm::vec3(23, y2, -1));
      geometryLetter3.pushUv(glm::vec2(0.0f, 0.0f));
      geometryLetter3.pushUv(glm::vec2(1.0f, 0.0f));
      geometryLetter3.pushUv(glm::vec2(1.0f, 1.0f));
      geometryLetter3.pushUv(glm::vec2(0.0f, 1.0f));
      geometryLetter3.build();

      if (texture.load(_letters[name[0]]) == false)
        exit(0);//throw
      texture.bind();
      geometryLetter1.draw(_shader, transform, GL_QUADS);
      if (texture.load(_letters[name[1]]) == false)
        exit(0);//throw
      texture.bind();
      geometryLetter2.draw(_shader, transform, GL_QUADS);
      if (texture.load(_letters[name[2]]) == false)
        exit(0);//throw
      texture.bind();
      geometryLetter3.draw(_shader, transform, GL_QUADS);
      y1 -= 3;
      y2 -= 3;
    }
}


template <typename T>
gdl::SdlContext		GDLGUI<T>::getContext() const
{
  return (_context);
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
glm::vec3 GDLGUI<T>::setCamPos()
{
  glm::vec3 ret;
  ret = _p1->getPosition();
  ret.x += 1;
  ret.y += 90;
  ret.z += 70;
  return ret;
}

template <class T>
void	GDLGUI<T>::drawMonster(IEntity<T> &ent)
{
  (void)ent;
  std::cout << "draw Monster" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawAI(IEntity<T> &ent)
{
  (void)ent;
  std::cout << "draw AI" << std::endl;
}

template <class T>
void	GDLGUI<T>::drawBombNumber(IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(BBOMBNUMBER);

  std::cout << "drawbombnumber" << std::endl;
  if (!ent.isDraw())
    _cube->build();
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawRadius(IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(BRADIUS);

  std::cout << "drawRadius" << std::endl;
  if (!ent.isDraw())
    _cube->build();
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawSpeed(IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(BSPEED);

  std::cout << "drawSpeed" << std::endl;
  if (!ent.isDraw())
    _cube->build();
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawFlame(IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(FLAME);

  if (!ent.isDraw())
    _cube->build();
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawFloor(IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(FLOOR);
  

  if (!ent.isDraw())
    {
      _floor->build();
      ent.setIsDraw(true);
    }
  texture->bind();
  _floor->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawBrkWall(IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(BRKWALL);
  
  if (!ent.isDraw())
    {
      _cube->build();
      ent.setIsDraw(true);
    }
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawUbrkWall(IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(UBRKWALL);
 
  if (!ent.isDraw())
    {
      _cube->build();
      ent.setIsDraw(true);
    }
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <class T>
void	GDLGUI<T>::drawBomb(IEntity<T> &ent)
{
  gdl::Texture *  texture = _AM.getTexture(BOMB);
   
  if (!ent.isDraw())
    {
      _cube->build();
      ent.setIsDraw(true);
    }
  texture->bind();
  _cube->draw((gdl::AShader&) _shader, getTransformation(ent), GL_QUADS);
}

template <typename T>
void	GDLGUI<T>::drawPlayer(IEntity<T> &ent)
{
  gdl::Texture texture;
  gdl::Model	model;

  _texture.bind();
  _AM.getModel(PLAYER)->setCurrentAnim(1, false);
  _AM.getModel(PLAYER)->draw((gdl::AShader&) _shader, getTransformation(ent), _clock.getElapsed());
}

template <typename T>
void	GDLGUI<T>::drawMap()
{
  typename std::map<std::pair<int, int>, IEntity<T> *>::const_iterator it_e;
  typename std::map<std::pair<int, int>, IEntity<T> *>::const_iterator it_p;

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
    if (it_p->second != NULL)
      (this->*_drawFct[it_p->second->getType()])(*it_p->second);
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
  animInit();
  objectInit();
  return true;
}

template <typename T>
bool GDLGUI<T>::animInit()
{
  _AM.getModel(PLAYER)->createSubAnim(0, "start", 0, 36);
  _AM.getModel(PLAYER)->createSubAnim(0, "run", 36, 53);
  _AM.getModel(PLAYER)->createSubAnim(0, "end", 53, 120);
  _AM.getModel(PLAYER)->createSubAnim(0, "noMove", 0, 0);
  return (true);
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
}


template <typename T>
double		GDLGUI<T>::getElapsedTime()
{
  return (_time + _clock.getElapsed());
}
