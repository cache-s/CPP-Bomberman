#ifndef		IGUI_HPP_
# define	IGUI_HPP_

#include	<iostream>
#include	"IEntity.hpp"
#include	"EventManager.hpp"
#include	"eKey.hpp"

template <class T>
class EventManager;

template <typename T>
class IGUI
{
public:
  virtual void windowInit() = 0;
  virtual void cameraInit() = 0;
  virtual void shaderInit() = 0;
  virtual void soundInit() = 0;
  virtual void assetsInit() = 0;
  virtual void menuInit() = 0;
  virtual bool update() = 0;
  virtual void setEntitiesToDraw(std::vector<IEntity<T> *> _ent) = 0;
  virtual eKey pollEvent() = 0;
  virtual eKey menuPollEvent() = 0;
  virtual void pause() = 0;
  virtual void translate(T const &v, IEntity<T> &ent) const = 0;
  virtual void rotate(T const &axis, float angle, IEntity<T> &ent) const = 0;
  virtual void menuLoadTexture(const std::vector<std::string> & images) = 0;
  virtual gdl::SdlContext getContext() const = 0;

  virtual void draw() = 0;
  virtual void drawBomb(IEntity<T> &ent) = 0;
  virtual void drawMonster(IEntity<T> &ent) = 0;
  virtual void drawAI(IEntity<T> &ent) = 0;
  virtual void drawBombNumber(IEntity<T> &ent) = 0;
  virtual void drawRadius(IEntity<T> &ent) = 0;
  virtual void drawFlame(IEntity<T> &ent) = 0;
  virtual void drawSpeed(IEntity<T> &ent) = 0;
  virtual void drawBrkWall(IEntity<T> &ent) = 0;
  virtual void drawUbrkWall(IEntity<T> &ent) = 0;
  virtual void drawPlayer(IEntity<T> &ent) = 0;
  virtual void drawFloor(IEntity<T> &ent) = 0;
  virtual void drawMap() = 0;
  virtual void drawMenu(int i) = 0;
  virtual void drawNumber(const std::string & number) = 0;
  virtual void drawString(const std::string & string, int pos) = 0;

  virtual double getElapsedTime() = 0;
  virtual ~IGUI() {};
  virtual glm::mat4 getTransformation(const IEntity<T> &ent) const = 0;
};

#endif		/* IGUI_HPP_ */
