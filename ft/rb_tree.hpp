/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:29:41 by amahla            #+#    #+#             */
/*   Updated: 2023/01/05 17:46:00 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RB_TREE_HPP__
# define __RB_TREE_HPP__

namespace ft {

	enum e_color { black = true, red = false };


	template< typename Key, typename T, typename _KeyOfValue,
		typename Compare, typename Allocator = std::allocator<T> >
 	class rb_tree {
		
		struct Node {	

			typedef Node*		node_pointer;
			typedef const Node*	const_node_pointer;
	
			e_color			color;
			node_pointer*	p;
			node_pointer*	l;
			node_pointer*	r;
			T				content;

		};

		public:

			Node	*p;



	};

}

#endif
