/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:29:41 by amahla            #+#    #+#             */
/*   Updated: 2023/01/09 11:06:37 by amahla           ###   ########.fr       */
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

		Node( const T x ) : color(black), parent(NULL), left(NULL),
			right(NULL), content(x)
		{
		}

	};


	template< typename Key,
		typename T,
		typename KeyFirst,
		typename Compare, typename Allocator = std::allocator<T> >
 	class rb_tree {
		
		public:

			typedef Key										key_type;
			typedef T										value_type;
			typedef T&										reference;
			typedef const T									const_reference;
			typedef T*										pointer;
			typedef const T*								const_pointer;
			typedef typename Node<T>::base_pointer			link_type;
			typedef typename Node<T>::const_base_pointer	const_link_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;

			typedef typename Allocator::template rebind< Node<T> >::other	allocNode;

		private:

			Compare						_comp;
			allocNode					_alloc;
			link_type					_nil;
			link_type					_root;
			size_type					_sizeTree;


			inline link_type	_create_node( const value_type& x )
			{
				link_type	node = this->_alloc.allocate(1);
				this->_alloc.construct(node, x);
				node->parent = _nil;
				node->left = _nil;
				node->right = _nil;
				return	node;
			}

			inline void	_deleteNode( link_type& node )
			{
				this->_alloc.destroy( node );
				this->_alloc.deallocate( node, 1 );
			}

			inline void	_deleteTree( link_type& root )
			{
				if ( !root )
					return ;
				if ( root && root->left )
					_deleteTree( root->left );
				if ( root && root->right )
					_deleteTree( root->right );
				_deleteNode( root );
			}

			link_type	_maxTree( link_type x ) const
			{
				while ( x->right )
					x = x->right;
				return x;
			}

			const_link_type	_maxTree( const_link_type x ) const
			{
				while ( x->right )
					x = x->right;
				return x;
			}

			link_type	_minTree( link_type x ) const
			{
				while ( x->left )
					x = x->left;
				return x;
			}

			const_link_type	_minTree( const_link_type x ) const
			{
				while ( x->left )
					x = x->left;
				return x;
			}

			void	_rotateLeft( link_type& node )
			{
				link_type	x = node->right;

				if ( !x )
					return ;

				node->right = x->left;
				if ( x->left )
					x->left->parent = node;
				x->parent = node->parent;
				if ( node->parent )
				{
					if ( node->parent->left == node )
						node->parent->left = x;
					else
						node->parent->right = x;
				}
				else
					this->_root = x;
				node->parent = x;
				x->left = node;
			}

			void	_rotateRight( link_type& node )
			{
				link_type	x = node->left;

				if ( !x )
					return;

				node->left = x->right;
				if ( x->right )
					x->right->parent = node;
				x->parent = node->parent;
				if ( node->parent )
				{
					if ( node->parent->left == node )
						node->parent->left = x;
					else
						node->parent->right = x;
				}
				else
					this->_root = x;
				node->parent = x;
				x->right = node;
			}

			void	_insert( link_type& x )
			{
				(void)x;
			}


		public:

			rb_tree( const Compare& comp = Compare(),
				const Allocator& alloc = Allocator() )
				: _comp(comp), _alloc(alloc), _nil(NULL), _root(_nil),
					_sizeTree(0) { }

			rb_tree( const rb_tree<Key, T, KeyFirst, Compare, Allocator>&	x );

			~rb_tree( void )
			{
				_deleteTree( this->_root );
			}


	};

}

#endif
