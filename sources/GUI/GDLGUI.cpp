#include		"GDLGUI.hpp"

GDLGUI::GDLGUI()
{
  std::cout << "Starting GUI" << std::endl;
  _drawFct[BOMB] = &GDLGUI::drawBomb;
  _drawFct[MONSTER] = &GDLGUI::drawMonster;
  _drawFct[ARTINT] = &GDLGUI::drawAI;
  _drawFct[BOMBNUMBER] = &GDLGUI::drawBombNumber;
  _drawFct[RADIUS] = &GDLGUI::drawRadius;
  _drawFct[FLAME] = &GDLGUI::drawFlame;
  _drawFct[SPEED] = &GDLGUI::drawSpeed;
  _drawFct[BRKWALL] = &GDLGUI::drawBrkWall;
  _drawFct[UBRKWALL] = &GDLGUI::drawUbrkWall;
  _drawFct[PLAYER] = &GDLGUI::drawPlayer;
}

void	GDLGUI::windowInit()
{
  if (!_context.start(1280, 720, "My bomberman!"))
    throw ("Error starting");
}

void	GDLGUI::cameraInit()
{
  glEnable(GL_DEPTH_TEST);
  _camProj = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  _camTransf = glm::lookAt(glm::vec3(0, 100, -20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
}

void	GDLGUI::shaderInit()
{
  if (!_shader.load("./includes/LibBomberman/shaders/basic.fp", GL_FRAGMENT_SHADER))
    throw ("Error basic.fp");
  if (!_shader.load("./includes/LibBomberman/shaders/basic.vp", GL_VERTEX_SHADER))
    throw ("Error basic.vp");
  if (!_shader.build())
    throw ("Error build");
  _shader.bind();
  _shader.setUniform("view", _camTransf);
  _shader.setUniform("projection", _camProj);
}

void	GDLGUI::soundInit()
{

}

bool	GDLGUI::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  return true;
}

void	GDLGUI::drawBomb() const
{
  std::cout << "draw bomb" << std::endl;
}

void	GDLGUI::drawMonster() const
{
  std::cout << "draw Monster" << std::endl;
}

void	GDLGUI::drawAI() const
{
  std::cout << "draw AI" << std::endl;
}

void	GDLGUI::drawBombNumber() const
{
  std::cout << "draw bomb number" << std::endl;
}

void	GDLGUI::drawRadius() const
{
  std::cout << "draw Radius" << std::endl;
}

void	GDLGUI::drawFlame() const
{
  std::cout << "draw flame" << std::endl;
}

void	GDLGUI::drawSpeed() const
{
  std::cout << "draw Speed" << std::endl;
}

void	GDLGUI::drawBrkWall() const
{
  std::cout << "draw brk wall" << std::endl;
}

void	GDLGUI::drawUbrkWall() const
{
  std::cout << "draw ubrk wall" << std::endl;
}

void	GDLGUI::drawPlayer() const
{
  std::cout << "draw Player" << std::endl;
}

void	GDLGUI::drawMenu() const
{
  std::cout << "draw Menu" << std::endl;
}

void	GDLGUI::draw(std::vector<IEntity<glm::vec3> *> _ent)
{
  for (size_t i = 0; i < _ent.size(); i++)
    (this->*_drawFct[_ent[i]->getType()])();
}

void	GDLGUI::pollEvent()
{

}

void	GDLGUI::pause()
{

}
