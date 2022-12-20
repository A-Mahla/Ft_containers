# include <iostream>
# include "metaprog.hpp"
# include "vec_iterator.hpp"

using namespace ft;

void	randomIteratorTest( void )
{
	random_access_iterator<int> g;
	random_access_iterator<int> p(g);
	
	(void)g;
	(void)p;
	g = p;

	(void)g;
	g.~random_access_iterator();
}

int main(void)
{
	randomIteratorTest();
//	test();
	return 0;
}
