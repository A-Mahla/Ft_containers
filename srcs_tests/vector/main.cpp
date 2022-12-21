# include <iostream>
# include "metaprog.hpp"
# include "random_iterator.hpp"
# include <vector>

using namespace ft;

struct Test {
	
	Test & operator=( const Test & rhs ) { 
		if ( this != &rhs )
		{
			data1 = rhs.data1;
			data2 = rhs.data2;
			data3 = rhs.data3;
		}
		return *this;
	}

	int data1;
	int data2;
	int data3;
};

void	randomIteratorTest( void )
{

	Test T = {1, 2, 3};
	Test T2 = {4, 5, 6};
	Test T3 = {7, 8, 9};

//	int a = 1;

//	int *z = &a;

//	Test*	TX = &T;
//	Test*	TX2 = &T2;

	Test* TVEC = new Test[3];

	TVEC[0] = T;
	TVEC[1] = T2;
	TVEC[2] = T3;


	std::vector<Test>::iterator	z(TVEC);
	const std::vector<Test>::iterator	z2(TVEC);

	randomIterator<Test>	x(TVEC);
	randomIterator<Test>	p = x;

	p = 2 + x;
	std::cout << (x > p) << std::endl;

	delete [] TVEC;

}

int main(void)
{
	randomIteratorTest();
//	test();
	return 0;
}
