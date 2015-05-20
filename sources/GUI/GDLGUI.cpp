#include		"GDLGUI.hpp"

GDLGUI::GDLGUI()
{
  std::cout << "Starting GUI" << std::endl;
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

void	GDLGUI::draw()
{

}

void	GDLGUI::pollEvent()
{

}

void	GDLGUI::pause()
{

}
