# include <iostream>
# include "metaprog.hpp"

using namespace std;
# include <vector> 


struct Test {};


/*====================VECTOR_TEST=======================*/

void	beginAndEnd( void )
{
	std::cout << "\t\ttest begin() and end()\n\n";
	vector<int> a(10000, 10);
	for ( vector<int>::iterator it = a.end(); it != a.begin(); --it )
		std::cout << *it;
	std::cout << std::endl;
	
	vector<std::string> b(1000, "yo");
	for ( vector<std::string>::iterator it = b.end(); --it != b.begin();)
		std::cout << *it;
	std::cout << std::endl;

	const vector<float> c;
	vector<float>::const_iterator e = c.begin();
//	vector<float>::iterator d = c.begin();
	e = c.end();

}

void	vectorConstruct( void )
{
	vector<float> b(1);
	vector< int >	a(10);
	vector<double> c(10000, 10);
	vector<std::string> d(10000000, "");

//	vector<int >::const_iterator	it = a.end();

}


int main(void)
{
	beginAndEnd();
//	vectorConstruct();
	return 0;
}
