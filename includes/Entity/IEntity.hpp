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
    BOMB,
    MONSTER,
    ARTINT,
    BOMBNUMBER,
    RADIUS,
    FLAME,
    SPEED,
    BRKWALL,
    UBRKWALL,
    PLAYER,
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

  virtual void		setHitboxSize(int hitbox) = 0;
  virtual void		setIsBreakable(bool breakable) = 0;
  virtual void		setPosition(T pos) = 0;
  virtual void		setRotation(T pos) = 0;
  virtual void		setScale(T pos) = 0;

  virtual eEntityType	getType() const = 0;
  virtual IEntity<T>	*clone(int x, int y) = 0;
};

#endif			/* IENTITY_HPP_ */
