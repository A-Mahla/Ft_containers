# include <iostream>
# include "metaprog.hpp"

using namespace ft;

void	isIntegralTest( void )
{
	std::cout << is_integral< bool >::value << std::endl;
	std::cout << is_integral< char >::value << std::endl;
	std::cout << is_integral< signed char >::value << std::endl;
	std::cout << is_integral< unsigned char >::value << std::endl;
	std::cout << is_integral< short >::value << std::endl;
	std::cout << is_integral< short int >::value << std::endl;
	std::cout << is_integral< signed short >::value << std::endl;
	std::cout << is_integral< signed short int >::value << std::endl;
	std::cout << is_integral< unsigned short >::value << std::endl;
	std::cout << is_integral< unsigned short int >::value << std::endl;
	std::cout << is_integral< int >::value << std::endl;
	std::cout << is_integral< signed >::value << std::endl;
	std::cout << is_integral< signed int >::value << std::endl;
	std::cout << is_integral< signed int >::value << std::endl;
	std::cout << is_integral< unsigned int >::value << std::endl;
	std::cout << is_integral< long >::value << std::endl;
	std::cout << is_integral< long int >::value << std::endl;
	std::cout << is_integral< signed long >::value << std::endl;
	std::cout << is_integral< signed long int >::value << std::endl;
	std::cout << is_integral< unsigned long >::value << std::endl;
	std::cout << is_integral< unsigned long int >::value << std::endl;
	std::cout << is_integral< long long >::value << std::endl;
	std::cout << is_integral< long long int >::value << std::endl;
	std::cout << is_integral< signed long long >::value << std::endl;
	std::cout << is_integral< signed long long int >::value << std::endl;
	std::cout << is_integral< unsigned long long >::value << std::endl;
	std::cout << is_integral< unsigned long long int >::value << std::endl;

	std::cout << is_integral< const bool >::value << std::endl;
	std::cout << is_integral< const char >::value << std::endl;
	std::cout << is_integral< const signed char >::value << std::endl;
	std::cout << is_integral< const unsigned char >::value << std::endl;
	std::cout << is_integral< const short >::value << std::endl;
	std::cout << is_integral< const short int >::value << std::endl;
	std::cout << is_integral< const signed short >::value << std::endl;
	std::cout << is_integral< const signed short int >::value << std::endl;
	std::cout << is_integral< const unsigned short >::value << std::endl;
	std::cout << is_integral< const unsigned short int >::value << std::endl;
	std::cout << is_integral< const int >::value << std::endl;
	std::cout << is_integral< const signed >::value << std::endl;
	std::cout << is_integral< const signed int >::value << std::endl;
	std::cout << is_integral< const signed int >::value << std::endl;
	std::cout << is_integral< const unsigned int >::value << std::endl;
	std::cout << is_integral< const long >::value << std::endl;
	std::cout << is_integral< const long int >::value << std::endl;
	std::cout << is_integral< const signed long >::value << std::endl;
	std::cout << is_integral< const signed long int >::value << std::endl;
	std::cout << is_integral< const unsigned long >::value << std::endl;
	std::cout << is_integral< const unsigned long int >::value << std::endl;
	std::cout << is_integral< const long long >::value << std::endl;
	std::cout << is_integral< const long long int >::value << std::endl;
	std::cout << is_integral< const signed long long >::value << std::endl;
	std::cout << is_integral< const signed long long int >::value << std::endl;
	std::cout << is_integral< const unsigned long long >::value << std::endl;
	std::cout << is_integral< const unsigned long long int >::value << std::endl;

	std::cout << is_integral< volatile bool >::value << std::endl;
	std::cout << is_integral< volatile char >::value << std::endl;
	std::cout << is_integral< volatile signed char >::value << std::endl;
	std::cout << is_integral< volatile unsigned char >::value << std::endl;
	std::cout << is_integral< volatile short >::value << std::endl;
	std::cout << is_integral< volatile short int >::value << std::endl;
	std::cout << is_integral< volatile signed short >::value << std::endl;
	std::cout << is_integral< volatile signed short int >::value << std::endl;
	std::cout << is_integral< volatile unsigned short >::value << std::endl;
	std::cout << is_integral< volatile unsigned short int >::value << std::endl;
	std::cout << is_integral< volatile int >::value << std::endl;
	std::cout << is_integral< volatile signed >::value << std::endl;
	std::cout << is_integral< volatile signed int >::value << std::endl;
	std::cout << is_integral< volatile signed int >::value << std::endl;
	std::cout << is_integral< volatile unsigned int >::value << std::endl;
	std::cout << is_integral< volatile long >::value << std::endl;
	std::cout << is_integral< volatile long int >::value << std::endl;
	std::cout << is_integral< volatile signed long >::value << std::endl;
	std::cout << is_integral< volatile signed long int >::value << std::endl;
	std::cout << is_integral< volatile unsigned long >::value << std::endl;
	std::cout << is_integral< volatile unsigned long int >::value << std::endl;
	std::cout << is_integral< volatile long long >::value << std::endl;
	std::cout << is_integral< volatile long long int >::value << std::endl;
	std::cout << is_integral< volatile signed long long >::value << std::endl;
	std::cout << is_integral< volatile signed long long int >::value << std::endl;
	std::cout << is_integral< volatile unsigned long long >::value << std::endl;
	std::cout << is_integral< volatile unsigned long long int >::value << std::endl;

}


void	ifEnableTest( void )
{
	typedef enable_if< is_same< int, int >::value, char>::type  g;

	std::cout << "test enable_if" << std::endl;
	std::cout << is_integral< g >::value << std::endl;

}


int main(void)
{
	isIntegralTest();
	ifEnableTest(); 
	return 0;
}
