// Advent of Code 2016 Day 9

#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::ostringstream uncompressedString{""};

	std::string curLine;
	while (std::getline(std::cin, curLine)) {
		for (unsigned int i = 0; i < curLine.length(); ++i) {
			if (curLine[i] == '\n') continue;
			if (curLine[i] == '(') {
				// get start of marker
				unsigned int markerStart{i};

				// get end of marker
				while (i < curLine.length() && curLine[i] != ')') {
					++i;
				}
				unsigned int markerEnd{i};
				++i; // move index beyond closing paren

				// process marker
				std::string marker{curLine.substr(markerStart, markerEnd - markerStart)};
				std::string::size_type separator{marker.find('x')};

				int data{std::stoi(marker.substr(1, separator - 1))};
				int repeat{std::stoi(marker.substr(separator + 1, marker.length() - separator))};

				// get data to repeat
				std::string dataToRepeat{curLine.substr(markerEnd + 1, data)};

				// write repeated data
				for (int j = 0; j < repeat; ++j) {
					uncompressedString << dataToRepeat;
				}

				// move index beyond repeated data
				i += data - 1;

			} else {
				uncompressedString << curLine[i];
			}
		}
	}

	std::cout << uncompressedString.str().length() << std::endl;

	return 0;
}
