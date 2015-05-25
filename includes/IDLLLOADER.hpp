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
