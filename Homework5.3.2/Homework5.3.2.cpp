// Homework5.3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class DivisionByZeroException : public std::exception
{
public:
	const char* what() const override
	{
		return "Выход за границы массива";
	}
};

class smart_array
{
protected:
	int count = 0;
	int size = 0;
public:
	int* arr;
	smart_array(int size)
	{
		this->size = size;
		arr = new int[size];
	}
	void add_element(int element)
	{
		if (count >= size) throw DivisionByZeroException();
		arr[count] = element;
		++count;
	}
	int get_element(int row)
	{
		if (row >= size) throw DivisionByZeroException();
		return arr[row];
	}
	int get_size()
	{
		return size;
	}
	~smart_array()
	{
		delete[] arr;
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		for (int a = 0; a < new_array.get_size(); ++a)
		{
			arr.arr[a] = new_array.arr[a];
		}
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
