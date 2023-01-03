/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:19:33 by amahla            #+#    #+#             */
/*   Updated: 2023/01/03 14:16:44 by amahla           ###   ########.fr       */
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

			typedef T												value_type;
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef Allocator										allocator_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef typename ft::randomIterator<T>					iterator;
			typedef typename ft::randomIterator<const T>			const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:

			allocator_type	_alloc;
			pointer			_start;
			pointer			_finish;
			pointer			_end_of_storage;

			difference_type	_hdlCapacity;

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

			vector( const vector<T, Allocator>&	x )
			{
				this->_start = this->_alloc.allocate(x.size());
				pointer	p = this->_start;

  				for (const_iterator i = x.begin(); i != x.end(); i++, p++)
					this->_alloc.construct(p, *i);
  				this->_finish = this->_start + x.size();
  				this->_end_of_storage = p + x.size();
			}

			inline	~vector( void )
			{
				for( pointer p = this->_start ; p != this->_finish; p++ )
					this->_alloc.destroy(p);
				this->_alloc.deallocate(this->_start, capacity());
			}

			// ===== ITERATORS =====

			/* @member begin() / end() / rbegin() / rend()
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

			inline reverse_iterator	rbegin( void )
			{
				return reverse_iterator(end());
			}

			inline const_reverse_iterator	rbegin( void ) const
			{
				return const_reverse_iterator(end());
			}

			inline reverse_iterator	rend( void )
			{
				return reverse_iterator(begin());
			}

			inline const_reverse_iterator	rend( void ) const
			{
				return const_reverse_iterator(begin());
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

			inline void	resize( size_type sz, T c = T() )
			{
				if ( sz > capacity() )
				{
					vector<T> tmp(*this);
					size_type n = 0;

					for ( iterator it = begin(); it != end(); it++ )
						this->_alloc.destroy( &(*it) );
					this->_alloc.deallocate( this->_start, capacity() );
					this->_start = _alloc.allocate( sz );
					this->_end_of_storage = this->_start + sz;
					for ( iterator it = begin(); n < sz; it++, n++ )
					{
						if ( n < tmp.size() )
							this->_alloc.construct( &(*it), tmp[n] );
						else
							this->_alloc.construct( &(*it), c );
					}
					this->_finish = this->_start + n;
				}
				else
				{
					if ( size() > sz )
					{
						while ( size() > sz )
						{
							this->_alloc.destroy( this->_finish - 1 );
							this->_alloc.construct( this->_finish - 1, c );
							(this->_finish)--;
						}
					}
					else
					{
						while ( size() < sz )
						{
							this->_alloc.construct( this->_finish, c );
							(this->_finish)++;
						}
					}
				}
			}

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


			// ===== MODIFIERS =====

			/* @member push_back()
			 *
			 * @brief add a elem at the end
			 *
			 * @return void*/

			void push_back( const T& x );

			/* @member pop_back()
			 *
			 * @brief remove a elem from the end
			 *
			 * @return void*/

			void pop_back( void );

			/* @member insert()
			 *
			 * @brief insert at an iterator position
			 *
			 * @return iterator*/

			iterator	insert( iterator position, const T& x );

			/* @member erase()
			 *
			 * @brief erase an elem (iterator) from current instance
			 *
			 * @return iterator*/

			iterator	erase( iterator pos )
			{
				erase( pos, pos + 1 );
				return pos;
			}

			/* @member erase()
			 *
			 * @brief erase a range of iterators from current instance
			 *
			 * @return iterator*/

			iterator	erase( iterator first, iterator last )
			{
				iterator	tmpFirst = first;
				iterator	endIt = end();

				for ( ; last != endIt; tmpFirst++, last++ )
				{
					this->_alloc.destroy( &(*tmpFirst) );
					this->_alloc.construct( &(*tmpFirst), *last );
				}
				this->_finish = &(*tmpFirst);
				while ( tmpFirst++ != endIt )
					this->_alloc.destroy( &(*tmpFirst) );
				return first;
			}

			/* @member swap()
			 *
			 * @brief exchanges the contents of the container with other
			 *
			 * @return void*/


			void	swap( vector<T, Allocator>	& other );

			/* @member clear()
			 *
			 * @brief (alloc.)destroy all element of current instance
			 *
			 * @return void*/

			inline void	clear()
			{
				for( pointer p = this->_start ; p != this->_finish; p++ )
					this->_alloc.destroy(p);
				this->_finish = this->_start;
			}


	};
}

#endif
