# include <iostream>
# include "metaprog.hpp"
//# include "random_iterator.hpp"

//using namespace std;
//# include <vector> 

# include "vector.hpp"
using namespace ft;
//

struct Test {};


/*====================VECTOR_TEST=======================*/

void	vectorConstruct( void )
{
	vector< int >	a(10, 1);
//	vector<float> b(1);
//	vector<double> c(10000, 10);
//	vector<std::string> d(10000, "");

	vector<int >::const_iterator	it;

}


int main(void)
{
	vectorConstruct();
	return 0;
}
