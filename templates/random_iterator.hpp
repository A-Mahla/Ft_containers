/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:36 by amahla            #+#    #+#             */
/*   Updated: 2022/12/21 21:57:57 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RANDOM_ITERATOR_HPP__
# define __RANDOM_ITERATOR_HPP__


namespace ft {


	template< typename T >
	class randomIterator {

		public:

			typedef T								value_type;
			typedef T&							 	reference;
			typedef T*								pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

		private:

			pointer	 it;

		public:

			randomIterator( void ) : it(NULL) { }

			randomIterator( pointer rhs ) : it(rhs) { }

			randomIterator( const randomIterator & rhs ) : it(rhs.it) { }

			~randomIterator() {}

			inline randomIterator	& operator=( const randomIterator & rhs )
			{
				if ( this != &rhs )
					this->it = rhs.it;
				return *this;
			}

			inline reference	operator*( void ) const
			{
				return *(this->it);
			}

			inline pointer	operator->( void ) const
			{
				 return this->it;
			}

			inline bool		operator==( const randomIterator & rhs ) const
			{
				return this->it == rhs.it;
			}

			inline bool		operator!=( const randomIterator & rhs ) const
			{
				return !(this->it == rhs.it);
			}

			inline randomIterator	& operator++( void )
			{
				this->it++;
				return *this;
			}

			inline randomIterator	operator++( int )
			{
				randomIterator	tmp = it;

				this->it++;
				return tmp;
			}

			inline randomIterator	& operator--( void )
			{
				this->it--;
				return *this;
			}

			inline randomIterator	operator--( int )
			{
				randomIterator	tmp = it;

				this->it--;
				return tmp;
			}

			inline randomIterator	& operator+=( const long int n )
			{
				difference_type	m = n;

				if (n >= 0)
				{
					while (m--)
						this->it++;
				}
				else
				{
					while (m++ < 0)
						this->it--;
				}

				return *this;
			}

			inline randomIterator	& operator-=( const long int n )
			{
				return *this += -n;
			}

			inline randomIterator	operator+( const long int n ) const
			{
				randomIterator	tmp = this->it;

				return tmp += n;
			}

			friend inline randomIterator	operator+( const long int n,
				const randomIterator & lhs )
			{
				randomIterator	tmp = lhs.it;

				return tmp += n;
			}

			inline randomIterator	operator-( const long int n ) const
			{
				randomIterator tmp = this->it;

				return tmp -= n;
			}

			inline difference_type	operator-( const randomIterator & rhs ) const
			{
				return this->it > rhs.it ? this->it - rhs.it : rhs.it - this->it;
			}

			inline value_type	operator[]( const long int n ) const
			{
				return *(this->it + n);
			}

			inline bool		operator<( const randomIterator & rhs ) const
			{
				return rhs.it - this->it > 0;
			}

			inline bool		operator>( const randomIterator & rhs ) const
			{
				return rhs < *this;
			}

			inline bool		operator>=( const randomIterator & rhs ) const
			{
				return !(rhs < *this);
			}

			inline bool		operator<=( const randomIterator & rhs ) const
			{
				return !(rhs > *this);
			}

	};
}

#endif
