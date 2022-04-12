#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "classes.h"
#include <fstream>
#include <ostream> 


figure** addToArray(figure** Array, figure* add)
{
	figure** res = new figure * [figure::size];

	if (Array != nullptr)
	{
		for (int i = 0; i < figure::size; i++)
		{
			res[i] = Array[i];
			Array[i] = nullptr;
		}
	}
	res[figure::size] = add;
	res[figure::size]->set();

	figure::size++;

	return res;
}

void cin(int* _x)
{
	while (true)
	{
		std::cin >> *_x;
		if (std::cin.good())
		{
			break;
		}
		std::cout << "invalid input" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
}



int main()
{
	figure** Figures = nullptr;

	int take = 0;
	while (take == 0)
	{
		std::cout << "0 EXIT\n11 ADD BALL  12 ADD BRICK  13 ADD TETRA\n2 EDIT\n3 DELETE\n4 FIND AREA\n5 OUTPUT TO FILE\n6 SEE ALL\n";

		cin(&take);

		switch (take)
		{
		case 0:
			return 0;
		case 11: // добавление шара
		{
			Figures = addToArray(Figures, new ball);
		}
		break;
		case 12: // добавление параллелепипеда
		{
			Figures = addToArray(Figures, new brick);
		}
		break;
		case 13: // добавление тетраэдра
		{
			Figures = addToArray(Figures, new tetra);
		}
		break;

		case 2: // редактировать данные
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}
			std::cout << "size = " << figure::size << " enter index: " << std::endl;
			int enter = -1;

			while (enter - 1 < 0 || enter - 1 > figure::size - 1)
				cin(&enter);
			enter--;

			Figures[enter]->set();
		}
		break;

		case 3: // удалить фигуру
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}

			std::cout << "size = " << figure::size << " enter index: " << std::endl;

			int enter = -1;
			while (enter - 1 < 0 || enter - 1 > figure::size - 1)
				cin(&enter);
			enter--;

			delete Figures[enter];
			for (int i = enter; i < figure::size; i++)
			{
				Figures[i] = Figures[i + 1];
			}

			Figures[figure::size] = nullptr;
			figure::size--;


		}
		break;

		case 4: // найти площадь поверхности
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}

			std::cout << "size = " << figure::size << " enter index: " << std::endl;

			int enter = -1;
			while (enter - 1 < 0 || enter - 1 > figure::size - 1)
				cin(&enter);
			enter--;

			int n = -1;

			std::cout << "area = " << Figures[enter]->area() << std::endl;
		}
		break;

		case 5: // вывести в файл
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}

			std::ofstream myfile;
			myfile.open("ouput.txt");

			for (int i = 0; i < figure::size; i++)
				Figures[i]->fileout(myfile);

			myfile.close();
		}
		break;

		case 6: // вывести на экран
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}

			for (int i = 0; i < figure::size; i++)
			{
				std::cout << i + 1 << ") ";
				Figures[i]->printdata();
			}
		}
		break;

		default:
			take = 0;
		}

		take = 0;
	}

	delete[] Figures;

	return 0;
}