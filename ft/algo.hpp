/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:09:59 by amahla            #+#    #+#             */
/*   Updated: 2023/01/13 20:54:26 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ALGO_HPP__
# define __ALGO_HPP__

namespace ft {

	template< typename InputIt1, typename InputIt2 >
	bool	lexicographical_compare( InputIt1 first1, InputIt1 last1,
	                              InputIt2 first2, InputIt2 last2 )
	{
		while ( first1 != last1 && first2 != last2 )
		{
			if ( *first1 < *first2 )
				return true;
			else if ( *first2 < *first1 )
				return false;
			first1++;
			first2++;
		}
		return first1 == last1 && first2 != last2;
	}
	
	template<class InputIt1, class InputIt2, class Compare>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
	                             InputIt2 first2, InputIt2 last2, Compare comp)
	{
		while ( first1 != last1 && first2 != last2 )
		{
			if ( comp(*first1, *first2) )
				return true;
			else if ( comp(*first2, *first1) )
				return false;
			first1++;
			first2++;
		}
		return first1 == last1 && first2 != last2;
	}

	template< class InputIt1, class InputIt2 >
	bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
	{
		for ( ; first1 != last1 && *first1 == *first2; first1++, first2++ )
			;
		return first1 == last1;
	}

	template< class InputIt1, class InputIt2, class BinaryPredicate >
	bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2,
		BinaryPredicate p )
	{
		for ( ; first1 != last1 && p(*first1, *first2); ++first1, ++first2 )
			;
		return first1 == last1;
	}

}

#endif
