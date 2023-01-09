/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:29:41 by amahla            #+#    #+#             */
/*   Updated: 2023/01/09 14:00:06 by amahla           ###   ########.fr       */
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

		Node( const T& x ) : color(black), parent(NULL), left(NULL),
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

//		private:
		public: //TO TEST JUST FOR TEST

			Compare						_comp;
			allocNode					_alloc;
			link_type					_nil;
			link_type					_root;
			size_type					_sizeTree;


			inline link_type	_create_node( const value_type x )
			{
				link_type	node = this->_alloc.allocate(1);
				this->_alloc.construct(node, x);
				node->parent = _nil;
				node->left = _nil;
				node->right = _nil;
				return	node;
			}

			inline void	_destroyNode( link_type& node )
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
				_destroyNode( root );
			}

			link_type	_maxTree( link_type x )
			{
				while ( x->right )
					x = x->right;
				return x;
			}

			link_type	_maxTree( link_type x ) const
			{
				while ( x->right )
					x = x->right;
				return x;
			}

			link_type	_minTree( link_type x )
			{
				while ( x->left )
					x = x->left;
				return x;
			}

			link_type	_minTree( link_type x ) const
			{
				while ( x->left )
					x = x->left;
				return x;
			}

			link_type	_next( link_type node )
			{
				if ( node->right )
					return _minTree(node->right);
				while ( node->parent && node->parent->right == node )
					node = node->parent;
				return node->parent;
			}

			link_type	_next( link_type node ) const
			{
				if ( node->right )
					return _minTree(node->right);
				while ( node->parent && node->parent->right == node )
					node = node->parent;
				return node->parent;
			}

			link_type	_prev( link_type node )
			{
				if ( node->left )
					return _maxTree(node->_left);
				while ( node->parent && node->parent->left == node )
					node = node->parent;
				return node->parent;
			}

			link_type	_prev( link_type node ) const
			{
				if ( node->left )
					return _maxTree(node->_left);
				while ( node->parent && node->parent->left == node )
					node = node->parent;
				return node->parent;
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

			link_type	_find( key_type& k )
			{
				link_type	x = this->_root;

				while ( x && KeyFirst()(x->value) != k )
				{
					if ( KeyFirst()(x->value) > k )
						x = x->left;
					else
						x = x->right;
				}
				return x;
			}

			link_type	_find( key_type& k ) const
			{
				link_type	x = this->_root;

				while ( x && KeyFirst()(x->value) != k )
				{
					if ( KeyFirst()(x->value) > k )
						x = x->left;
					else
						x = x->right;
				}
				return x;
			}

			void	_insertNode( link_type& node )
			{
				link_type	y = this->_nil;
				link_type	x = this->_root;

				while ( x )
				{
					y = x;
					if ( KeyFirst()(x->content) > KeyFirst()(node->content) )
						x = x->left;
					else
						x = x->right;
				}

				node->parent = y;

				if ( !y )
					this->_root = node;
				else
				{
					if ( KeyFirst()(y->content) > KeyFirst()(node->content) )
						y->left = node;
					else
						y->right = node;
				}
			}

			void	_deleteNode( link_type& node )
			{
				link_type	y;
				link_type	x;

				if ( !(node->left) || !(node->right) )
					y = node;
				else
					y = _next( node );

				if ( y->left )
					x = y->left;
				else
					x = y->right;

				if ( x )
					x->parent = y->parent;

				if ( y->parent )
				{
					if ( y->parent->left == y )
						y->parent->left = x;
					else
						y->parent->right = x;
				}
				else
					this->_root = x;

				if ( y != node )
					node->content = y->content;

				_destroyNode( y );
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

template< typename T >
void	display_tree_content(std::string prefix, ft::Node<T>* node, int is_left)
{
	const std::string	e_type = "NODE";
	const std::string	e_colors[2] = {"\x1b[32m", "\x1b[33m"};

	if (is_left)
		std::cout << prefix << "├──";
	else
		std::cout << prefix << "└──";
	if (!node)
		std::cout << "\x1b[31mNULL\x1b[0m\n";
	else
	{
		std::cout << e_colors[node->color] << e_type;
		std::cout << " ( key : " << node->content.first;
		std::cout << ")\x1b[0m\n";
//		std::cout <<", content : " << node->content.second << ")\x1b[0m\n";
	}
}

template< typename T >
void	print_tree(std::string prefix, ft::Node<T> *node, int is_left)
{

	std::string	new_prefix;

	if (node)
	{
		display_tree_content(prefix, node, is_left);
		if (is_left)
		{
			new_prefix = prefix + "│   ";
			print_tree(new_prefix, node->left, 1);
			print_tree(new_prefix, node->right, 0);
//			if (!node->right && !node->vol)
//				display_tree_content(new_prefix, node->right, 0);
		}
		else
		{
			new_prefix = prefix + "    ";
			print_tree(new_prefix, node->left, 1);
			print_tree(new_prefix, node->right, 0);
//			if (!node->right && !node->vol)
//				display_tree_content(new_prefix, node->right, 0);
		}
	}
}

#endif
