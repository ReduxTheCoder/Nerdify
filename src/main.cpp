# include <string>
# include <iostream>

void help() {
	std::cout << "Usage:\n";
	std::cout << "Nerdify [options] [string]\n";
	std::cout << "\t-h --help: print Nerdify documentation\n";
	std::cout << "\t-s --super: add '!11!!!' at the end of the string\n";
}

int main(int argc, char* argv[]) {
	if (argc < 2 || argv[1] == "-h" || argv[1] == "--help") {
		help();
	}

	return 0;
}
