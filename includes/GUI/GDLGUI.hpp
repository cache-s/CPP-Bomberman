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
# include	<unistd.h>
# include	"IThread.hpp"
# include	"ISafeQueue.hpp"
# include	"ICondVar.hpp"
# include	"IGUI.hpp"
# include	"IEntity.hpp"
# include	"EventManager.hpp"
# include	"AssetsManager.hpp"

template <typename T>
class	EventManager;

template <typename T>
class GDLGUI : public IGUI<T>, public gdl::Game
{
public:
  GDLGUI(ISafeQueue<IEntity <T> *> &_drawQueue, ICondVar &_drawCondVar, std::map<std::pair<int, int>, IEntity<T> *> &_entityMap, std::map<std::pair<int, int>, IEntity<T> *> &_characterMap);
  ~GDLGUI();

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

  void setEntitiesToDraw(std::vector<IEntity<T> *> ent);
  void drawInit();
  void drawBomb(const IEntity<T> &ent);
  void drawMonster(const IEntity<T> &ent);
  void drawAI(const IEntity<T> &ent);
  void drawBombNumber(const IEntity<T> &ent);
  void drawRadius(const IEntity<T> &ent);
  void drawFlame(const IEntity<T> &ent);
  void drawSpeed(const IEntity<T> &ent);
  void drawBrkWall(const IEntity<T> &ent);
  void drawUbrkWall(const IEntity<T> &ent);
  void drawPlayer(const IEntity<T> &ent);
  void drawFloor(const IEntity<T> &ent);
  void drawMap(std::map<std::pair<int, int>, IEntity<T> *> entMap, std::map<std::pair<int, int>, IEntity<T> *> characterMap);
  void drawMenu(int i);

  void createCube();
  void createFloor();
  void objectInit();

  double    getElapsedTime();
  glm::mat4 getTransformation(const IEntity<T> &ent) const;
  eKey pollEvent();
  eKey menuPollEvent();
  void pause();
private:
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
  ICondVar				&_drawCondVar;
  Mutex					_updateMutex;
  ICondVar				*_updateCondVar;
  ISafeQueue<IEntity<T> *>		&_drawQueue;
  IThread				*_GUIThread;
  eKey					_lastKeyPressed;
  double				_time;
  gdl::Geometry				*_cube;
  gdl::Geometry				*_floor;
  IEntity<T>				*_p1;
  IEntity<T>				*_p2;

  typedef void	(GDLGUI<T>::*drawFunc)(const IEntity<T> &ent);
  std::map<eEntityType, drawFunc>	_drawFct;
  AssetsManager				_AM;
};

template	<typename T>
void		*draw_routine(void *c);

#include	"GDLGUI.tpp"

#endif		/* GDLGUI_HPP_*/
