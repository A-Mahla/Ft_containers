/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:29:41 by amahla            #+#    #+#             */
/*   Updated: 2023/01/06 12:35:57 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RB_TREE_HPP__
# define __RB_TREE_HPP__

	enum e_color { black = true, red = false };

	template< typename T >
	struct Node
	{	
		e_color			color;
		node_pointer*	p;
		node_pointer*	l;
		node_pointer*	r;
		T				content;
	};


namespace ft {

	template< typename Key, typename T, typename KeyFirst,
		typename Compare, typename Allocator = std::allocator<T> >
 	class rb_tree {
		
		public:

			typedef Key								key_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef const T*						const_pointer;
			typedef T&								reference;
			typedef const T&						const_reference;
			typedef Node<T>*						link_type;
			typedef const Node<T>*					const_link_type;
			typedef size_t							size_type;
			typedef ptrdiff_t						difference_type;
			typedef Allocator						allocator_type;

		private:

		Compare		_comp;
		Node<T>		_root;
		size_type	_sizeTree;



	};

}

#endif
