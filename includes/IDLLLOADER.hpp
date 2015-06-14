//
// IDLLLOADER.hpp for Bomberman in /home/chazot_a/rendu/cpp_bomberman/includes
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:14:08 2015 Jordan Chazottes
// Last update Sun Jun 14 21:14:09 2015 Jordan Chazottes
//

#ifndef				IDLLLOADER_HPP_
# define			IDLLLOADER_HPP_

class				IDLLLOADER
{
public:
  virtual void			DLOpen() = 0;
  virtual void			DLClose() = 0;
  virtual void			DLError() = 0;
  virtual void			DLSym() = 0;
};

#endif				//IDLLLOADER_HPP_
