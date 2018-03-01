#include <iostream>

using namespace std;

struct Size
{
	int		a;
	short	b;
	double	c;
	char	d;
};

struct Size2
{
	char	a;
	Size	b;
};

struct Size3
{
	char	a;
	Size3*	ptr;
};

int main()
{
	// ##2. Size of structure
	cout << sizeof(Size) << endl;
	cout << sizeof(Size2) << endl;
	system("pause");
}