#include <iostream>


int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; ++i) {
		for (int j = 0; argv[i][j] != '\0'; ++j) {
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z') {
				std::cout << char(argv[i][j] - ('a' - 'A'));
			} else {
				std::cout << argv[i][j];
			}
		}
		if (i < argc - 1) {
			std::cout << " ";
		}
	}
	
	std::cout << std::endl;
	return 0;
}