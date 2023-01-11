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
 
	const std::string extra(100000000, 'b');
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
	for ( int n(0); n < 100000000; n++ )
		c[n];
}

// ==== Test_tree ====

/*
void treeTest( void )
{
	// TO TEST MAP ATTRIBUT AND RBTREE MUST BE PUBLIC
	map<int, std::string> a;



	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(26, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(17, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(41, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(47, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(21, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(30, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(14, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(38, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(23, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(28, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(19, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(16, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(10, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(20, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(15, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(12, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(35, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(7, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(39, "") ) );
	a._tree._insertNode( a._tree._create_node( pair<const int, std::string>(3, "") ) );

	std::cout << std::endl;

	a[7] = "";
	a[8];
	a[9];
	a[9];
	a[9] = "yo";
	a[45];
	a[-45];

	std::cout << a._tree._sizeTree << std::endl;
//	a._tree._deleteNode( 7 );
	std::cout << a._tree._sizeTree << std::endl;
	print_tree<pair<const int, std::string> >("", a._tree._root, 2);

	a[18] = "what";
	std::cout << std::endl;
	map<int, std::string> b(a);
	print_tree<pair<const int, std::string> >("", b._tree._root, 2);

	map<int, std::string> c;

	c = b;
	std::cout << std::endl;
	print_tree<pair<const int, std::string> >("", c._tree._root, 2);

	for ( map< int, std::string>::reverse_iterator it(c.rend()); it != c.rbegin(); )
		std::cout << (--it)->first << std::endl;


}
*/
// =================

int main(void)
{
//	clock_t start = clock();


	// ==== VECTOR ====

/*	constructVector();
	beginAndEndVector();
	capacityTestVector();
	accessConstructVector();
	modifierVector();
	comparisonVector();

	// ==== STACK ====

	stackTest();
*/
	// ==== MAP ====

	// ==== Test_tree ====

//	treeTest();

	// ====================

	constructMap();

/*
	clock_t end = clock();

	double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

	if ( X )
		std::cout <<  "STL :";
	else
		std::cout <<  "MY CUSTOM CONTAINER :";
	std::cout << "Elapsed time: ";
	std::cout << elapsed_time << " seconds" << std::endl;
*/
	return 0;
}

