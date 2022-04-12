#include <iostream>
#include <fstream>

#define PI 3.1415

void cin(float* _x)
{
	if (_x != nullptr)
		while (true)
		{
			std::cin >> *_x;
			if (std::cin.good() && *_x > 0)
			{
				break;
			}
			std::cout << "invalid input" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
}


class figure
{
public:

	static int size;
	virtual float area() = 0;
	virtual void set() = 0;
	virtual void printdata() = 0;
	virtual std::ofstream& fileout(std::ofstream& fp) = 0;
};

int figure::size = 0;

class ball : public figure
{
	float R; 

public:

	ball()
	{
		R = 0;
	}

	float area() override final
	{
		return 4 * PI * R * R;
	}

	void set() override
	{
		std::cout << "enter ball's Radius: ";
		float _R = 0;
		while (_R <= 0) cin(&_R);
		R = _R;
	}

	void printdata() override
	{
		std::cout << "R = " << R << std::endl;
	}

	std::ofstream& fileout(std::ofstream& fp) override
	{
		float Area = area();
		fp << "ball R = " << R << " area = " << Area << std::endl;
		return fp;
	}
};

class brick : public figure
{
	float a;
	float b;
	float c;

public:

	brick()
	{
		a = b = c = 0;
	}

	void set() override
	{
		float _a = 0, _b = 0, _c = 0;
		std::cout << "a: ";
		while (_a <= 0) cin(&_a);
		std::cout << "b: ";
		while (_b <= 0) cin(&_b);
		std::cout << "c: ";
		while (_c <= 0) cin(&_c);
		a = _a; b = _b; c = _c;
	}

	void printdata() override
	{
		std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;
	}

	float area() override
	{
		return 2 * (a * b + a * c + b * c);
	}


	std::ofstream& fileout(std::ofstream& fp) override
	{
		float Area = area();
		fp << "ball a = " << a << " b = " << b << " c = " << c << " area = " << Area << std::endl;
		return fp;
	}
};

class tetra : public figure
{
	float a;

public:

	tetra()
	{
		a = 0;
	}

	void set() override
	{
		std::cout << "enter tetraiders's side len: ";
		float _a = 0;
		while (_a <= 0) cin(&_a);
		a = _a;
	}
	void printdata() override
	{
		std::cout << "a = " << a << std::endl;
	}

	float area() override
	{
		return sqrt(3) * a;
	}

	std::ofstream& fileout(std::ofstream& fp) override
	{
		float Area = area();
		fp << "tetra a = " << a << " area = " << Area << std::endl;
		return fp;
	}
};