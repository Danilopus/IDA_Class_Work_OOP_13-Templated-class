//class template version 4.0 //20.06.2023//
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//My own headers
#include "Service functions.h"
#include "classes.h"



// Class Work 28.06.2023 -------------------------------------------	

// Шаблоны

// Виды
/*
1) Определенное количество аргументов 

2) Неопределенное количество аргументов (#Variadic template) (#tuple)

Типы аргументы шаблона:
1) неопределенный аргумент - передача типов данных
2) вычисляемый аргумент - передача типов данных
3*) аргумент-параметр (как правило: передача размера, кол-ва и.т.п.)



*/
void func_example_2(MyClass <int, 10> obj);



//Task 1
void Task_1()
{
	MyClass <int, 10> obj;	
	//MyClass <float, 20> obj2;

	std::cout << "\n\nMyClass obj\n";
	for (size_t i = 0; i < obj.size(); i++)
	{
		obj[i] = i+1;
	}
	func_example_2(obj); 

	std::cout << "\n\nranged for\n";

	for (const auto& el : obj)
	{
		std::cout << el << " | ";
	}


	std::cout << "\n\n begin | end\n";
	for (auto it = obj.begin();  it != obj.end(); ++it)
	//for (const auto it = obj.begin(); it != obj.end(); ++it)
	{
		std::cout << *it << " | ";
	}

	// standart static array -------------------------
	std::cout << "\n\nstandart static array\n";

	int arr[10];
	for (size_t i = 0; i < std::size(arr); i++)
	{
		arr[i] = 2*i + 1;
	}
	for (const auto& el : arr)
	{
		std::cout << el << " | ";
	}

	// std::array ----------------------------------
	std::cout << "\n\nstd::array | ranged for\n";

	std::array<int, 10> arr_STD;
	//for (size_t i = 0; i < std::size(arr_STD); i++)
	for (size_t i = 0; i < (arr_STD.size()); i++)
	{
		arr_STD[i] = 3*i + 1;
	}

	// const auto& el - контейнер-итератор для элемента коллекции arr
	// arr - коллекция

	for (const auto& el : arr_STD)
	{
		std::cout << el << " | ";
	}
	std::cout << "\n\nstd::array | begin-end\n";
	//for (auto it = arr_STD.begin(); it != arr_STD.end(); ++it)
	for (std::array<int,10>::iterator it = arr_STD.begin(); it != arr_STD.end(); ++it)

	{
		const auto& el = *it;
		//std::cout << *it << " | ";
		std::cout << el << " | ";

	}

}

// функция принимает только объект MyClass c параметрами <int, 10>
void func_example_2(MyClass <int, 10> obj) 
{
	for (size_t i = 0; i < obj.size(); i++)
	{
		std::cout << obj[i] << " | ";
	}

}

//Task 2
void Task_2()
{
	
}
//Task 3
void Task_3()
{

}


// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
srand(time(NULL));
		
	
Task_1();
Task_2();
Task_3();





std::cout << "\n\n";
//system("pause");	
_getch();
}


