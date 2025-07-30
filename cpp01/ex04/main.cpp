#include <string>
#include <iostream>
#include <fstream>

std::string manageLine(std::string line, char **argv)
{
	std::string s1 = argv[2];
	std::string s2 = argv[3]; 
	std::string result = line;
	
	size_t pos = 0;
	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result.erase(pos, s1.length());
		result.insert(pos, s2);         
		pos += s2.length();            
	}
	
	return result + "\n";
}

int main(int argc, char **argv)
{
	std::string allOfFile;
	std::string line;
	if (argc != 4)
	{
		std::cerr << "Bad arguments"<< std::endl;
		return 1;
	}
	std::ifstream inputFile(argv[1]);
	if (inputFile.is_open())
	{
		while(std::getline(inputFile, line))
		{
			allOfFile += manageLine(line, argv);
		}
		inputFile.close();
		std::string outputFilename = std::string(argv[1]) + ".replace";
		std::ofstream outputFile(outputFilename.c_str());
		if (outputFile.is_open())
		{
			outputFile << allOfFile;
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