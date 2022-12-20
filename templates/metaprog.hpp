/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metaprog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:36 by amahla            #+#    #+#             */
/*   Updated: 2022/12/19 19:37:04 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITERATOR_TRAIT_HPP__
# define __ITERATOR_TRAIT_HPP__

namespace ft {

	template< typename Iter >
	struct iterator_traits {
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template< typename T, T val >
	struct integral_constant {
		typedef T type;
		static const T value = val;
	};

}

#endif
