#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 4 || std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty())
	{
		std::cerr << "Bad arguments"<< std::endl;
		return 1;
	}
	std::ifstream inputFile(argv[1]);
	if (inputFile.is_open())
	{
		std::ostringstream buffer;
		buffer << inputFile.rdbuf();
		std::string fileContent = buffer.str();
		inputFile.close();
		
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		
		size_t pos = 0;
		while ((pos = fileContent.find(s1, pos)) != std::string::npos)
		{
			fileContent.erase(pos, s1.length());
			fileContent.insert(pos, s2);
			pos += s2.length();
		}
		
		std::string outputFilename = std::string(argv[1]) + ".replace";
		std::ofstream outputFile(outputFilename.c_str());
		if (outputFile.is_open())
		{
			outputFile << fileContent;
			outputFile.close();
		}
		else
		{
			std::cerr << "Could not create output file" << std::endl;
			return 1;
		}
	}
	else
	{
		std::cerr << "file can not open" << std::endl;
		return 1;
	}
}