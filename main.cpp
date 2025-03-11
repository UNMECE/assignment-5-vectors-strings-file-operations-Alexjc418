#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <pixel.h>

void read_pixels(const std::string &file_name, std::vector<Pixel> &pixels){
	std::ifstream file(file_name);
	std::string line;
	while (std::getline(file, line)){
		std::stringstream line_stream(line);
	Pixel pixel;
	char comma;
	line_stream >> pixel.x >> comma >> pixel.y >> comma >> pixel.r >> comma >> pixel.g >> comma >> pixel.b;
	pixels.push_back(pixel);
    }
}

void average_colors(std::vector<Pixel> &pixels){
	float sum_r = 0.0, sum_g = 0.0, sum_b = 0.0;
	int num_pixels = pixels.size();
	
	for (const auto &pixel : pixels){
		sum_r += pixel.r;
		sum_g += pixel.g;
		sum_b += pixel.b;
    }
	std::cout << "Average R: " << sum_r / num_pixels << std::endl;
	std::cout << "Average G: " << sum_g / num_pixels << std::endl;
	std::cout << "Average B: " << sum_b / num_pixels << std::endl;
}

void invert_y(std::vector<Pixel> &pixels){
	int max_height = 255;
	
	for (auto &pixel : pixels){
	pixel.y = max_height - pixel.y;
    }
}

void write_pixels(const std::string &file_name, const std::vector<Pixel> &pixels){
	std::ofstream file(file_name);
    
    for (const auto &pixel : pixels) {
        file << pixel.x << "," << pixel.y << "," << pixel.r << "," << pixel.g << "," << pixel.b << "\n";
    }
}

int main(int argc, char *argv[]) {
    std::vector<Pixel> pixels;
    read_pixels("pixels.dat", pixels);
    
    average_colors(pixels);
    invert_y(pixels);
    write_pixels("flipped.dat", pixels);
    
    return 0;
}




