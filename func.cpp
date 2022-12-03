#include "Header.h"
#include <iostream>
#include <string>
#include <cmath>
#include <filesystem>
#include <vector>

Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}

void Point::Print()
{
	std::cout << "(" << x << " , " << y << " , " << z << ")" << std::endl;
}

Point::Point(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point& Point::operator=(const Point& other)
{
	if (&other == this)
		return *this;
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

bool Point::operator==(const Point& pt1)
{
	return ((this->x == pt1.x) && (this->y == pt1.y) && (this->z == pt1.z));
}

bool Point:: operator > (const Point& pt1) {
	return (pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)) > (pow(pt1.x, 2) + pow(pt1.y, 2) + pow(pt1.z, 2));
}

bool Point:: operator < (const Point& pt1) {
	return (pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)) < (pow(pt1.x, 2) + pow(pt1.y, 2) + pow(pt1.z, 2));
}

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << "(" << point.x << " " << point.y << " " << point.z << ")" << " ";
	return out;
}

inline std::istream& operator>>(std::istream& in, Point& point)
{
	in >> point.x >> point.y >> point.z;
	return in;
}

void dop(Set<std::string>& files, std::string directory) {
	file_check(files, directory);
	std::cout << "\n/////////////////////////////////" << "\n";
	dop_func(files);
	std::cout << "\n/////////////////////////////////" << "\n";
	std::cout << files;
}

std::vector<std::string> tmp_for_file_check;
int count_for_file_check = 0;
void file_check(Set<std::string>& files, std::string directory) {
	for (const auto& entry : std::filesystem::directory_iterator(directory)) {
		if (std::filesystem::is_directory(entry)) {
			std::cout << entry << " - is directory." << std::endl;
			file_check(files,entry.path().string());
		}
		else {
			tmp_for_file_check.push_back(entry.path().string());
			std::cout << tmp_for_file_check[count_for_file_check] << " - is file." << std::endl;
			count_for_file_check++;
		}
	}
}

int symb_count(std::string a) {
	int count = a.size();
	for (count; a[count] != '\\'; count--);

	return count+1;
}

void dop_func(Set<std::string>& f) {
	for (int i = 0; i < tmp_for_file_check.size(); i++) {
		tmp_for_file_check[i] = tmp_for_file_check[i].erase(0, symb_count(tmp_for_file_check[i]));
		f.insert(tmp_for_file_check[i]);
	}
}

