#include <iostream>
#include <string>
#include <deque>

//#include <ctime>

#if USE_STL

	#include <map>
	#include <stack>
	#include <vector>
	using namespace std;
	#define X 1

#else

	#include "rb_tree.hpp"
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	using namespace ft;
	#define X 0

#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

struct Test {};

/*====================VECTOR_TEST=======================*/

void	constructVector( void )
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
 
	const std::string extra(10000000, 'b');
	characters.assign(extra.begin(), extra.end());
	std::cout << "capacity character : " << characters.capacity() << std::endl;
	std::cout << "size character : " << characters.size() << std::endl;
 
	vector<char> g(extra.begin(), extra.end());
	std::cout << "capacity g : " << g.capacity() << std::endl;
	std::cout << "size g : " << g.size() << std::endl;

}

void	beginAndEndVector( void )
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

void	capacityTestVector( void )
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

void	accessConstructVector( void )
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

void	modifierVector( void )
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

void	comparisonVector( void )
{
	vector<int> a(10, 9);
	vector<int> b(10, 8);
	vector<int> d(11, 9);
	vector<int> e(10, 9);

	if ( a == e )
		std::cout << "a and e is same (right)" << std::endl;
	else
		std::cout << "a and e is not same" << std::endl;
	if ( a != b )
		std::cout << "a and b is not same (right)" << std::endl;
	else
		std::cout << "a and b is same" << std::endl;
	if ( b < a )
		std::cout << "b < a (right)" << std::endl;
	else
		std::cout << "a < b" << std::endl;
	if ( d > a )
		std::cout << "d > a (right)" << std::endl;
	else
		std::cout << "d < a" << std::endl;
	if ( a >= e )
		std::cout << "a >= e (right)" << std::endl;
	else
		std::cout << "a < e" << std::endl;
	if ( a <= e )
		std::cout << "a <= e (right)" << std::endl;
	else
		std::cout << "a > e" << std::endl;
	if ( b <= a )
		std::cout << "b <= a (right)" << std::endl;
	else
		std::cout << "a < b" << std::endl;
	if ( d >= a )
		std::cout << "d >= a (right)" << std::endl;
	else
		std::cout << "d < a" << std::endl;

}

/*=====================STAC==============================*/

void	stackTest( void )
{
	stack<std::string>	test;

	if ( test.empty() )
		std::cout << "test is empty (right)" << std::endl;

	test.push( "yoooooooo" );
	std::cout << test.top() << std::endl;
	test.push( "Bien ou bien" );
	std::cout << test.top() << std::endl;
	std::cout << test.size() << std::endl;
	test.pop();
	std::cout << test.top() << std::endl;
	std::cout << test.size() << std::endl;
}

/*=====================MAP===============================*/

void	constructMap( void )
{
	map<int, std::string> a;

	a[7] = "";
	a[8];
	a[9];
	a[9];
	a[9] = "yo";
	a[45];
	a[-45];


	map<int, std::string> b(a);

	map<int, std::string> c;

	c = a;
	for ( int n(0); n < 100000; n++ )
		c[n];
}

void	capacityMap( void )
{
	map<int, std::string> a;

	a[7] = "";
	a[8];
	a[9];
	a[9];
	a[9] = "yo";
	a[45];
	a[-45];

	std::cout << a.size() << std::endl;
	std::cout << a.max_size() << std::endl;
	std::cout << a.empty() << std::endl;
}

void	accessMap( void )
{
	
	map<int, std::string> a;

	a[7] = "";
	a[9];
	a[8];
	a[45];
	a[-45];

	std::cout << a.at(9) << std::endl;
	try
	{
		std::cout << a.at(66) << std::endl;
	}
	catch ( std::out_of_range & e )
	{
		std::cout << e.what() << std::endl;
	}
}

void	modifierMap( void )
{
	map<int, std::string>	a;

	a[1];
	a[7] = "";
	a[8];
	a[10];
	a[11];
	a[12];
	a[15];
	a[45];
	a[-45];

//	a.insert(pair<int, std::string>(9, "yooo"));
	a.insert(pair<int, std::string>(21, "yooo"));
	a.insert(--(a.end()), pair<int, std::string>(9, "yooo"));

	#if VIEWER
		std::cout << "tree a" << std::endl;
		a.print();
	#endif

	std::cout << std::endl;
	a.erase(a.begin());
	std::cout << std::endl;
	a.erase(10);

	#if VIEWER
		std::cout << "tree a" << std::endl;
		a.print();
		std::cout << a.size() << std::endl;
	#endif

	map<int, std::string>	b;

	b.swap(a);
	#if VIEWER
		std::cout << "tree a" << std::endl;
		a.print();
		std::cout << a.size() << std::endl;
		std::cout << "tree b" << std::endl;
		b.print();
		std::cout << b.size() << std::endl;
	#endif
	b.erase(b.begin(), b.end());
	#if VIEWER
		std::cout << "tree a" << std::endl;
		a.print();
		std::cout << b.size() << std::endl;
		std::cout << "tree b" << std::endl;
		b.print();
		std::cout << b.size() << std::endl;
	#endif
}

/*=====================42 Test===============================*/

void	test42( void )
{
	const int seed = 1000000;
	srand(seed);

	vector<std::string> vector_str;
	vector<int> vector_int;
	stack<int> stack_int;
	vector<Buffer> vector_buffer;
	stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

}

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};


#define TESTED_TYPE int

void		othertest(void)
{
	const int size = 5;
	vector<TESTED_TYPE> vct(size);
	vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	std::cout << vct.size() << std::endl;
}

int main(void)
{
	clock_t start = clock();


	// ==== VECTOR ====
/*
	constructVector();
	beginAndEndVector();
	capacityTestVector();
	accessConstructVector();
	modifierVector();
	comparisonVector();

	// ==== STACK ====

	stackTest();

	// ==== MAP ====

	// ==== Test_tree ====

//	treeTest();

	// ====================

	constructMap();
	accessMap();
	capacityMap();
	modifierMap();


	test42();
*/
	othertest();
	clock_t end = clock();

	double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

	if ( X )
		std::cout <<  "STL :";
	else
		std::cout <<  "MY CUSTOM CONTAINER :";
	std::cout << "Elapsed time: ";
	std::cout << elapsed_time << " seconds" << std::endl;

	return 0;
}

