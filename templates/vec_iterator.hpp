/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:36 by amahla            #+#    #+#             */
/*   Updated: 2022/12/20 21:04:19 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VEC_ITERATOR_HPP__
# define __VEC_ITERATOR_HPP__

# include "metaprog.hpp"

namespace ft {

	template< typename T >
	class random_access_iterator {


		public:

			typedef T								value_type;
			typedef T&								reference;
			typedef T*								pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

		private:

			pointer	 it;

		public:

			random_access_iterator( void ) : it(NULL) {}

			random_access_iterator( const random_access_iterator & rhs ) : it(rhs.it) { }

			~random_access_iterator() {}

			random_access_iterator	& operator=( const random_access_iterator & rhs )
			{
				this->it = rhs.it;
				return *this;
			}

			random_access_iterator	& operator=( random_access_iterator & rhs )
			{
				this->it = rhs.it;
				return *this;
			}

			reference operator*( void ) const
			{
				return *(this->it);
			}


	};
}

#endif
