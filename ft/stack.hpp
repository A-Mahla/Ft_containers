/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:43:22 by amahla            #+#    #+#             */
/*   Updated: 2023/01/05 12:10:12 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
# define __STACK_HPP__

# include "vector.hpp"

namespace ft {

	template< typename T, typename Container = ft::vector<T> >
	class stack {

		public:

			typedef typename Container::value_type	value_type;
			typedef typename Container::size_type	size_type;
			typedef Container						container_type;

		protected:

			container_type	c;

		public:

			explicit	stack( const Container& x = Container() ) : c(x) { }

			inline bool	empty( void ) const
			{
				return c.empty();
			}

			inline size_type	size( void ) const
			{
				return c.size();
			}

			inline value_type	& top( void )
			{
				return c.back();
			}

			inline const value_type	& top( void ) const
			{
				return c.back();
			}

			inline void	push( const value_type& x )
			{
				c.push_back(x);
			}

			inline void pop( void )
			{
				c.pop_back();
			}

	};

	template <class T, class Container>
	inline bool	operator==( const stack<T, Container>& x,
		const stack<T, Container>& y )
	{
		return x == y;
	}

	template <class T, class Container>
	inline bool	operator<(const stack<T, Container>& x,
		const stack<T, Container>& y)
	{
		return x < y;
	}

	template <class T, class Container>
	inline bool	operator!=(const stack<T, Container>& x,
		const stack<T, Container>& y)
	{
		return x != y;
	}

	template <class T, class Container>
	inline bool	operator>(const stack<T, Container>& x,
		const stack<T, Container>& y)
	{
		return x > y;
	}

	template <class T, class Container>
	inline bool	operator>=(const stack<T, Container>& x,
		const stack<T, Container>& y)
	{
		return x >= y;
	}

	template <class T, class Container>
	inline bool	operator<=(const stack<T, Container>& x,
		const stack<T, Container>& y)
	{
		return x <= y;
	}


}

#endif
