#include "../includes/scalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isChar(const std::string &str)
{
	if (str.length() != 1)
		return (false);
	if (!isprint(static_cast<unsigned char>(str[0])))
		return (false);
	if (isdigit(static_cast<unsigned char>(str[0])))
		return (false);
	return (true);
}

bool ScalarConverter::isInt(const std::string &str)
{
	size_t	i;
	long	value;

	i = 0;
	if (str.empty())
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return (false);
	while (i < str.length())
	{
		if (!isdigit(static_cast<unsigned char>(str[i])))
			return (false);
		i++;
	}
	value = atol(str.c_str());
	if (value > INT_MAX || value < INT_MIN)
		return (false);
	return (true);
}

bool ScalarConverter::isFloat(const std::string &str)
{
	size_t	i;
	int		dotCount;

	if (str == "nanf" || str == "+inff" || str == "-inff")
		return (true);
	if (str.empty())
		return (false);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return (false);
	if (str[str.length() - 1] != 'f' && str[str.length() - 1] != 'F')
		return (false);
	std::string core = str.substr(i, str.length() - i - 1);
	if (core.empty())
		return (false);
	dotCount = 0;
	for (size_t j = 0; j < core.length(); j++)
	{
		if (core[j] == '.')
			dotCount++;
		else if (!isdigit(static_cast<unsigned char>(core[j])))
			return (false);
	}
	if (dotCount != 1)
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string &str)
{
	size_t	i;
	int		dotCount;

	if (str == "nan" || str == "+inf" || str == "-inf")
		return (true);
	if (str.empty())
		return (false);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return (false);
	std::string core = str.substr(i);
	if (core.empty())
		return (false);
	dotCount = 0;
	for (size_t j = 0; j < core.length(); j++)
	{
		if (core[j] == '.')
			dotCount++;
		else if (!isdigit(static_cast<unsigned char>(core[j])))
			return (false);
	}
	if (dotCount > 1)
		return (false);
	return (true);
}

bool	ScalarConverter::validDecimalPrecision(const std::string &str, size_t maxDecimals)
{
	size_t	dotPos;
	size_t	decimals;

	dotPos = str.find('.');
	if (dotPos == std::string::npos)
		return (true);
	decimals = 0;
	for (size_t i = dotPos + 1; i < str.length(); ++i)
	{
		if (isdigit(static_cast<unsigned char>(str[i])))
			decimals++;
		else
			break ;
	}
	return (decimals <= maxDecimals);
}

void ScalarConverter::charConverter(const std::string &str)
{
	double	value;
	char	c;

	std::cout << "char: ";
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff"
		|| str == "-inf" || str == "-inff")
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isChar(str))
	{
		std::cout << "'" << str[0] << "'" << std::endl;
		return ;
	}
	value = strtod(str.c_str(), NULL);
	if (value < 0 || value > 127 || !validDecimalPrecision(str, 8))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	c = static_cast<char>(value);
	if (!isprint(static_cast<unsigned char>(c)))
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::intConverter(const std::string &str)
{
	double	value;
	int		i;

	std::cout << "int: ";
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff"
		|| str == "-inf" || str == "-inff")
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isChar(str))
	{
		value = static_cast<int>(str[0]);
		std::cout << value << std::endl;
		return ;
	}
	if (isInt(str))
	{
		std::cout << str << std::endl;
		return ;
	}
	value = strtod(str.c_str(), NULL);
	if (value < INT_MIN || value > INT_MAX || !validDecimalPrecision(str, 8))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	i = static_cast<int>(value);
	std::cout << i << std::endl;
}

void ScalarConverter::floatConverter(const std::string &str)
{
	double	value;
	float	f;

	std::cout << "float: ";
	if (str == "nan" || str == "nanf")
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (str == "+inf" || str == "+inff")
	{
		std::cout << "+inff" << std::endl;
		return ;
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "-inff" << std::endl;
		return ;
	}
	if (isChar(str))
		value = static_cast<double>(str[0]);
	else
		value = strtod(str.c_str(), NULL);
	if (value < INT_MIN || value > INT_MAX || !validDecimalPrecision(str, 8))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	f = static_cast<float>(value);
	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::doubleConverter(const std::string &str)
{
	double	value;

	std::cout << "double: ";
	if (str == "nan" || str == "nanf")
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (str == "+inf" || str == "+inff")
	{
		std::cout << "+inf" << std::endl;
		return ;
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "-inf" << std::endl;
		return ;
	}
	if (isChar(str))
		value = static_cast<double>(str[0]);
	else
		value = strtod(str.c_str(), NULL);
	if (value < INT_MIN || value > INT_MAX || !validDecimalPrecision(str, 8))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(std::string strType)
{
	if (!isChar(strType) && !isInt(strType) && !isFloat(strType)
		&& !isDouble(strType))
	{
		std::cout << RED "Error: The input is not a literal type. Try a char, \
			int, float or double" RESET
					<< std::endl;
		return ;
	}
	charConverter(strType);
	intConverter(strType);
	floatConverter(strType);
	doubleConverter(strType);
}
