# include <string>
# include <iostream>
# include <cctype>

bool super = false;

void help() {
	std::cout << "Usage:\n";
	std::cout << "Nerdify [options] [string]\n";
	std::cout << "\t-h --help: print Nerdify documentation\n";
	std::cout << "\t-s --super: add '!11!!!' at the end of the string\n";
}

char upper(char lower) {
	return static_cast<char>(std::toupper(static_cast<unsigned char>(lower)));
}

void nerdify(std::string &str) {
	for (int i = 0; i < str.size(); i++) {
		if (i % 2 == 0) {
			str[i] = upper(str[i]);
		}
	}

	if (super) {
		str += "!11!!!";
	}
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		help();
	}

	for (int current_arg = 1; current_arg < argc; current_arg++) {
		std::string arg = argv[current_arg]; // create a proper std::string
		if (arg == "-h" || arg == "--help") {
			help();
			continue;
		}
		if (arg == "-s" || arg == "--super") {
			super = true;
			continue;
		}

		nerdify(arg);             // pass by reference
		std::cout << arg << "\n"; // print modified string
	}

	return 0;
}
