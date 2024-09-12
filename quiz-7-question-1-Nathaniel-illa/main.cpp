#include "main.hpp"

int main()
{
	string filename = "original.data";
	ifstream ifs;
	string buf;

	reform(filename);
	ifs.open("trans.data");
	cout << "Sorted column-wise values \n";
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
}