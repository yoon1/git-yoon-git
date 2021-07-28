#include <tuple>
#include <iostream>

using namespace std;

typedef tuple<int, double, int, double> MyTuple;
int main()
{
	MyTuple c0(0, 1.5, 2, 3.7);

	// display contents "0 1 2 3"
	cout << get<0>(c0);
	cout << " " << get<1>(c0);
	cout << " " << get<2>(c0);
	cout << " " << get<3>(c0) << endl;

	// display size "4"
	cout << " " << tuple_size<MyTuple>::value << endl;
}
