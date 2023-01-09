/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:10:27 by amahla            #+#    #+#             */
/*   Updated: 2023/01/09 15:52:35 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

# include "rb_tree.hpp"

namespace ft {


	template< typename T1, typename T2 >
	struct pair {

		typedef typename remove_cv<T1>::type	first_type;
		typedef typename remove_cv<T2>::type	second_type;

		first_type	first;
		second_type	second;

		pair( void ) : first(), second() { }

		pair( const T1& x, const T2& y ) : first(x), second(y) { }

		pair	& operator=( const pair& other )
		{
			this->first = other.first;
			this->second = other.second;
			return *this;
		}

	};

	template< class T1, class T2 >
	pair<T1,T2>	make_pair( T1 t, T2 u )
	{
		return pair<T1, T2>(t, u);
	}

	template< class T1, class T2 >
	bool	operator==( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template< class T1, class T2 >
	bool	operator!=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool	operator<( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		return lhs.first < rhs.first && lhs.second < rhs.second;
	}

	template< class T1, class T2 >
	bool	operator>=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		return !(lhs < rhs);
	}

	template< class T1, class T2 >
	bool	operator>( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		return rhs < lhs;
	}

	template< class T1, class T2 >
	bool	operator<=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
	{
		return !(lhs < rhs);
	}


	template< class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator< std::pair<const Key, T> > >
	class map {

		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef pair<const Key, T>					value_type;
			typedef Compare								key_compare;
			typedef Allocator							allocator_type;
	
			class value_compare
				: public std::binary_function< value_type, value_type, bool >
			{
	
				friend class map;
	
				protected:
	
					Compare	comp;
	
					value_compare( Compare c ) : comp(c) { }
	
				public:
	
					bool	operator()( const value_type& x, const value_type& y ) const
					{
						return comp( x.first, y.first );
					}
			};

//		private:
		public: // TO CHANGE JUST FOR TEST

			typedef rb_tree< key_type, value_type, std::_Select1st<value_type>,
				key_compare, allocator_type >	btree;

			btree	_tree;

		public:

			typedef typename Allocator::reference		reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef typename btree::size_type			size_type;
			typedef typename btree::difference_type		difference_type;

			explicit map( const Compare& comp = Compare(),
				const Allocator& alloc = Allocator() ) : _tree( comp, alloc )
			{ }

			map(const map<Key, T, Compare, Allocator>&	x ) : _tree( x._tree )
			{ }

	};

}

#endif
