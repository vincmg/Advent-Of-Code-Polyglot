// Advent of Code 2016 Day 9

#include <iostream>
#include <string>

long int decompress(const std::string& line)
{
	if (line.empty()) return 0;

	long int count{0};
	for (unsigned int i = 0; i < line.length(); ++i) {
		if (line[i] == '\n') continue;

		if (line[i] == '(') {
			// get start of marker
			unsigned int markerStart{i};

			// get end of marker
			while (i < line.length() && line[i] != ')') {
				++i;
			}
			unsigned int markerEnd{i};
			++i; // move index beyond closing paren

			// process marker
			std::string marker{line.substr(markerStart, markerEnd - markerStart)};
			std::string::size_type separator{marker.find('x')};

			int data{std::stoi(marker.substr(1, separator - 1))};
			int repeat{std::stoi(marker.substr(separator + 1, marker.length() - separator))};

			// get data to repeat
			std::string dataToRepeat{line.substr(markerEnd + 1, data)};

			// decompress recursively and add to char count
			count += repeat * decompress(dataToRepeat);

			// move index beyond repeated data
			i += data - 1;

		} else {
			++count;
		}
	}

	return count;
}

int main()
{
	long int count{0};
	std::string curLine;
	while (std::getline(std::cin, curLine)) {
		count += decompress(curLine);
	}

	std::cout << count << std::endl;

	return 0;
}
