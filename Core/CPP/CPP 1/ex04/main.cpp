#include <iostream>
#include <fstream>
#include <sstream>

// void ft_replace(std::string str, std::string new_str, size_t start, size_t old_length, size_t new_length)
// {
// 	str.erase(start, old_length);
// 	str.insert(start, new_str);
// 	std::cout << str << std::endl; 
// }


int main(int argc, char **argv)
{ 

	if (argc != 4)
	{
		std::cout << "please provide the correct amount of arguments" << std::endl;
		return (1);
	}
	std::string 	file = argv[1];
	std::string		str1 = argv[2];
	std::string		str2 = argv[3];
	std::string		buffer;
	std::size_t		found;
	std::ifstream 	ifs(file);

	if (!ifs.is_open())
	{
		std::cout << "could not open file"  <<std::endl;
		return (1);
	}
	std::ofstream 	ofs(file + ".replace");
	while (std::getline(ifs, buffer))
	{
		while (buffer.find(str1) != std::string::npos && str1 != str2)
		{
			found = buffer.find(str1);
			buffer.erase(found, str1.length());
			buffer.insert(found, str2);
		}
		ofs << buffer << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}
