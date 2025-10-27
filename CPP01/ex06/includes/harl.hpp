#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class harlFilter
{
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

  public:
    void complain(std::string level);

};
    int getLevel(std::string level);

#endif