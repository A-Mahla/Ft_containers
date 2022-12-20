/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:36 by amahla            #+#    #+#             */
/*   Updated: 2022/12/20 12:12:53 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VEC_ITERATOR_HPP__
# define __VEC_ITERATOR_HPP__

namespace ft {

	template< typename T >
	class iterator {

		public:

			typedef T								value_type;
			typedef T&								reference;
			typedef T*								pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

	};
}

#endif
