/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:19:33 by amahla            #+#    #+#             */
/*   Updated: 2023/01/13 21:13:18 by amahla           ###   ########.fr       */
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
			typedef typename ft::random_iterator<T>					iterator;
			typedef typename ft::random_iterator<const T>			const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:

			allocator_type	_alloc;
			pointer			_start;
			pointer			_finish;
			pointer			_end_of_storage;

			inline void	_realloc( size_type sz, bool construct, T c = T() )
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
					else if ( construct )
						this->_alloc.construct( &(*it), c );
					else
						break ;
				}
				this->_finish = this->_start + n;
			}

			inline size_type _hdlCapacity( size_type n )
			{
				if ( capacity() == 0 )
					return 1;
				else if ( n > capacity() * 2 )
					return n;
				else
					return capacity() * 2;
			}

		protected:

			/* @member get_allocator()
			 *
			 * @brief replaces the contents of the container by n * u 
			 *
			 * @return allocator_type*/

			allocator_type	get_allocator( void ) const
			{
				return ( this->_alloc );
			}

		public:

			// ===== CONSTRUCT/COPY/DESTROY =====

			/* @member vector()
			 *
			 * @brief construct by default
			 *
			 * @return NO*/

			inline explicit	vector( const Allocator& alloc = Allocator() )
				: _alloc(alloc), _start(NULL), _finish(NULL), _end_of_storage(NULL)
			{ }

			/* @member vector()
			 *
			 * @brief construct with size and value
			 *
			 * @return NO*/

			inline explicit	vector( size_type n, const T& value = T(),
					const Allocator& alloc = Allocator() )
			{
				this->_alloc = alloc;
				this->_start = this->_alloc.allocate(n);
				this->_finish = this->_start + n;
				for ( pointer x = this->_start; x != this->_finish; x++ )
					this->_alloc.construct(x, T(value));
				this->_end_of_storage = _finish;
			}

			/* @member vector()
			 *
			 * @brief construct with a range of iterators
			 *
			 * @return NO*/

			template <class InputIterator>
			inline	vector(InputIterator first,
				typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type last,
				const Allocator& alloc = Allocator())
			{
				this->_alloc = alloc;
				this->_start = this->_alloc.allocate( std::distance(first, last) );
				this->_finish = this->_start;
				this->_end_of_storage = this->_start + ( std::distance(first, last) );
				insert( begin(), first, last );
			}

			/* @member vector()
			 *
			 * @brief construct by copy
			 *
			 * @return NO*/

			inline	vector( const vector<T, Allocator>&	x )
			{
				pointer p = this->_alloc.allocate(x.size());

  				for ( size_type i = 0; i < x.size(); i++ )
					this->_alloc.construct(p + i, x[i]);
				this->_start = p;
  				this->_finish = this->_start + x.size();
  				this->_end_of_storage = this->_finish;
			}

			/* @member ~vector()
			 *
			 * @brief destruct by default
			 *
			 * @return NO*/

			inline	~vector( void )
			{
				for( pointer p = this->_start ; p != this->_finish; p++ )
					this->_alloc.destroy(p);
				this->_alloc.deallocate(this->_start, capacity());
			}

			/* @member operator=()
			 *
			 * @brief Vector assignment operator
			 *
			 * @return NO*/

			vector<T,Allocator>&	operator=( const vector<T,Allocator>& x )
			{
				if ( this != &x )
				{
					vector<T ,Allocator> tmp(x);

					swap(tmp);
				}
				return *this;
			}

			/* @member assign()
			 *
			 * @brief replaces the contents of the container by a range of iterators 
			 *
			 * @return void*/

			template <class InputIterator>
			inline void	assign(InputIterator first,
				typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type last)
			{
				for ( pointer p = this->_start; p != this->_finish; p++ )
					this->_alloc.destroy( p );
				this->_finish = this->_start;
				insert( begin(), first, last );
			}

			/* @member assign()
			 *
			 * @brief replaces the contents of the container by n * u 
			 *
			 * @return void*/

			inline void	assign( size_type n, const T& u )
			{
				for ( pointer p = this->_start; p != this->_finish; p++ )
					this->_alloc.destroy( p );
				this->_finish = this->_start;
				insert( begin(), n, u );
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


			/* @brief the max_size can be stored in this instance
			 *
			 * @return size_type*/

			inline size_type	max_size( void ) const
			{
				return this->_alloc.max_size();
			}

			/* @member resize()
			 *
			 * @brief change the size of the vector and realloc if there aren't
			 *  place.
			 *
			 * @return void*/

			inline void	resize( size_type sz, T c = T() )
			{
				if ( sz > max_size() )
					throw std::length_error("std::length_error");
				if ( sz > capacity() )
					_realloc( sz, true, c );
				else
				{
						while ( size() > sz )
						{
							this->_alloc.destroy( this->_finish - 1 );
							(this->_finish)--;
						}

						while ( size() < sz )
						{
							this->_alloc.construct( this->_finish, c );
							(this->_finish)++;
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
			 * @brief change the capacity of the vector and realloc if there
			 *	aren't place
			 *
			 * @return void*/

			inline void	reserve( size_type n )
			{
				if ( n > max_size() )
					throw std::length_error("vector::reserve");
				if ( n > capacity() )
					_realloc( n, false );
			}


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

			inline void push_back( const T& x )
			{
				if ( size() == capacity() )
					reserve( _hdlCapacity( size() + 1 ) );
				this->_alloc.construct( this->_finish++, T(x) );
			}

			/* @member pop_back()
			 *
			 * @brief remove a elem from the end
			 *
			 * @return void*/

			inline void pop_back( void )
			{
				if ( begin() != end() )
					this->_alloc.destroy( --(this->_finish) );
			}

			/* @member insert()
			 *
			 * @brief insert value before the position
			 *
			 * @return iterator*/

			iterator	insert( iterator position, const T& x )
			{

				const size_type n = position - begin();

				push_back(T());
				
				// iterator position in new vector() = this->_start + n
				// memmove all data from position to position + n at the end
				for ( pointer p = this->_finish - 1; p != this->_start + n; p-- )
				{
					this->_alloc.destroy(p);
					this->_alloc.construct( p, *(p - 1) );
				}

				// insert data x
				this->_alloc.destroy( this->_start + n );
				this->_alloc.construct( this->_start + n, x );
				return this->_start + n;
			}

			/* @member insert()
			 *
			 * @brief insert n * value before the position
			 *
			 * @return iterator*/

			inline void	insert( iterator position, size_type n, const T& x )
			{
				const size_type	nPos = position - begin();
				size_type		nEnd = end() - begin();

				// resize if > capacity() and construct
				if ( nEnd + n > capacity() )
					reserve( nEnd + n );
				for ( size_type	i = 0; i < n; i++ )
					this->_alloc.construct( this->_finish++, x );

				// iterator position in new vector() = this->_start + nPos
				// memmove all data from position to position + n at the end
				for ( pointer p = this->_finish - 1; p != this->_start + nPos + n - 1; p-- )
				{
					this->_alloc.destroy(p);
					this->_alloc.construct( p, *(this->_start + --nEnd) );
				}

				// insert data n * x
				for ( size_type i = 0; i < n; i++ )
				{
					this->_alloc.destroy( this->_start + nPos + i);
					this->_alloc.construct( this->_start + nPos + i, x );
				}
			}

			/* @member insert()
			 *
			 * @brief insert range of iterator before the position
			 *
			 * @return iterator*/

			template < typename InputIterator >
			inline void	insert( iterator position, InputIterator first,
				typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type last )
			{
				const size_type	nPos = position - begin();
				size_type		n = std::distance(first, last);
				size_type		nEnd = end() - begin();

				// resize if > capacity() and construct
				if ( nEnd + n > capacity() )
					reserve( nEnd + n );
				for ( size_type	i = 0; i < n; i++ )
					this->_alloc.construct( this->_finish++, T() );

				// iterator position in new vector() this->_start + nPos + n
				// memmove all data from position to position + n at the end
				for ( pointer p = this->_finish - 1; p != this->_start + nPos + n - 1; p-- )
				{
					this->_alloc.destroy(p);
					this->_alloc.construct( p, *(this->_start + --nEnd) );
				}

				// insert range of iterator [first, last)
				for ( size_type i = 0; i < n; i++ )
				{
					this->_alloc.destroy( this->_start + nPos + i);
					this->_alloc.construct( this->_start + nPos + i, *(first++) );
				}
			}

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
				while ( tmpFirst != endIt )
					this->_alloc.destroy( &(*(tmpFirst++)) );
				return first;
			}

			/* @member swap()
			 *
			 * @brief exchanges the contents of the container with other
			 *
			 * @return void*/

			inline void	swap( vector<T, Allocator>	& other )
			{
				pointer	tmp[3] = { other._start, other._finish, other._end_of_storage };
				allocator_type	tmpAlloc = other._alloc;

				other._start = this->_start;
				other._finish = this->_finish;
				other._end_of_storage = this->_end_of_storage;
				other._alloc = this->_alloc;

				this->_start = tmp[0];
				this->_finish = tmp[1];
				this->_end_of_storage = tmp[2];
				this->_alloc = tmpAlloc;

			}

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

		template <class T, class Allocator>
		inline bool operator==( const vector<T,Allocator>& x,
			const vector<T,Allocator>& y )
		{
			return x.size() == y.size()
				&& ft::equal(x.begin(), x.end(), y.begin());
		}

		template <class T, class Allocator>
		inline bool	operator<( const vector<T,Allocator>& x,
			const vector<T,Allocator>& y )
		{
			return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
		}

		template <class T, class Allocator>
		inline bool	operator!=(const vector<T,Allocator>& x,
			const vector<T,Allocator>& y)
		{
			return !(x == y);
		}

		template <class T, class Allocator>
		inline bool	operator>(const vector<T,Allocator>& x,
			const vector<T,Allocator>& y)
		{
			return ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end());
		}

		template <class T, class Allocator>
		inline bool	operator>=(const vector<T,Allocator>& x,
			const vector<T,Allocator>& y)
		{
			return !(x < y);
		}

		template <class T, class Allocator>
		inline bool	operator<=(const vector<T,Allocator>& x,
			const vector<T,Allocator>& y)
		{
			return !(x > y);
		}

		//===== SPECIALISED ALGORITHMS =====

		template <class T, class Allocator>
		inline void	swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
		{
			x.swap(y);
		}
}

#endif
