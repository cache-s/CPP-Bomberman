//
// GDLGUI.hpp for bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:30:48 2015 Jordan Chazottes
// Last update Sun Jun 14 23:14:48 2015 Jordan Chazottes
//

#ifndef		GDLGUI_HPP_
# define	GDLGUI_HPP_

# include	<map>
# include	<vector>
# include	<iostream>
# include	<fstream>
# include	<sstream>
# include	<Game.hh>
# include       <glm/glm.hpp>
# include       <glm/gtc/matrix_transform.hpp>
# include	<BasicShader.hh>
# include	<SdlContext.hh>
# include       <Geometry.hh>
# include	<unistd.h>

# include	"IThread.hpp"
# include	"ISafeQueue.hpp"
# include	"ICondVar.hpp"
# include	"IGUI.hpp"
# include	"IEntity.hpp"
# include	"EventManager.hpp"
# include	"AssetsManager.hpp"
# include	"Settings.hpp"

template <typename T>
class	EventManager;

template <typename T>
class GDLGUI : public IGUI<T>, public gdl::Game
{
public:
  GDLGUI(ISafeQueue<IEntity <T> *> &_drawQueue, std::map<std::pair<int, int>, IEntity<T> *> &_entityMap, std::map<std::pair<int, int>, IEntity<T> *> &_characterMap, Settings &settings);
  ~GDLGUI();

  void init();
  void windowInit();
  void cameraInit();
  void shaderInit();
  void soundInit();
  void assetsInit();
  void menuInit();
  bool initialize();
  bool update();
  bool getKey();
  bool getMenuKey();
  void draw();
  void translate(T const &v, IEntity<T> &ent) const;
  void rotate(T const &axis, float angle, IEntity<T> &ent) const;
  void menuLoadTexture(const std::vector<std::string> & image);

  glm::vec3	setCamPos();
  void setEntitiesToDraw(std::vector<IEntity<T> *> ent);
  void drawInit();
  void drawBomb(IEntity<T> &ent);
  void drawBombNumber(IEntity<T> &ent);
  void drawRadius(IEntity<T> &ent);
  void drawFlame(IEntity<T> &ent);
  void drawSpeed(IEntity<T> &ent);
  void drawBrkWall(IEntity<T> &ent);
  void drawUbrkWall(IEntity<T> &ent);
  void drawPlayer(IEntity<T> &ent);
  void drawFloor(IEntity<T> &ent);
  void drawMap(int p);
  void drawMenu(int index);
  void drawNumber(const std::string & number);
  void drawString(const std::string & string, int pos);
  void drawScore(const std::string & score);
  void drawHighScore();

  bool checkRadius(int p, int posX, int posY, int radius) const;
  bool checkRadius(int p, const IEntity<T> &ent, int radius) const;

  void createCube();
  void createFloor();
  void objectInit();
  bool animInit();

  bool inputUp(int p);
  bool inputQuit(int p);
  bool inputRight(int p);
  bool inputDown(int p);
  bool inputLeft(int p);
  bool inputBomb(int p);

  void			getHighScore(int index, std::string & score, std::string & name);
  gdl::SdlContext	getContext() const;
  double    getElapsedTime();
  glm::mat4 getTransformation(const IEntity<T> &ent) const;
  eKey pollEvent();
  eKey menuPollEvent();
  void pause();
private:
  Settings				&_settings;
  gdl::Geometry				_geometryMenu;
  std::vector<gdl::Texture*>		_textureMenu;
  std::vector<IEntity<T> *>		_ents;
  gdl::SdlContext			_context;
  glm::mat4				_camProj;
  glm::mat4				_camTransf;
  gdl::BasicShader			_shader;
  gdl::Input				_input;
  gdl::Texture				_texture;
  gdl::Clock				_clock;
  Factory<glm::vec3>			*_factory;
  Mutex					_updateMutex;
  ICondVar				*_updateCondVar;
  ISafeQueue<IEntity<T> *>		&_drawQueue;
  eKey					_lastKeyPressed;
  double				_time;
  std::map<char, std::string>		_numbers;
  std::map<char, std::string>		_letters;
  gdl::Geometry				*_cube;
  gdl::Geometry				*_floor;
  IEntity<T>				*_p1;
  IEntity<T>				*_p2;
  std::map<std::pair<int, int>, IEntity<T> *> &_charMap;
  std::map<std::pair<int, int>, IEntity<T> *> &_entMap;

  typedef void	(GDLGUI<T>::*drawFunc)(IEntity<T> &ent);
  std::map<eEntityType, drawFunc>	_drawFct;
  typedef bool  (GDLGUI<T>::*inputFunc)(int);
  std::map<int, inputFunc>              _inputFct;
  AssetsManager				_AM;
};

template	<typename T>
void		*draw_routine(void *c);

#include	"GDLGUI.tpp"

#endif		/* GDLGUI_HPP_*/
