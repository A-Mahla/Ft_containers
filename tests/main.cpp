#include <iostream>
#include <string>
#include <deque>
#include <list>

//#include <ctime>

#if USE_STL

	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	using namespace std;
	#define X 1

#else

	#include "rb_tree.hpp"
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "set.hpp"
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

/*=====================STACK==============================*/

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
	std::list<pair<int, std::string> > test;

	c = a;
	for ( int n(0); n < 100000; n++ )
	{
		test.push_back(make_pair<int, std::string>(n, "what"));
		c[n] = "yo";
	}
	b.insert(test.begin(), test.end());
	std::cout << b.size() << std::endl;
}

void	capacityAndModidierMap( void )
{
	map<int, int> a;

	a[7] = 0;
	a[8];
	a[9];
	a[9];
	a[432] = 34;
	a[437] = 143;
	a[489] = 94;
	a[403] = 192;
	a[73] = 603;
	a[92] = 0;
	a[7652];
	a[-1241];
	a[-1212345] = 0123;
	a[-654] = 43;
	a[-789234];
	a[9] = 9;
	a[45];
	a[-45];

	std::cout << a.size() << std::endl;
	std::cout << a.max_size() << std::endl;
	std::cout << a.empty() << std::endl;

	map<int, int>::iterator it1 = a.begin();
	map<int, int>::iterator it2 = a.begin();
	map<int, int>::iterator it3 = a.begin();

	for (int i = 0; i < 13; i++) { 
		if ( i < 3 )
			it3++;
		if ( i < 8 )
			it2++;
		it1++; 
	}
	map<int, int> mp(a.begin(), it1);
	map<int, int> cpy(it3, it2);


	// mp.printBT();
	std::cout << "size of mp : " << mp.size() << "\n";
	// cpy.printBT();
	std::cout << "size of cpy : " << cpy.size() << "\n";
	cpy = mp;
	std::cout << "size of cpy after taking mp: " << cpy.size() << " and checking empty() " << cpy.empty() << "\n";
	// cpy.printBT();


	std::cout << "mp[5] = " << mp[5] << "\n";
	mp[5] = 1999;
	std::cout << "after doing [mp[5] = 1999] : mp[5] = " << mp[5] << "\n";
	std::cout << "size :" << mp.size() << "\n";

	std::cout << "\n" << "\n" << "****************** testing the swap function :" << "\n";
	cpy.insert(make_pair(1000, 0));
	cpy.insert(make_pair(2000, 0));
	cpy.insert(make_pair(3000, 0));
	cpy.insert(make_pair(-8000, 0));

	std::cout << "printing both my map to check there differences :\nmp -->" << "\n";
	std::cout << mp.size() << " printing the size first\n";
	// mp.printBT();
	std::cout << "cpy -->\n";
	std::cout << cpy.size() << " printing the size first\n";
	// cpy.printBT();

	mp.swap(cpy);

	std::cout << "printing again after swap :\nmp -->" << "\n";
	std::cout << mp.size() << " printing the size first\n";
	// mp.printBT();
	std::cout << "cpy -->\n";
	std::cout << cpy.size() << " printing the size first\n";
	// cpy.printBT();


	std::cout << "\n******************* end of the test *******************\n\n";
	mp.clear();
	cpy.clear();
	map<int, int>::iterator itbeg = mp.begin();
	map<int, int>::iterator itend = mp.end();

	if (itbeg == itend)
		std::cout << "we enter here because (itbeg == itend) because we just clear !!\n";

	std::cout << (mp.key_comp()).operator()(5, 10) << "\n";

	mp.insert(make_pair(1045, 0));
	std::cout << "finding stuff that does not exit : " << (--(mp.find(56)))->first << "\n";
	mp.insert(make_pair(56, 0));
	std::cout << "finding stuff that does exit : " << mp.find(56)->first << "\n";

	map<char,int> mymap;

	mymap.insert(make_pair('a', 0));
	mymap.insert(make_pair('b', 0));
	mymap.insert(make_pair('c', 0));

	std::cout << "initialising mymap with value = 0 : \n";

	std::cout << "mymap['a'] : " << mymap['a'] << "\n";
	std::cout << "mymap['b'] : " << mymap['b'] << "\n";
	std::cout << "mymap['c'] : " << mymap['c'] << "\n";

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	std::cout << "now after chamging value this way ( mymap['x'] = X ) :\n";
	std::cout << "mymap['a'] : " << mymap['a'] << "\n";
	std::cout << "mymap['b'] : " << mymap['b'] << "\n";
	std::cout << "mymap['c'] : " << mymap['c'] << "\n";


	pair<map<char,int>::iterator,map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	map<int, int> y;
	map<int, int> z;


	std::cout << "************************ testing swap function : **************************** \n\n";

	y.insert(make_pair(1, 56));
	y.insert(make_pair(2, 57));
	y.insert(make_pair(3, 58));

	z.insert(make_pair(8, 45));
	z.insert(make_pair(9, 46));
	z.insert(make_pair(10, 47));

	std::cout << "keys inserted for z : [8, 9, 10]\n" << z[8] << " " << z[9] << " " << z[10]  << " " << "\n";
	std::cout << "keys inserted for y : [1, 2, 3] -> " << y[1]  << " " << y[2]  << " " << y[3]  << " " << "\n";

	map<int, int>::iterator rit1 = y.begin();
	map<int, int>::iterator rit2 = z.begin();

	swap(y, z);

	std::cout << "keys inserted for z : [8, 9, 10] ->" << z[8]  << " " << z[9]  << " " << z[10]  << " " << "\n";
	std::cout << "keys inserted for y : [1, 2, 3] -> " << y[1]  << " " << y[2]  << " " << y[3]  << " " << "\n";

	std::cout << "\nand testing now with iterators\n\n";


	for (; rit1 != z.end(); rit1++)
		std::cout << "with syntax (*rit).first " << (*rit1).first << "\n";
	std::cout << "---------------------------------------------\n";
	for (; rit2 != y.end(); rit2++)
		std::cout << "with syntax (*rit).first " << (*rit2).first << "\n";

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

void	deleteMap(void)
{
	map<int, std::string> mp;

	mp[42] = "lol";

	mp[50] = "mdr";
	mp[25] = "funny";

	mp[46] = "bunny";
	mp[21] = "fizz";
	mp[30] = "buzz";
	mp[55] = "fuzzy";

	mp[18] = "bee";
	mp[23] = "coconut";
	mp[28] = "diary";
	mp[35] = "fiesta";
	mp[44] = "hello";
	mp[48] = "world";
	mp[53] = "this is a test";
	mp[80] = "hey";

	mp[12] = "no";
	mp[20] = "idea";
	mp[22] = "123";
	mp[24] = "345";
	mp[27] = "27";
	mp[29] = "29";
	mp[33] = "33";
	mp[38] = "38";

	mp[43] = "1";
	mp[45] = "2";
	mp[47] = "3";
	mp[49] = "4";
	mp[51] = "5";
	mp[54] = "6";
	mp[60] = "7";
	mp[90] = "8";

	mp.erase(25);
	mp.erase(55);
	mp.erase(24);
	mp.erase(54);

	mp.erase(22);
	mp.erase(51);

	mp.erase(21);
	mp.erase(53);
	mp.erase(20);
	mp.erase(23);
	mp.erase(23);
	mp.erase(42);
	mp.erase(38);
	mp.erase(35);
	mp.erase(33);
}


/*=====================SET===============================*/

void	constructSet( void )
{
	set<int> a;

	a.insert(7);
	a.insert(8);
	a.insert(9);
	a.insert(9);
	a.insert(9);
	a.insert(45);
	a.insert(-45);


	set<int> b(a);

	set<int> c;
	std::list<int> test;

	c = a;
	for ( int n(0); n < 100000; n++ )
	{
		test.push_back(n);
		c.insert(n);
	}
	b.insert(test.begin(), test.end());
	std::cout << b.size() << std::endl;

}


void	capacityAndModidierSet( void )
{
	set<int> a;

	a.insert(7);
	a.insert(8);
	a.insert(9);
	a.insert(9);
	a.insert(432);
	a.insert(437);
	a.insert(489);
	a.insert(403);
	a.insert(73);
	a.insert(92);
	a.insert(7652);
	a.insert(-1241);
	a.insert(-1212345);
	a.insert(-654);
	a.insert(-789234);
	a.insert(9);
	a.insert(45);
	a.insert(-45);

	std::cout << a.size() << std::endl;
	std::cout << a.max_size() << std::endl;
	std::cout << a.empty() << std::endl;

	set<int>::iterator it1 = a.begin();
	set<int>::iterator it2 = a.begin();
	set<int>::iterator it3 = a.begin();

	for (int i = 0; i < 13; i++) { 
		if ( i < 3 )
			it3++;
		if ( i < 8 )
			it2++;
		it1++; 
	}
	set<int> mp(a.begin(), it1);
	set<int> cpy(it3, it2);


	std::cout << "size of mp : " << mp.size() << "\n";
	std::cout << "size of cpy : " << cpy.size() << "\n";
	cpy = mp;
	std::cout << "size of cpy after taking mp: " << cpy.size() << " and checking empty() " << cpy.empty() << "\n";

	mp.insert(5);
	std::cout << "size :" << mp.size() << "\n";

	std::cout << "\n" << "\n" << "****************** testing the swap function :" << "\n";
	cpy.insert(1000);
	cpy.insert(2000);
	cpy.insert(3000);
	cpy.insert(8000);

	std::cout << "printing both my set to check there differences :\nmp -->" << "\n";
	std::cout << mp.size() << " printing the size first\n";
	std::cout << "cpy -->\n";
	std::cout << cpy.size() << " printing the size first\n";

	mp.swap(cpy);

	std::cout << "printing again after swap :\nmp -->" << "\n";
	std::cout << mp.size() << " printing the size first\n";
	std::cout << "cpy -->\n";
	std::cout << cpy.size() << " printing the size first\n";


	std::cout << "\n******************* end of the test *******************\n\n";
	mp.clear();
	cpy.clear();
	set<int>::iterator itbeg = mp.begin();
	set<int>::iterator itend = mp.end();

	if (itbeg == itend)
		std::cout << "we enter here because (itbeg == itend) because we just clear !!\n";

	std::cout << (mp.key_comp()).operator()(5, 10) << "\n";

	mp.insert(1045);
	std::cout << "finding stuff that does not exit : " << *(--(mp.find(56))) << "\n";
	mp.insert(56);
	std::cout << "finding stuff that does exit : " << *(mp.find(56)) << "\n";

	set<char> myset;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');


	std::cout << "myset['a'] : " << *(myset.find('a')) << "\n";
	std::cout << "myset['b'] : " << *(myset.find('b')) << "\n";
	std::cout << "myset['c'] : " << *(myset.find('c')) << "\n";

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');

	std::cout << "myset['a'] : " << *(myset.find('a')) << "\n";
	std::cout << "myset['b'] : " << *(myset.find('b')) << "\n";
	std::cout << "myset['c'] : " << *(myset.find('c')) << "\n";


	pair<set<char>::iterator,set<char>::iterator> ret;
	ret = myset.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << *(ret.first) << '\n';

	std::cout << "upper bound points to: ";
	std::cout << *(ret.first) << '\n';

	set<int> y;
	set<int> z;


	std::cout << "************************ testing swap function : **************************** \n\n";

	y.insert(1);
	y.insert(2);
	y.insert(3);

	z.insert(8);
	z.insert(9);
	z.insert(10);

	set<int>::iterator rit1 = z.begin();
	set<int>::iterator rit2 = y.begin();

	for (; rit1 != z.end(); rit1++)
		std::cout << "with syntax (*rit) " << (*rit1) << "\n";
	std::cout << "---------------------------------------------\n";
	for (; rit2 != y.end(); rit2++)
		std::cout << "with syntax (*rit) " << (*rit2) << "\n";

	swap(y, z);

	rit1 = z.begin();
	rit2 = y.begin();

	for (; rit1 != z.end(); rit1++)
		std::cout << "with syntax (*rit) " << (*rit1) << "\n";
	std::cout << "---------------------------------------------\n";
	for (; rit2 != y.end(); rit2++)
		std::cout << "with syntax (*rit) " << (*rit2) << "\n";
}


/*=======================================================*/

/*=====================Map viewer========================*/

#if VIEWER

void	display_tree_content(std::string prefix, Node<pair<const int, std::string> >* node, int is_left)
{
	const std::string	e_type = "NODE";
	const std::string	e_colors[2] = {"\x1b[33m", "\x1b[32m"};

	if (is_left == 2)
		std::cout << " ──";
	if (is_left == 1)
		std::cout << prefix << "├──";
	else if (is_left == 0 )
		std::cout << prefix << "└──";
	if ( node->parent != NULL )
	{

		std::cout << e_colors[node->color] << e_type;
		std::cout << " ( key : " << node->content.first;
		//		std::cout << " )\x1b[0m\n";
		std::cout <<", content : " << node->content.second << ")\x1b[0m\n";
	}
	else if ( node->parent == NULL && node->left == NULL && node->right == NULL )
		std::cout << "\x1b[31mNULL\x1b[0m\n";
}

void	print_tree(std::string prefix, Node<pair<const int, std::string> >* node, int is_left)
{

	std::string	new_prefix;

	if ( node->parent != NULL && node->left != NULL && node->right != NULL )
		//	if ( node )
	{
		display_tree_content(prefix, node, is_left);
		if ( is_left == 2 )
			is_left = 0;
		if (!is_left)
		{
			new_prefix = prefix + "    ";
			print_tree(new_prefix, node->right, 1);
			print_tree(new_prefix, node->left, 0);
		}
		else
		{
			new_prefix = prefix + "│   ";
			print_tree(new_prefix, node->right, 1);
			print_tree(new_prefix, node->left, 0);
		}
	}
}

void	print(Node<pair<const int, std::string> >* node)
{
	print_tree("", node->left, 2);
}

void	viewerMap( void )
{
	map<int, std::string> mp;

	mp[42] = "lol";

	mp[50] = "mdr";
	mp[25] = "funny";

	mp[46] = "bunny";
	mp[21] = "fizz";
	mp[30] = "buzz";
	mp[55] = "fuzzy";

	mp[18] = "bee";
	mp[23] = "coconut";
	mp[28] = "diary";
	mp[35] = "fiesta";
	mp[44] = "hello";
	mp[48] = "world";
	mp[53] = "this is a test";
	mp[80] = "hey";

	mp[12] = "no";
	mp[20] = "idea";
	mp[22] = "123";
	mp[24] = "345";
	mp[27] = "27";
	mp[29] = "29";
	mp[33] = "33";
	mp[38] = "38";

	mp[43] = "1";
	mp[45] = "2";
	mp[47] = "3";
	mp[49] = "4";
	mp[51] = "5";
	mp[54] = "6";
	mp[60] = "7";
	mp[90] = "8";

	std::cout << std::endl << "\tPrint MAP" << std::endl << std::endl;
	print(mp.end().base());

	mp.erase(25);
	mp.erase(55);
	mp.erase(24);
	mp.erase(54);

	mp.erase(22);
	mp.erase(51);

	mp.erase(21);
	mp.erase(53);
	mp.erase(20);
	mp.erase(23);
	mp.erase(23);
	mp.erase(42);
	mp.erase(38);
	mp.erase(35);
	mp.erase(33);

	std::cout << std::endl << "\tAfter deleted some elements" << std::endl << std::endl;
	print(mp.end().base());

}
#endif

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

int main(void)
{
	clock_t start = clock();

	#ifndef VIEWER
	// ==== VECTOR ====

	constructVector();
	beginAndEndVector();
	capacityTestVector();
	accessConstructVector();
	modifierVector();
	comparisonVector();

	// ==== STACK ====

	stackTest();

	// ==== MAP ====

	constructMap();
	accessMap();
	capacityAndModidierMap();
	deleteMap();

	// ====== SET ====

	constructSet();
	capacityAndModidierSet();


	test42();
	#else
	viewerMap();
	#endif

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

