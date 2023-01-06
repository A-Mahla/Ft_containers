/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:29:41 by amahla            #+#    #+#             */
/*   Updated: 2023/01/06 19:06:01 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RB_TREE_HPP__
# define __RB_TREE_HPP__

# include "metaprog.hpp"

namespace ft {


	enum e_color { black = true, red = false };


	template< typename T >
	struct Node
	{
		typedef Node*		base_pointer;
		typedef const Node*	const_base_pointer;

		e_color			color;
		base_pointer	parent;
		base_pointer	left;
		base_pointer	right;
		T				content;

	};


	template< typename Key,
		typename T,
		typename KeyFirst,
		typename Compare, typename Allocator = std::allocator<T> >
 	class rb_tree {
		
		public:

			typedef Key										key_type;
			typedef T										value_type;
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef typename Node<T>::base_pointer			link_type;
			typedef typename Node<T>::const_base_pointer	const_link_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;

			typedef typename Allocator::template rebind< Node<T> >::other	allocNode;

		private:

			Compare						_comp;
			allocNode					_alloc;
			link_type					_root;
			size_type					_sizeTree;

//			void	_create_node;

			void	_deleteTree( link_type root )
			{
				if ( !root )
					return ;
				if ( root && root->left )
					_deleteTree( root->left );
				if ( root && root->right )
					_deleteTree( root->right );
				this->_alloc.destroy( root );
				this->_alloc.deallocate( root, 1 );
			}

		public:

			rb_tree( const Compare& comp = Compare(),
				const Allocator& alloc = Allocator() )
				: _comp(comp), _alloc(alloc), _root(NULL), _sizeTree(0) { }

			rb_tree( const rb_tree<Key, T, KeyFirst, Compare, Allocator>&	x );

			~rb_tree( void )
			{
				_deleteTree( this->_root );
			}


	};

}

#endif
