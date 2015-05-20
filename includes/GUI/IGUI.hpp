#ifndef		IGUI_HPP_
# define	IGUI_HPP_

class IGUI
{
public:
  virtual void windowInit() = 0;
  virtual void cameraInit() = 0;
  virtual void shaderInit() = 0;
  virtual void soundInit() = 0;
  virtual bool update() = 0;
  virtual void draw() = 0;
  virtual void pollEvent() = 0;
  virtual void pause() = 0;
private:
};

#endif		/* IGUI_HPP_ */
