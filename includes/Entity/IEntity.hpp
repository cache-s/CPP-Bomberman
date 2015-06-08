#ifndef			IENTITY_HPP_
# define		IENTITY_HPP_

#include		<OpenGL.hh>
#include		<Game.hh>
#include		<SdlContext.hh>
#include		<Geometry.hh>
#include		<Texture.hh>
#include		<BasicShader.hh>
#include		<Model.hh>
#include		<glm/glm.hpp>
#include		 <glm/gtc/matrix_transform.hpp>
#include		"IObs.hpp"

enum			eEntityType
  {
    FLOOR = 0,
    BRKWALL = 1,
    UBRKWALL = 2,
    MAPWALL = 3,
    BBOMBNUMBER = 10,
    BSPEED = 11,
    BRADIUS = 12,

    PLAYER = 20,
    ARTINT = 21,
    MONSTER = 22,
    FLAME = 31,
    BOMB = 32,
  };

template <class T>
class			IEntity
{
public:
  virtual int		getPosX() const = 0;
  virtual int		getPosY() const = 0;
  virtual int		getHitboxSize() const = 0;
  virtual bool		isBreakable() const = 0;
  virtual T		getPosition() const = 0;
  virtual T		getRotation() const = 0;
  virtual T		getScale() const = 0;
  virtual float		getSpeed() const = 0;

  virtual void		setHitboxSize(int hitbox) = 0;
  virtual void		setIsBreakable(bool breakable) = 0;
  virtual void		setPosition(const T &pos) = 0;
  virtual void		setRotation(const T &pos) = 0;
  virtual void		setScale(const T &pos) = 0;
  virtual void		setPosX(int x) = 0;
  virtual void		setPosY(int y) = 0;
  virtual void		setSpeed(float speed) = 0;

  virtual eEntityType	getType() const = 0;
  virtual IEntity<T>	*clone(int x, int y) = 0;

  virtual ~IEntity() {};
};

#endif			/* IENTITY_HPP_ */
