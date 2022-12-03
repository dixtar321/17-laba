#pragma once
#include <iostream>

struct Point
{
	Point();
	Point(int x, int y, int z);
	int x, y, z;
	Point& operator=(const Point& other);
	friend std::ostream& operator<< (std::ostream& out, const Point& point);
	friend std::istream& operator>> (std::istream& in, Point& point);
	bool operator== (const Point& pt1);
	bool operator> (const Point& pt1);
	bool operator< (const Point& pt1);
	void Print();
};

template <typename T>

class Set {
private:
	size_t Set_size; 
	T* Set_array;
public:
	size_t get_Set_size() {
		return Set_size;
	}
	T get_Set_array(size_t idx) {
		return Set_array[idx];
	}
	Set() {
		Set_size = 0;
		Set_array = new T[Set_size+1];
	}
	Set(const int value) {
		if (value > 0) {
			Set_size = value;
			Set_array = new T[Set_size+1];
		}
		else {
			std::cout << "Size error!\n";
		}

	};
	~Set() {
		delete[] Set_array;
	};

	void insert(const T& value) {  // вставить элемент
		if (!(find_for_func(value))) {
			if (Set_size == 0) {
				Set_size += 1;
				Set_array[0] = value;
			}
			else {
				T* array_tmp = new T[Set_size + 1];
				memcpy(array_tmp, Set_array, Set_size * sizeof(T));
				array_tmp[Set_size] = value;
				Set_size += 1;
				//if (Set_array != nullptr)
					//delete[] Set_array;
				Set_array = array_tmp;
				
			}
			if(Set_size > 1)
				bubble_sort();
		}
		else
			std::cout << "This element is already in Set\n";
	};

	int find_element(const T& value) {
		for (int i = 0; i < Set_size; i++) {
			if (Set_array[i] == value)
				return i;
		}
	}

	void erase(const T& value) {
		try {
			if (Set_size == 0) {
				throw std::exception("Set size is 0");
			}

			if ((find_for_func(value))) {
				T* array_tmp = new T[Set_size];
				memcpy(array_tmp, Set_array, Set_size * sizeof(T));
				int count = find_element(value);
				for (int i = 0; i < Set_size - count; i++) {
					array_tmp[count + i] = array_tmp[count + i + 1];
				}
				if (Set_array != nullptr)
					delete[] Set_array;
				Set_array = array_tmp;
				Set_size--;
				std::cout << "Was erased - " << value;
				std::cout << "\n";
			}
			else {
				std::cout << "There is not this element in Set";
				std::cout << "\n";
			}
		}
		catch (const std::exception& ex) {
			std::cout << "Exception! " << ex.what() << "\n";
		}
		

	}; // добавить исключение // удалить элемент

	bool find_for_func(const T& value) {
		for (int i = 0; i < Set_size; i++) {
			if (Set_array[i] == value)
				return 1;
		}
		return 0;
	};

	bool find(const T& value) {
		for (int i = 0; i < Set_size; i++) {
			if (Set_array[i] == value) {
				std::cout << "True for "<< value;
				std::cout << "\n";
				return 1;
			}
		}
		std::cout << "False for " << value;
		std::cout << "\n";
		return 0;
	}; // есть ли элемент

	void size() {
		std::cout << "Set Size is "<<Set_size;
		std::cout << "\n";
	};

	void clear() {
		T* array_tmp = new T[Set_size];
		memcpy(array_tmp, Set_array, Set_size * sizeof(T));
		for (int i = 0; i < Set_size; i++) {
			array_tmp[i] = array_tmp[i + 1];
		}
		if (Set_array != nullptr)
			delete[] Set_array;
		Set_array = array_tmp;
		Set_size = 0;
		std::cout << "\nSet is empty";
	};

	friend std::ostream& operator<<(std::ostream& stream, Set<T>& t) {
		for (size_t i = 0; i < t.Set_size; i++) {
			stream << t.get_Set_array(i)<< " ";
			std::cout << "\n";
		}
		std::cout << "\n";
		return stream;
	};

	void swap(T& a, T& b) {
		T t(a);
		a = b;
		b = t;
	}

	void bubble_sort() {
		int i, j;
		for(i = 0; i < Set_size - 1; i++)
			for(j = 0; j < Set_size - 1 - i; j++)
				if (Set_array[j] > Set_array[j + 1])
					swap(Set_array[j], Set_array[j + 1]);
	};
};

void dop(Set<std::string>& files, std::string directory);
void file_check(Set<std::string>& files, std::string directory);
void dop_func(Set<std::string>& f);
int symb_count(std::string a);