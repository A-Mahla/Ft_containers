/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:36 by amahla            #+#    #+#             */
/*   Updated: 2023/01/05 13:28:29 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RANDOM_ITERATOR_HPP__
# define __RANDOM_ITERATOR_HPP__


namespace ft {


	template< typename T >
	class random_iterator {

		public:

			typedef T								value_type;
			typedef T&							 	reference;
			typedef T*								pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

		private:

			pointer	 it;

		public:

			random_iterator( void ) : it(NULL) { }

			random_iterator( pointer rhs ) : it(rhs) { }

			random_iterator( const random_iterator & rhs ) : it(rhs.it) { }

			~random_iterator() {}

			inline random_iterator	& operator=( const random_iterator & rhs )
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

			inline bool		operator==( const random_iterator & rhs ) const
			{
				return this->it == rhs.it;
			}

			inline bool		operator!=( const random_iterator & rhs ) const
			{
				return !(this->it == rhs.it);
			}

			inline random_iterator	& operator++( void )
			{
				this->it++;
				return *this;
			}

			inline random_iterator	operator++( int )
			{
				random_iterator	tmp = it;

				this->it++;
				return tmp;
			}

			inline random_iterator	& operator--( void )
			{
				this->it--;
				return *this;
			}

			inline random_iterator	operator--( int )
			{
				random_iterator	tmp = it;

				this->it--;
				return tmp;
			}

			inline random_iterator	& operator+=( const long int n )
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

			inline random_iterator	& operator-=( const long int n )
			{
				return *this += -n;
			}

			inline random_iterator	operator+( const long int n ) const
			{
				random_iterator	tmp = this->it;

				return tmp += n;
			}

			friend inline random_iterator	operator+( const long int n,
				const random_iterator & lhs )
			{
				random_iterator	tmp = lhs.it;

				return tmp += n;
			}

			inline random_iterator	operator-( const long int n ) const
			{
				random_iterator tmp = this->it;

				return tmp -= n;
			}

			inline difference_type	operator-( const random_iterator & rhs ) const
			{
				return this->it - rhs.it;
			}

			inline value_type	operator[]( const long int n ) const
			{
				return *(this->it + n);
			}

			inline bool		operator<( const random_iterator & rhs ) const
			{
				return rhs.it - this->it > 0;
			}

			inline bool		operator>( const random_iterator & rhs ) const
			{
				return rhs < *this;
			}

			inline bool		operator>=( const random_iterator & rhs ) const
			{
				return !(rhs < *this);
			}

			inline bool		operator<=( const random_iterator & rhs ) const
			{
				return !(rhs > *this);
			}

			operator random_iterator< const T >( void ) const
			{
				return random_iterator< const T >(this->it);
			}

	};
}

#endif
