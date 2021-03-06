//
// IEntity.hpp for bomberman in /home/chazot_a/rendu/cpp_bomberman/includes
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:24:23 2015 Jordan Chazottes
// Last update Sun Jun 14 21:24:24 2015 Jordan Chazottes
//

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

template <typename T>
class			IEntity
{
public:
  virtual double	getPosX() const = 0;
  virtual double	getPosY() const = 0;
  virtual double	getHitboxSize() const = 0;
  virtual bool		isBreakable() const = 0;
  virtual T		getPosition() const = 0;
  virtual T		getRotation() const = 0;
  virtual T		getScale() const = 0;
  virtual float		getSpeed() const = 0;
  virtual bool		isCrossable() const = 0;

  virtual void		setIsCrossable(bool isCrossable) = 0;
  virtual void		setHitboxSize(double hitbox) = 0;
  virtual void		setIsBreakable(bool breakable) = 0;
  virtual void		setPosition(const T &pos) = 0;
  virtual void		setRotation(const T &pos) = 0;
  virtual void		setScale(const T &pos) = 0;
  virtual void		setPosX(double x) = 0;
  virtual void		setPosY(double y) = 0;
  virtual void		setSpeed(float speed) = 0;

  virtual bool		isDraw() const = 0;
  virtual void		setIsDraw(bool isDraw) = 0;
  virtual eEntityType	getType() const = 0;
  virtual IEntity<T>	*clone(double x, double y) = 0;

  virtual ~IEntity() {};
};

#endif			/* IENTITY_HPP_ */
