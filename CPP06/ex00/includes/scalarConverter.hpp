#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cctype>
# include <climits>
# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>
# include <float.h>

# define RESET "\e[0m"
# define RED "\e[31m"

// static functions do not need an object to be called.
// non static functions need an object to be called.
class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();

	static bool isChar(const std::string &str);
	static bool isInt(const std::string &str);
	static bool isFloat(const std::string &str);
	static bool isDouble(const std::string &str);

	static void charConverter(const std::string &str);
	static void intConverter(const std::string &str);
	static void floatConverter(const std::string &str);
	static void doubleConverter(const std::string &str);

  public:
	static void convert(std::string strType);
};
#endif