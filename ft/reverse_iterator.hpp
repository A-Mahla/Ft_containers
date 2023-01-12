/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:24:04 by amahla            #+#    #+#             */
/*   Updated: 2023/01/12 18:26:32 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSE_ITERATOR_HPP
# define __REVERSE_ITERATOR_HPP

# include "metaprog.hpp"
# include <iterator>

namespace ft {


	template< typename It >
	class reverse_iterator : public 
		std::iterator<typename iterator_traits<It>::iterator_category,
				typename iterator_traits<It>::value_type,
				typename iterator_traits<It>::difference_type,
				typename iterator_traits<It>::pointer,
				typename iterator_traits<It>::reference> {

		protected:
			
			It	current;

		public:

			typedef It
				iterator_type;
			typedef typename iterator_traits<It>::difference_type
				difference_type;
			typedef typename iterator_traits<It>::reference
				reference;
			typedef typename iterator_traits<It>::pointer
				pointer;


			reverse_iterator( void ) { }

			explicit reverse_iterator( iterator_type x ) : current(x) { }

			template < class U >
			inline reverse_iterator(const reverse_iterator<U>	& u)
			{
				current = u.base();
			}

			inline iterator_type	base( void ) const
			{
				return this->current;
			}

			inline reference	operator*( void ) const
			{
				iterator_type tmp = current;
				return *(--tmp);
			}

			inline pointer	operator->( void ) const
			{
				return &(operator*());
			}

			inline reverse_iterator	& operator++( void )
			{
				(this->current)--;
				return *this;
			}

			inline reverse_iterator	operator++( int )
			{
				reverse_iterator tmp = *this;

				(this->current)--;
				return tmp;
			}

			inline reverse_iterator	& operator--( void )
			{
				(this->current)++;
				return *this;
			}

			inline reverse_iterator	operator--( int )
			{
				reverse_iterator tmp = *this;

				(this->current)++;
				return tmp;
			}

			inline reverse_iterator	operator+( difference_type n ) const
			{
				return reverse_iterator(this->current - n);
			}

			inline reverse_iterator	& operator+=( difference_type n )
			{
				this->current -= n;
				return *this;
			}

			inline reverse_iterator	operator-( difference_type n ) const
			{
				return reverse_iterator(this->current + n);
			}

			inline reverse_iterator	& operator-=( difference_type n )
			{
				this->current += n;
				return *this;
			}

			inline reference	operator[]( difference_type n ) const
			{
				return (this->current)[-n - 1];
			}

	};

	template <class Iterator1, class Iterator2>
	inline bool	operator==( const reverse_iterator<Iterator1>& x,
		const reverse_iterator<Iterator2>& y )
	{
		return x.base() == y.base();
	}

	template <class Iterator1, class Iterator2>
	inline bool	operator<( const reverse_iterator<Iterator1>& x,
		const reverse_iterator<Iterator2>& y )
	{
		return x.base() > y.base();
	}

	template <class Iterator1, class Iterator2>
	inline bool	operator!=( const reverse_iterator<Iterator1>& x,
		const reverse_iterator<Iterator2>& y )
	{
		return x.base() != y.base();
	}

	template <class Iterator1, class Iterator2>
	inline bool	operator>( const reverse_iterator<Iterator1>& x,
		const reverse_iterator<Iterator2>& y )
	{
		return x.base() < y.base();
	}

	template <class Iterator1, class Iterator2>
	inline bool	operator>=( const reverse_iterator<Iterator1>& x,
		const reverse_iterator<Iterator2>& y )
	{
		return x.base() <= y.base();
	}

	template <class Iterator1, class Iterator2>
	inline bool	operator<=( const reverse_iterator<Iterator1>& x,
		const reverse_iterator<Iterator2>& y )
	{
		return x.base() >= y.base();
	}

	template <class Iterator1, class Iterator2>
	inline typename reverse_iterator<Iterator1>::difference_type	operator-(
		const reverse_iterator<Iterator1>& x,
		const reverse_iterator<Iterator2>& y )
	{
		return y.base() - x.base();
	}

	template <class Iterator>
	inline reverse_iterator<Iterator>	operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x )
	{
		return reverse_iterator<Iterator>(x.base() - n);
	}

}


#endif
