# include <string>
# include <iostream>

bool super = false;

void help() {
	
	// Helper function to print usage of the program

	std::cout << "Usage:\n";
	std::cout << "Nerdify [options] [string]\n";
	std::cout << "\t-h --help: print Nerdify documentation\n";
	std::cout << "\t-s --super: add '!11!!!' at the end of the string\n";
}

std::string lower_chars = "abcdefghijklmnopqrstuvwxyz";
std::string upper_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char upper(char lower) {
    auto index = lower_chars.find(lower);
    if (index == std::string::npos) {
		// If character is not found it's a symbol or a number, ignore it.
        return lower;
    }
    return upper_chars[index];
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
		return 0;
	}

	for (int current_arg = 1; current_arg < argc; current_arg++) {
		std::string arg = argv[current_arg];
		if (arg == "-h" || arg == "--help") {
			help();
			continue;
		}
		if (arg == "-s" || arg == "--super") {
			super = true;
			continue;
		}

		nerdify(arg);
		std::cout << arg << "\n";
	}

	return 0;
}
