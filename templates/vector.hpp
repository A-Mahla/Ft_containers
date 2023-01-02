/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:19:33 by amahla            #+#    #+#             */
/*   Updated: 2023/01/02 09:13:10 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include "random_iterator.hpp"
# include "reverse_iterator.hpp"
# include "algo.hpp"
# include <memory> 
# include <sstream>

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

		public:

			vector( const Allocator& = Allocator() )
				: _start(NULL), _finish(NULL), _end_of_storage(NULL)
			{
				_start = NULL;
				_finish = NULL;
				_end_of_storage = NULL;
			}

			explicit	vector( size_type n, const T& value = T(),
					const Allocator& = Allocator() )
			{
				this->_start = this->_alloc.allocate(n);
				this->_finish = _start + n;
				for ( pointer x = this->_start; x != this->_finish; x++ )
					this->_alloc.construct(x, value);
				this->_end_of_storage = _finish;
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

			// ===== ITERATORS =====

			/* @member begin() and end()
			 *
			 * @return iterator*/

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
				return iterator(_finish);
			}

			inline const_iterator	end( void ) const
			{
				return const_iterator(_finish);
			}

			// ===== CAPACITY =====

			/* @member size()
			 *
			 * @brief the size of current instance is return
			 *
			 * @return size_type*/

			inline size_type	size( void ) const
			{
				return this->_finish - this->_start;
			}

			/* @member max_size()
			 *
			 * @brief the max_size can be stored in this instance
			 *
			 * @return size_type*/

			inline size_type	max_size( void ) const
			{
				return this->_alloc.max_size();
			}

			/* @member resize()
			 *
			 * @brief
			 *
			 * @return void*/

			inline void	resize( size_type sz, T c = T() );

			/* @member capacity()
			 *
			 * @brief the capacity before realloc of current instance is return
			 *
			 * @return size_type*/

			inline size_type	capacity( void ) const
			{
				return this->_end_of_storage - this->_start;
			}

			/* @member empty()
			 *
			 * @brief boolean statement about size()==0 of current instance
			 *
			 * @return size_type*/

			inline bool	empty( void ) const
			{
				return !(this->size());
			}

			/* @member reserve()
			 *
			 * @brief
			 *
			 * @return void*/

			inline void	reserve( size_type n );


			// ===== ELEMENT ACCESS =====

			/* @member operator[]()
			 *
			 * @brief access operator read/write
			 *
			 * @return reference*/

			inline reference	operator[]( size_type n )
			{
				return *(this->_start + n);
			}

			/* @member operator[]()
			 *
			 * @brief access operator read only
			 *
			 * @return const_reference*/

			inline const_reference	operator[]( size_type n ) const
			{
				return *(this->_start + n);
			}

			/* @member at()
			 *
			 * @brief access operator read/write
			 *
			 * @return reference*/

			inline reference	at( size_type n )
			{
				if ( n >= size() )
				{
					std::stringstream error;
					error << "vector::_M_range_check: n (which is ";
					error << n << ") >= this->size() (which is ";
					error << this->size() << ")";
					throw std::out_of_range(error.str());
				}
				return *(this->_start + n);
			}

			/* @member at()
			 *
			 * @brief access operator read only
			 *
			 * @return const_reference*/

			inline const_reference	at( size_type n ) const
			{
				if ( n >= size() )
				{
					std::stringstream error;
					error << "vector::_M_range_check: n (which is ";
					error << n << ") >= this->size() (which is ";
					error << this->size() << ")";
					throw std::out_of_range(error.str());
				}
				return *(this->_start + n);
			}

			/* @member front()
			 *
			 * @brief access first elem write/read
			 *
			 * @return reference*/

			inline reference	front( void )
			{
				return *(this->_start);
			}

			/* @member front()
			 *
			 * @brief access first elem read only
			 *
			 * @return const_reference*/

			inline const_reference	front( void ) const
			{
				return *(this->_start);
			}

			/* @member back()
			 *
			 * @brief access first elem write/read
			 *
			 * @return reference*/

			inline reference	back( void )
			{
				return *(this->_finish - 1);
			}

			/* @member back()
			 *
			 * @brief access first elem read only
			 *
			 * @return const_reference*/

			inline const_reference	back( void ) const
			{
				return *(this->_finish - 1);
			}

			

	};
}

#endif
