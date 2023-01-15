/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metaprog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:36 by amahla            #+#    #+#             */
/*   Updated: 2023/01/15 22:54:04 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITERATOR_TRAIT_HPP__
# define __ITERATOR_TRAIT_HPP__

namespace ft {

/*===========================================================================*/

				/*		METAPROGRAMMING TOOLS	*/

	/*	integral_constant	*/
	template< typename T, T val >
	struct integral_constant {
		typedef T	type;
		static const T	value = val;
		const T operator()() const { return value; }
	};


	/*	true/false -- inheterite from integral_constant		*/
	struct true_type : integral_constant< bool, true > { };
	struct false_type : integral_constant< bool, false > { };


/*	== Other example of differents metaproggramming structures ==

	//	is_same
	template< typename T, typename U >
	struct is_same : false_type { };

	template< typename T >
	struct is_same< T, T > : true_type { };


	//	remove_cv_qualified	
	template< typename T >
	struct remove_cv {
		typedef T type;
	};

	template< typename T >
	struct remove_cv< T const > {
		typedef T type;
	};

	template< typename T >
	struct remove_cv< T volatile > {
		typedef T type;
	};

	template< typename T >
	struct remove_cv< T const volatile > {
		typedef T type;
	};*/

/*===========================================================================*/

				/*			REQUIREMENTS		*/

	/*		iterator_traits		*/
	template< typename Iter >
	struct iterator_traits {
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template< typename Iter >
	struct iterator_traits<Iter*> {
		typedef Iter							value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef Iter*							pointer;
		typedef Iter&							reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template< typename Iter >
	struct iterator_traits<const Iter*> {
		typedef Iter							value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const Iter*						pointer;
		typedef const Iter&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};


	/*	enable_if - S(ubstitution) F(ailure) I(s) N(ot) A(n) E(rror)	*/
	template< bool, typename T = void >
	struct enable_if {
		typedef T	type;
	};

	template< typename T >
	struct enable_if< false, T > { };


	/*	is_integral		*/
	template< typename T >
	struct is_integral : false_type { };

	template< >
	struct is_integral< bool > : true_type {};

	template< >
	struct is_integral< char > : true_type {};

	template< >
	struct is_integral< signed char > : true_type {};

	template< >
	struct is_integral< unsigned char > : true_type {};

	template< >
	struct is_integral< wchar_t > : true_type {};

	template< >
	struct is_integral< short int > : true_type {};

	template< >
	struct is_integral< unsigned short int > : true_type {};

	template< >
	struct is_integral< int > : true_type {};

	template< >
	struct is_integral< unsigned int > : true_type {};

	template< >
	struct is_integral< long int > : true_type {};

	template< >
	struct is_integral< unsigned long int > : true_type {};

	template< >
	struct is_integral< long long int > : true_type {};

	template< >
	struct is_integral< unsigned long long int > : true_type {};

	template< typename T >
	struct is_integral< T const > : is_integral< T > {};

	template< typename T >
	struct is_integral< T volatile > : is_integral< T > {};


}

#endif
