// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

using namespace std;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

bool cmp(int first, int second) {
	return first > second;
}


	int main ()
	{
	  auto compare = [](int lhs, int rhs) {
		  return lhs < rhs;
	  };

	  priority_queue<int, vector<int>, decltype(compare)> q(compare);

	  for (int n : {1, 2, 8, 5, 6, 7, 4, 0, 9, 7, 2})
		  q.push(n);

	  while (!q.empty()) {
		  cout << q.top() << " " ;
		  q.pop();
	  }

	  return 0;
	}