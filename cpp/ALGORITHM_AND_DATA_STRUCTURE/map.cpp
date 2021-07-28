#include<iostream>
#include<string>
#include<map>
using namespace std;
void print(map<int, string> Target_Map)
{
	for (auto i : Target_Map)
		cout << "Key->" << i.first << ", Value->" << i.second << "   ";
	cout << endl;
}

void main()
{
	map<int, string> Map;
	Map[1] = "First";
	Map[2] = "Second";
	Map[3] = "Third";
	map<int, string>::key_compare KComp = Map.key_comp();
	print(Map);
	if (KComp(3, 5))
		cout << "same" << endl;
	else
		cout << "Not same" << endl;
}

