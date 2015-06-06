#include			"MenuManager.hpp"

MenuManager::MenuManager(GDLGUI<glm::vec3>* gui, Settings* settings)
{
  _settings = settings;
  _gui = gui;
}

MenuManager::~MenuManager()
{

}
