/*

9. ������� ���������� ��������� set (�� ������ ������� � �����������) ��� �������� ������ ���������� ���������.
		insert(const T& value)
		erase(const T& value) (������� ���������� �� ������ ���������)
		bool find(const T& value)
		size
		clear
		operator<< ��� ������


		������� (����� ������ ���������� (���� � �����(����� ���� ����� � �����(� ������ ����� ���� �����, ����� �� ����� ���� ������))) � � set ��������� ���������� �������� ������)
		����� ������� � ����� � ��������� �����
		� Set ��������� ���������� ����� ������


	�������� ����������
	�������� ������� ��� ����� (�� �����), ��������� �������� �� ������������
	����� �������� ����� �� ����� � �������� ��������, ��������� �� ������������

*/

#include "Header.h"
#include <iostream>
#include <filesystem>
#include <clocale>

using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "\n///////////////POINT///////////////" << "\n";
	
	Point b(2, 3, 5);
	Point c(-4, -5, -6);
	Point d(89, 54, 0);
	Set<Point> a;
	a.erase(c);
	a.insert(b);
	cout << a;
	a.insert(c);
	cout << a;
	a.insert(d);
	cout << a;

	a.erase(c);
	cout << a;

	a.size();
	a.clear();
	cout << a;
	a.size();

	std::cout << "\n///////////////int///////////////" << "\n";

	Set<int> f;
	f.insert(4);
	cout << f;

	f.erase(4);
	cout << f;

	f.insert(-18);
	cout << f;
	f.insert(-35);
	cout << f;
	f.insert(0);
	cout << f;
	f.insert(50);
	cout << f;

	f.erase(0);
	cout << f;
	f.erase(-35);
	cout << f;
	f.erase(-18);
	cout << f;
	f.erase(-180);
	cout << f;
	f.erase(50);
	cout << f;
	f.erase(-18);
	cout << f;

	std::cout << "\n///////////////char///////////////" << "\n";
	Set<char> g;
	g.insert('d');
	cout << g;
	g.insert('b');
	cout << g;
	g.insert('z');
	cout << g;
	g.insert('z');
	cout << g;


	g.erase('d');
	cout << g;
	g.erase('o');
	cout << g;
	g.erase('z');
	cout << g;
	g.erase('b');
	cout << g;

	std::cout << "\n///////////////DOP///////////////" << "\n";
	Set<string> files;
	string directory = "C:/Users/alex_/OneDrive/������� ����/�������/�����������/����� 3/���� 17/���";
	dop(files, directory);
	
	

	/*
	string pathDirWindows = "C:/Users/alex_/OneDrive/������� ����/�������/�����������/����� 3/���� 17/���";
	filesystem::path dirWindows(pathDirWindows);
	if (filesystem::is_directory(pathDirWindows))
		cout << dirWindows << " - is directory." << endl;
	else
		cout << dirWindows << " - is other." << endl;


	string pathfileExplorer = "C:/Users/alex_/OneDrive/������� ����/�������/�����������/����� 3/���� 17/���";
	filesystem::path fileExplorer(pathfileExplorer);
	if (filesystem::is_regular_file(fileExplorer))
		cout << fileExplorer << " - is file." << endl;
	else
		cout << fileExplorer << " - is other." << endl;



	std::string path = "C:/Users/alex_/OneDrive/������� ����/�������/�����������/����� 3/���� 17/���";
	for (const auto& entry : fs::directory_iterator(path)) {

		std::cout << entry.path() << std::endl;
	}
	*/

	return 0;
}

