#ifndef		IGUI_HPP_
# define	IGUI_HPP_

#include	<iostream>
#include	"IEntity.hpp"

class IGUI
{
public:
  virtual void windowInit() = 0;
  virtual void cameraInit() = 0;
  virtual void shaderInit() = 0;
  virtual void soundInit() = 0;
  virtual bool update() = 0;
  virtual void draw(std::vector<IEntity<glm::vec3> *> _ent) = 0;
  virtual void pollEvent() = 0;
  virtual void pause() = 0;

  virtual void drawBomb() const = 0;
  virtual void drawMonster() const = 0;
  virtual void drawAI() const = 0;
  virtual void drawBombNumber() const = 0;
  virtual void drawRadius() const = 0;  
  virtual void drawFlame() const = 0;  
  virtual void drawSpeed() const = 0;  
  virtual void drawBrkWall() const = 0;
  virtual void drawUbrkWall() const = 0;
  virtual void drawPlayer() const = 0;
};

#endif		/* IGUI_HPP_ */
