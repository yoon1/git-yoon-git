#include<vector>
#include<iostream>
using namespace std;
void print(vector<int> Target_Vector)
{
	for (auto i : Target_Vector)
		cout << i << " ";
	cout << endl;
}

void main()
{
	vector<int> Vector(15, 2);
	Vector.reserve(50);
	cout << "Previous ->"; cout << Vector.capacity();
	cout << endl << "shrink_to_fit()" << endl;
	Vector.shrink_to_fit();
	cout << "After ->"; cout << Vector.capacity() << endl;
}
