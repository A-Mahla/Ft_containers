/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:19:33 by amahla            #+#    #+#             */
/*   Updated: 2022/12/21 21:54:33 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include "random_iterator.hpp"
# include <memory>

namespace ft {


	template< typename T, typename Allocator = std::allocator<T> >
	class vector {
	
		public:

			typedef T										value_type;
			typedef T&										reference;
			typedef const T&								const_reference;
			typedef Allocator								allocator_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef typename ft::randomIterator<T>			iterator;
			typedef typename ft::randomIterator<const T>	const_iterator;

		private:

			allocator_type	_alloc;
			pointer			_start;
			pointer			_finish;
			pointer			_end_of_storage;
			size_type		_nelem;

		public:

			vector( const Allocator& = Allocator() )
			{
				_start = NULL;
				_finish = NULL;
				_end_of_storage = NULL;
				_nelem = 0;
			}

			explicit	vector<T>( size_type n, const T& value = T(),
					const Allocator& = Allocator() )
			{
				_start = _alloc.allocate(n);
				_alloc.construct(_start, value);
				_finish = _start + n;
				_end_of_storage = _finish;
				_nelem = n;
			}

//			template <class InputIterator>
//				vector(InputIterator first, InputIterator last,
//				const Allocator& = Allocator())
//			{}

/*			vector( const vector<T,Allocator>& x )
			{
				// Allocate enough memory to store the elements of x
				pointer p = alloc.allocate(x.size());

  				// Copy the elements of x into the new vector
  				for (const_iterator i = x.begin(); i != x.end(); ++i, ++p)
					alloc.construct(p, *i);

  				// Update the pointers of the new vector
  				start = p;
  				finish = p + x.size();
  				end_of_storage = p + x.size();
			}
*/
			inline iterator			begin( void )
			{
				return iterator(_start);
			}

			inline const_iterator	begin( void ) const
			{
				return const_iterator(_start);
			}

			inline iterator			end( void )
			{
				return iterator(_start);
			}

			inline const_iterator	end( void ) const
			{
				return const_iterator(_start);
			}

	};
}


#endif
