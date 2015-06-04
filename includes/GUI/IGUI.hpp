#ifndef		IGUI_HPP_
# define	IGUI_HPP_

#include	<iostream>
#include	"IEntity.hpp"

template <class T>
class IGUI
{
public:
  virtual void windowInit() = 0;
  virtual void cameraInit() = 0;
  virtual void shaderInit() = 0;
  virtual void soundInit() = 0;
  virtual void assetsInit() = 0;
  virtual bool update(std::vector<IEntity<T> *> _ent) = 0;
  virtual void setEntitiesToDraw(std::vector<IEntity<T> *> _ent) = 0;
  virtual void pollEvent() = 0;
  virtual void pause() = 0;
  virtual void translate(T const &v, IEntity<T> &ent) const = 0;
  virtual void rotate(T const &axis, float angle, IEntity<T> &ent) const = 0;

  virtual void drawBomb(const IEntity<T> &ent) const = 0;
  virtual void drawMonster(const IEntity<T> &ent) const = 0;
  virtual void drawAI(const IEntity<T> &ent) const = 0;
  virtual void drawBombNumber(const IEntity<T> &ent) const = 0;
  virtual void drawRadius(const IEntity<T> &ent) const = 0;
  virtual void drawFlame(const IEntity<T> &ent) const = 0;
  virtual void drawSpeed(const IEntity<T> &ent) const = 0;
  virtual void drawBrkWall(const IEntity<T> &ent) const = 0;
  virtual void drawUbrkWall(const IEntity<T> &ent) const = 0;
  virtual void drawPlayer(const IEntity<T> &ent) const = 0;
  virtual void drawFloor(const IEntity<T> &ent) const = 0;
  virtual void drawMap(std::map<std::pair<int, int>, IEntity<T> *> entMap) = 0;
  virtual void drawMenu(const std::string &image) = 0;

  virtual ~IGUI() {};
  virtual glm::mat4 getTransformation(const IEntity<T> &ent) const = 0;
};

#endif		/* IGUI_HPP_ */
