# include <iostream>
# include "metaprog.hpp"
# include "vec_iterator.hpp"


using namespace ft;

void	randomIteratorTest( void )
{
	int *i = NULL;

	random_access_iterator<int> g(i);
	random_access_iterator<int> p;
	
	g = p;

	(void)g;
	g.~random_access_iterator();
}

int main(void)
{
	randomIteratorTest();
	return 0;
}
