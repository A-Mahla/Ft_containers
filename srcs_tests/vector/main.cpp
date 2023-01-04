# include <iostream>
# include "metaprog.hpp"

//using namespace std;
//# include <vector> 

# include "vector.hpp"
using namespace ft;
//

struct Test {};


/*====================VECTOR_TEST=======================*/

void	vectorConstruct( void )
{
	vector<float> b(1);
	vector< int >	a(10);
	vector<double> c(10000, 10);
	vector<std::string> d(10000000, "");

	vector<int> e(10, 999);
	vector<int> f;

	f = e;
	for ( vector<int>::iterator it = f.begin(); it != f.end(); it++ )
		std::cout << *it << std::endl;

	std::cout << std::endl;

	for ( vector<int>::iterator it = e.begin(); it != e.end(); it++ )
		std::cout << *it << std::endl;

	std::cout << std::endl << "test assign" << std::endl << std::endl;
	vector<char> characters;
	std::cout << "capacity character : " << characters.capacity() << std::endl;
	std::cout << "size character : " << characters.size() << std::endl;
 

    characters.assign(6, 'a');
	for ( vector<char>::iterator it = characters.begin(); it != characters.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << "capacity character : " << characters.capacity() << std::endl;
	std::cout << "size character : " << characters.size() << std::endl;
 
	const std::string extra(100000000, 'b');
	characters.assign(extra.begin(), extra.end());
	std::cout << "capacity character : " << characters.capacity() << std::endl;
	std::cout << "size character : " << characters.size() << std::endl;
 
	vector<char> g(extra.begin(), extra.end());
	std::cout << "capacity g : " << g.capacity() << std::endl;
	std::cout << "size g : " << g.size() << std::endl;

}

void	beginAndEnd( void )
{
	std::cout << "\t\tTEST begin() / end()\n\n";
	vector<int> a(10000, 10);
	for ( vector<int>::iterator it = a.end() - 1; it != a.begin(); it-- )
		std::cout << *it;
	std::cout << std::endl;
	
	vector<std::string> b(1000, "yo");
	for ( vector<std::string>::iterator it = b.begin(); it != b.end(); it++ )
		std::cout << *it;
	std::cout << std::endl;

	const vector<float> c;
	vector<float>::const_iterator e = c.begin();
	e = c.end();

}

void	capacityTest( void )
{
	std::cout << "\t\tTEST size() / max_size() / capacity() / empty()\n\n";
	vector<char> a(10000, 10);
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	std::cout << a.max_size() << std::endl;
	std::cout << a.empty() << std::endl << std::endl;
	vector<int> b(100, 10);
	std::cout << b.size() << std::endl;
	std::cout << b.capacity() << std::endl;
	std::cout << b.max_size() << std::endl;
	std::cout << b.empty() << std::endl << std::endl;
	vector<double> c(10, 10);
	std::cout << c.size() << std::endl;
	std::cout << c.capacity() << std::endl;
	std::cout << c.max_size() << std::endl;
	std::cout << c.empty() << std::endl << std::endl;
	vector<std::string> d;
	std::cout << d.size() << std::endl;
	std::cout << d.capacity() << std::endl;
	std::cout << d.max_size() << std::endl;
	std::cout << d.empty() << std::endl << std::endl;
	vector<std::string> e(10);
	std::cout << e.size() << std::endl;
	std::cout << e.capacity() << std::endl;
	std::cout << e.max_size() << std::endl;
	std::cout << e.empty() << std::endl << std::endl;

	std::cout << "Test resize" << std::endl;
	vector<int> f( 1, 10 );
    std::cout << "The vector holds: " << std::endl;
	for ( vector<int>::iterator it = f.begin(); it != f.end(); it++ )
		std::cout << *it << ' ' << std::endl;
	std::cout << "size : " << f.size() << std::endl;
	std::cout << "capacity : " << f.capacity() << std::endl;
    std::cout << '\n';
 
    f.resize(5);
    std::cout << "After resize up to 5: " << std::endl;
	for ( vector<int>::iterator it = f.begin(); it != f.end(); it++ )
		std::cout << *it << ' ' << std::endl;
	std::cout << "size : " << f.size() << std::endl;
	std::cout << "capacity : " << f.capacity() << std::endl;
    std::cout << '\n';
 
    f.resize(2);
    std::cout << "After resize down to 2: " << std::endl;
	for ( vector<int>::iterator it = f.begin(); it != f.end(); it++ )
		std::cout << *it << ' ' << std::endl;
	std::cout << "size : " << f.size() << std::endl;
	std::cout << "capacity : " << f.capacity() << std::endl;
    std::cout << '\n';
 
    f.resize(11, 4);
    std::cout << "After resize up to 6 (initializer = 4): " << std::endl;
	for ( vector<int>::iterator it = f.begin(); it != f.end(); it++ )
		std::cout << *it << ' ' << std::endl;
	std::cout << "size : " << f.size() << std::endl;
	std::cout << "capacity : " << f.capacity() << std::endl;
    std::cout << '\n';


	std::cout << "Test reserve" << std::endl;
	vector<int> g( 1, 10 );
    std::cout << "The vector holds: " << std::endl;
	for ( vector<int>::iterator it = g.begin(); it != g.end(); it++ )
		std::cout << *it << ' ' << std::endl;
	std::cout << "size : " << g.size() << std::endl;
	std::cout << "capacity : " << g.capacity() << std::endl;
    std::cout << '\n';
 
    g.reserve(5);
    std::cout << "After reserve up to 5: " << std::endl;
	for ( vector<int>::iterator it = g.begin(); it != g.end(); it++ )
		std::cout << *it << ' ' << std::endl;
	std::cout << "size : " << g.size() << std::endl;
	std::cout << "capacity : " << g.capacity() << std::endl;
    std::cout << '\n';
 
    g.reserve(2);
    std::cout << "After reserve down to 2: " << std::endl;
	for ( vector<int>::iterator it = g.begin(); it != g.end(); it++ )
		std::cout << *it << ' ' << std::endl;
	std::cout << "size : " << g.size() << std::endl;
	std::cout << "capacity : " << g.capacity() << std::endl;
    std::cout << '\n';
 
    g.reserve(11);
    std::cout << "After reserve up to 6 (initializer = 4): " << std::endl;
	for ( vector<int>::iterator it = g.begin(); it != g.end(); it++ )
		std::cout << *it << ' ' << std::endl;
	std::cout << "size : " << g.size() << std::endl;
	std::cout << "capacity : " << g.capacity() << std::endl;
}

void	accessConstruct( void )
{
	std::cout << "\t\tTEST operator[]() / at()\n\n";

	vector<int> a(10);
	for ( size_t i(0); i < a.size(); i++ )
	{
		a[i] = i;
		std::cout << a[i] <<  a.at(i) << std::endl;
	}

	const vector<int> b(10);
	for ( size_t i(0); i < b.size(); i++ )
		std::cout << b[i] << b.at(i) << std::endl;
	std::cout << b.front() << std::endl;
	std::cout << b.back() << std::endl;

	vector<char>c(26);
	for ( size_t i(0), a = 'a'; i < c.size(); i++, a++ )
		c.at(i) = a;
	std::cout << c.front() << std::endl;
	std::cout << c.back() << std::endl;

}

void	modifier( void )
{

	std::cout << "test cleared" << std::endl;
	vector<int> a( 10, 10 );
	for ( vector<int>::iterator it = a.begin(); it != a.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << "capacity : " << a.capacity() << std::endl;
	
	a.clear();
	if ( !a.size() )
		std::cout << "vector a cleared" << std::endl;
	for ( vector<int>::iterator it = a.begin(); it != a.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << "capacity a : " << a.capacity() << std::endl;

	/* RETEST WITH DIFFERENT VALUE !!!*/
	std::cout << "test erase std" << std::endl;
	vector<int> b( 10, 10 );
	std::cout << "capacity b : " << b.capacity() << std::endl;
	b.erase( b.begin(), b.end() - 1 );
	for ( vector<int>::iterator it = b.begin(); it != b.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << "capacity b : " << b.capacity() << std::endl;
	std::cout << "size b : " << b.size() << std::endl;


	std::cout << "test erase( pos )" << std::endl;

	vector<int> c( 1, 10 );
	std::cout << "capacity c : " << c.capacity() << std::endl;
	c.erase( c.begin() );
	for ( vector<int>::iterator it = c.begin(); it != c.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << "capacity c : " << c.capacity() << std::endl;
	std::cout << "size c : " << c.size() << std::endl;

	std::cout << "test push_back()" << std::endl;

	vector<int> d;
	std::cout << "capacity d : " << d.capacity() << std::endl;
	std::cout << "size d : " << d.size() << std::endl;
	for ( int i = 0; i < 17; i++ )
		d.push_back(i);
	for ( vector<int>::iterator it = d.begin(); it != d.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << "capacity d : " << d.capacity() << std::endl;
	std::cout << "size d : " << d.size() << std::endl;

	std::cout << "test pop_back()" << std::endl;

	for ( int i = 0; i < 10; i++ )
		d.pop_back();
	for ( vector<int>::iterator it = d.begin(); it != d.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << "capacity d : " << d.capacity() << std::endl;
	std::cout << "size d : " << d.size() << std::endl;

	std::cout << "test insert(pos, x) " << std::endl;

	d.insert(d.begin(), 400);
	for ( vector<int>::iterator it = d.begin(); it != d.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << "capacity d : " << d.capacity() << std::endl;
	std::cout << "size d : " << d.size() << std::endl;

	std::cout << std::endl << "test insert(pos, x) " << std::endl;
	d.insert(d.end(), 9800);
	for ( vector<int>::iterator it = d.begin(); it != d.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << "capacity d : " << d.capacity() << std::endl;
	std::cout << "size d : " << d.size() << std::endl;

	std::cout << std::endl << "test insert(pos, x) " << std::endl;
	vector<int>::iterator it = d.begin();
	for ( int i = 5; i; i--, it++ )
		;
	std::cout << *it << std::endl;
	d.insert(it, 6, 11111);
	std::cout << "last" << std::endl;
	for ( vector<int>::iterator it = d.begin(); it != d.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << "capacity d : " << d.capacity() << std::endl;
	std::cout << "size d : " << d.size() << std::endl;

	std::cout << std::endl << "test insert(pos, n, x) " << std::endl;

	it = d.begin();
	for ( int i = 5; i; i--, it++ )
		;
	
	d.insert(it, 1000000, 999);
	std::cout << "capacity d : " << d.capacity() << std::endl;
	std::cout << "size d : " << d.size() << std::endl;

	vector<int> e;

	e.insert( e.begin(), d.begin(), d.end() );
	std::cout << "capacity e : " << e.capacity() << std::endl;
	std::cout << "size e : " << e.size() << std::endl;
	


}

int main(void)
{
	vectorConstruct();
	beginAndEnd();
	capacityTest();
	accessConstruct();
	modifier();
	return 0;
}

