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
    AI,
    BOMBNUMBER,
    RADIUS,
    FLAME,
    SPEED,
    BRKWALL,
    UBRKWALL,
    PLAYER,
  };

class			IEntity
{
public:
  virtual int		getPosX() const = 0;  
  virtual int		getPosY() const = 0;  
  virtual eEntityType	getType() const = 0;
};

#endif			/* IENTITY_HPP_ */
