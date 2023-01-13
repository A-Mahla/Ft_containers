/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:10:27 by amahla            #+#    #+#             */
/*   Updated: 2023/01/13 18:51:40 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PAIR_HPP__
# define __PAIR_HPP__

# include "rb_tree.hpp"

namespace ft {


	template< typename T1, typename T2 >
	struct pair {

		typedef T1								first_type;
		typedef T2								second_type;

		first_type	first;
		second_type	second;

		pair( void ) : first(), second() { }

		pair( const T1& x, const T2& y ) : first(x), second(y) { }

		template< class U1, class U2 >
		pair( const pair<U1, U2>& x ) : first(x.first), second(x.second) { }

		pair( const pair& x ) : first(x.first), second(x.second) { }

		pair	& operator=( const pair& other )
		{
			if ( this != &other )
			{
				this->first = other.first;
				this->second = other.second;
			}
			return *this;
		}

	};

	template< class T1, class T2 >
	ft::pair<T1,T2>	make_pair( T1 t, T2 u )
	{
		return ft::pair<T1, T2>(t, u);
	}

	template< class T1, class T2 >
	bool	operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template< class T1, class T2 >
	bool	operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool	operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if ( lhs.first == rhs.first )
			return lhs.second < rhs.second;
		return lhs.first < rhs.first;
	}

	template< class T1, class T2 >
	bool	operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs < rhs);
	}

	template< class T1, class T2 >
	bool	operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return rhs < lhs;
	}

	template< class T1, class T2 >
	bool	operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs < rhs);
	}

}

#endif
