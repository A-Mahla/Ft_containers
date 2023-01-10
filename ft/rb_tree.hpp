/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:29:41 by amahla            #+#    #+#             */
/*   Updated: 2023/01/10 14:29:27 by amahla           ###   ########.fr       */
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

		Node( const T& x ) : color(red), parent(NULL), left(NULL),
			right(NULL), content(x)
		{
		}

		Node&	operator=( const T& rhs )
		{
			if ( this != &rhs )
			{
				this->color = rhs.color;
				this->parent = rhs.parent;
				this->left = rhs.left;
				this->right = rhs.right;
				this->content = rhs.content;
			}
			return *this;
		}

	};

	template< typename T >
	class	rb_iterator
	{

		public:

			typedef T								value_type;
			typedef T&							 	reference;
			typedef T*								pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef typename Node<T>::base_pointer	link_type;

		private:

			pointer	it;

			operator rb_iterator< const T >( void ) const
			{
				return rb_iterator< const T >(this->it);
			}

		public:

			rb_iterator( void ) : it(NULL) { }

			rb_iterator( pointer rhs ) : it(rhs) { }

			rb_iterator( const rb_iterator & rhs ) : it(rhs.it) { }

			~rb_iterator() {}


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

			inline link_type	_initNil( void )
			{
				link_type init = this->_alloc.allocate(1);
				init->color = black;
				init->parent = NULL;
				init->left = NULL;
				init->right = NULL;
				return init;
			}

			inline link_type	_create_node( const value_type x )
			{
				link_type	node = this->_alloc.allocate(1);
				this->_alloc.construct(node, x);
				node->parent = _nil;
				node->left = _nil;
				node->right = _nil;
				return	node;
			}

			inline void	_destroyNode( link_type node )
			{
				this->_alloc.destroy( node );
				this->_alloc.deallocate( node, 1 );
			}

			inline void	_deleteTree( link_type& root )
			{
				if ( root == this->_nil )
					return ;
				if ( root->left != this->_nil )
					_deleteTree( root->left );
				if ( root->right != this->_nil )
					_deleteTree( root->right );
				_destroyNode( root );
			}

			link_type	_maxTree( link_type x )
			{
				if ( x == this->_nil )
					return this->_nil;
				while ( x->right != this->_nil )
					x = x->right;
				return x;
			}

			link_type	_maxTree( link_type x ) const
			{
				if ( x == this->_nil )
					return this->_nil;
				while ( x->right != this->_nil )
					x = x->right;
				return x;
			}

			link_type	_minTree( link_type x )
			{
				if ( x == this->_nil )
					return this->_nil;
				while ( x->left != this->_nil )
					x = x->left;
				return x;
			}

			link_type	_minTree( link_type x ) const
			{
				if ( x == this->_nil )
					return this->_nil;
				while ( x->left != this->_nil )
					x = x->left;
				return x;
			}

			link_type	_next( link_type node )
			{
				if ( node == this->_nil )
					return this->_nil;
				if ( node->right != this->_nil )
					return _minTree(node->right);
				while ( node->parent != this->_nil && node->parent->right == node )
					node = node->parent;
				return node->parent;
			}

			link_type	_next( link_type node ) const
			{
				if ( node == this->_nil )
					return this->_nil;
				if ( node->right != this->_nil )
					return _minTree(node->right);
				while ( node->parent != this->_nil && node->parent->right == node )
					node = node->parent;
				return node->parent;
			}

			link_type	_prev( link_type node )
			{
				if ( node == this->_nil )
					return this->_nil;
				if ( node->left != this->_nil )
					return _maxTree(node->left);
				while ( node->parent != this->_nil && node->parent->left == node )
					node = node->parent;
				return node->parent;
			}

			link_type	_prev( link_type node ) const
			{
				if ( node == this->_nil )
					return this->_nil;
				if ( node->left != this->_nil )
					return _maxTree(node->left);
				while ( node->parent != this->_nil && node->parent->left == node )
					node = node->parent;
				return node->parent;
			}

			void	_rotateLeft( link_type node )
			{
				link_type	x = node->right;

				if ( x == this->_nil )
					return ;

				node->right = x->left;
				if ( x->left != this->_nil )
					x->left->parent = node;
				x->parent = node->parent;
				if ( node->parent != this->_nil )
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

			void	_rotateRight( link_type node )
			{
				link_type	x = node->left;

				if ( x == this->_nil )
					return;

				node->left = x->right;
				if ( x->right != this->_nil )
					x->right->parent = node;
				x->parent = node->parent;
				if ( node->parent != this->_nil )
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

			link_type	_find( key_type k )
			{
				link_type	x = this->_root;

				while ( x != this->_nil && KeyFirst()(x->content) != k )
				{
					if ( KeyFirst()(x->content) > k )
						x = x->left;
					else
						x = x->right;
				}
				return x;
			}

			link_type	_find( key_type k ) const
			{
				link_type	x = this->_root;

				while ( x != this->_nil && KeyFirst()(x->content) != k )
				{
					if ( KeyFirst()(x->content) > k )
						x = x->left;
					else
						x = x->right;
				}
				return x;
			}

			void	_insertNode( link_type node )
			{
				link_type	y = this->_nil;
				link_type	x = this->_root;

				while ( x != this->_nil )
				{
					y = x;
					if ( KeyFirst()(x->content) > KeyFirst()(node->content) )
						x = x->left;
					else
						x = x->right;
				}

				node->parent = y;

				if ( y == this->_nil )
					this->_root = node;
				else
				{
					if ( KeyFirst()(y->content) > KeyFirst()(node->content) )
						y->left = node;
					else
						y->right = node;
				}
				this->_sizeTree++;
				_insertCorrect(node);
			}

			void	_insertCorrectLeft( link_type& node )
			{
				link_type y = node->parent->parent->right;
				if ( y->color == red )
				{
					node->parent->parent->color = red;
					node->parent->color = black;
					y->color = black;
					node = node->parent->parent;
				}
				else
				{
					if ( node == node->parent->right )
					{
						node = node->parent;
						_rotateLeft( node );
					}
					node->parent->color = black;
					node->parent->parent->color = red;
					_rotateRight( node->parent->parent );
				}
			}

			void	_insertCorrectRight( link_type& node )
			{
				link_type	y = node->parent->parent->left;
				if ( y->color == red )
				{
					node->parent->parent->color = red;
					node->parent->color = black;
					y->color = black;
					node = node->parent->parent;
				}
				else
				{
					if ( node == node->parent->left )
					{
						node = node->parent;
						_rotateRight( node );
					}
					node->parent->color = black;
					node->parent->parent->color = red;
					_rotateLeft( node->parent->parent );
				}
			}

			void	_insertCorrect( link_type node )
			{
				while ( node->parent->color == red )
				{
					if ( node->parent->parent->left == node->parent  )
						_insertCorrectLeft( node );
					else
						_insertCorrectRight( node );
				}
				this->_root->color = black;
			}

			void	_deleteCorrectLeft( link_type& x )
			{
				link_type	w = x->parent->right;
				if ( w->color == red )
				{
					w->color = black;
					x->parent->color = red;
					_rotateLeft( x->parent );
					w = x->parent->right;
				}
				if ( w->right->color == black && w->left->color == black )
				{
					w->color = red;
					x = x->parent;
				}
				else
				{
					if ( w->right->color == black )
					{
						w->color = red;
						w->left->color = black;
						_rotateRight( w );
						w = x->parent->right;
					}
					w->color = w->parent->color;
					w->right->color = black;
					w->parent->color = black;
					_rotateLeft( w->parent );
					x = this->_root;
				}

			}

			void	_deleteCorrectRight( link_type& x )
			{
				link_type	w = x->parent->left;
				if ( w->color == red )
				{
					w->color = black;
					x->parent->color = red;
					_rotateRight( x->parent );
					w = x->parent->left;
				}
				if ( w->right->color == black && w->left->color == black )
				{
					w->color = red;
					x = x->parent;
				}
				else
				{
					if ( w->left->color == black )
					{
						w->color = red;
						w->right->color = black;
						_rotateLeft( w );
						w = x->parent->left;
					}
					w->color = w->parent->color;
					w->left->color = black;
					w->parent->color = black;
					_rotateRight( x->parent );
					x = this->_root;
				}

			}

			void	_deleteCorrect( link_type x )
			{
				while ( x->parent != this->_nil && x->color == black )
				{
					if ( x == x->parent->left )
						_deleteCorrectLeft( x );
					else
						_deleteCorrectRight( x );
				}
				x->color = black;
			}

			void	_deleteNode( key_type k )
			{
				link_type	node = _find(k);
				link_type	y;
				link_type	x;

				if ( node == this->_nil )
					return ;

				if ( node->left == this->_nil || node->right == this->_nil )
					y = node;
				else
					y = _next( node );

				if ( y->left != this->_nil )
					x = y->left;
				else
					x = y->right;

				x->parent = y->parent;

				if ( y->parent != this->_nil )
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

				if ( y->color == black )
					_deleteCorrect(x);

				if ( x == this->_nil )
					x->parent = NULL;
				this->_sizeTree--;
				_destroyNode(y);
			}

		public:

			rb_tree( const Compare& comp = Compare(),
					const Allocator& alloc = Allocator() )
				: _comp(comp), _alloc(alloc), _nil(_initNil()), _root(_nil),
				_sizeTree(0)
		{ }

			rb_tree( const rb_tree<Key, T, KeyFirst, Compare, Allocator>&	x );

			~rb_tree( void )
			{
				_deleteTree( this->_root );
				this->_alloc.deallocate( this->_nil, 1 );
			}

	};

}

	template< typename T >
void	display_tree_content(std::string prefix, ft::Node<T>* node, int is_left)
{
	const std::string	e_type = "NODE";
	const std::string	e_colors[2] = {"\x1b[33m", "\x1b[32m"};

	if (is_left == 2)
		std::cout << " ──";
	if (is_left == 1)
		std::cout << prefix << "├──";
	else if (is_left == 0 )
		std::cout << prefix << "└──";
	if ( node->parent != NULL && node->left != NULL && node->right != NULL )
	{

		std::cout << e_colors[node->color] << e_type;
		std::cout << " ( key : " << node->content.first;
		std::cout << " )\x1b[0m\n";
		//		std::cout <<", content : " << node->content.second << ")\x1b[0m\n";
	}
	else if ( node->parent == NULL && node->left == NULL && node->right == NULL )
		std::cout << "\x1b[31mNULL\x1b[0m\n";
}

	template< typename T >
void	print_tree(std::string prefix, ft::Node<T> *node, int is_left)
{

	std::string	new_prefix;

	if ( node->parent != NULL && node->left != NULL && node->right != NULL )
		//	if ( node )
	{
		display_tree_content(prefix, node, is_left);
		if ( is_left == 2 )
			is_left = 0;
		if (!is_left)
		{
			new_prefix = prefix + "    ";
			print_tree(new_prefix, node->right, 1);
			print_tree(new_prefix, node->left, 0);
		}
		else
		{
			new_prefix = prefix + "│   ";
			print_tree(new_prefix, node->right, 1);
			print_tree(new_prefix, node->left, 0);
		}
	}
}

#endif
