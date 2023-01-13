/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:10:27 by amahla            #+#    #+#             */
/*   Updated: 2023/01/13 21:41:20 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

# include "rb_tree.hpp"

namespace ft {



	template< class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator< ft::pair<const Key, T> > >
	class map {

		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef pair<const Key, T>					value_type;
			typedef Compare								key_compare;
			typedef Allocator							allocator_type;
	
			class value_compare
				: public std::binary_function< value_type, value_type, bool >
			{
	
				friend class map;
	
				protected:
	
					Compare	comp;
	
					value_compare( Compare c ) : comp(c) { }
	
				public:
	
					bool	operator()( const value_type& x, const value_type& y ) const
					{
						return comp( x.first, y.first );
					}
			};

		private:

			typedef rb_tree< key_type, value_type, std::_Select1st<value_type>,
				key_compare, allocator_type >	btree;

			btree	_tree;

		public:

			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef typename btree::size_type				size_type;
			typedef typename btree::difference_type			difference_type;
			typedef typename btree::iterator				iterator;
			typedef typename btree::const_iterator			const_iterator;
			typedef typename btree::reverse_iterator		reverse_iterator;
			typedef typename btree::const_reverse_iterator	const_reverse_iterator;

			// ===== CONSTRUCT/COPY/DESTROY =====

			/* @member map()
			 *
			 * @brief construct by default
			 *
			 * @return NO*/

			inline explicit	map( const Compare& comp = Compare(),
				const Allocator& = Allocator() ) : _tree( comp )
			{ }

			/* @member map()
			 *
			 * @brief construct by copy
			 *
			 * @return NO*/

			inline	map( const map<Key, T, Compare, Allocator>&	x ) : _tree( x._tree )
			{ }

			/* @member map()
			 *
			 * @brief construct with a range of iterators
			 *
			 * @return NO*/

			template <class InputIterator>
			inline	map(InputIterator first,
				typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type last,
				const Compare& = Compare(), const Allocator& = Allocator()) : _tree(first, last)
				{ }

			/* @member ~map()
			 *
			 * @brief destruct by default
			 *
			 * @return NO*/

			inline	~map( void )
			{ }

			/* @member operator=()
			 *
			 * @brief map assignment operator
			 *
			 * @return NO*/

			inline	map<Key,T,Compare,Allocator>&
				operator=( const map<Key, T, Compare, Allocator>& rhs )
			{
				if ( this != &rhs )
					this->_tree = rhs._tree;
				return *this;
			}

			/* @member get_allocator()
			 *
			 * @brief return allocator used
			 *
			 * @return allocator_type*/

			allocator_type get_allocator() const
			{
				return this->_tree.get_allocator();
			}

			// ===== ITERATORS =====

			/* @member begin() / end() / rbegin() / rend()
			 *
			 * @return iterator*/

			inline iterator					begin( void )
			{
				return this->_tree.begin();
			}

			inline const_iterator			begin( void ) const
			{
				return this->_tree.begin();
			}

			inline iterator					end( void )
			{
				return this->_tree.end();
			}

			inline const_iterator			end( void ) const
			{
				return this->_tree.end();
			}

			inline reverse_iterator			rbegin( void )
			{
				return this->_tree.rbegin();
			}

			inline const_reverse_iterator	rbegin( void ) const
			{
				return this->_tree.rbegin();
			}

			inline reverse_iterator			rend( void )
			{
				return this->_tree.rend();
			}

			inline const_reverse_iterator	rend( void ) const
			{
				return this->_tree.rend();
			}

			// ===== CAPACITY =====

			/* @member size()
			 *
			 * @brief the size of current instance is return
			 *
			 * @return size_type*/

			inline size_type	size( void ) const
			{
				return this->_tree.getSize();
			}

			/* @brief the max_size can be stored in this instance
			 *
			 * @return size_type*/

			inline size_type	max_size( void ) const
			{
				return this->_tree.max_size();
			}

			/* @member empty()
			 *
			 * @brief boolean statement about size()==0 of current instance
			 *
			 * @return size_type*/

			inline bool	empty( void ) const
			{
				return this->_tree.empty();
			}

			// ===== ELEMENT ACCESS =====

			/* @member operator[]()
			 *
			 * @brief access operator read/write
			 *
			 * @return T&*/

			inline T&	operator[]( const Key& key )
			{
				return insert(ft::make_pair(key, T())).first->second;
			}

			/* @member at()
			 *
			 * @brief access operator read/write
			 *
			 * @return T&*/

			inline T&	at( const Key& key )
			{
				iterator	tmp = this->_tree.find(key);
				if ( tmp == end() )
					throw std::out_of_range("map::at");
				return	tmp->second;
			}

			inline const T&	at( const Key& key ) const
			{
				const_iterator	tmp = this->_tree.find(key);
				if ( tmp == end() )
					throw std::out_of_range("map::at");
				return	tmp->second;
			}

			// ===== MODIFIERS =====

			/* @member insert()
			 *
			 * @brief catch an iterator to content
			 * a find (false) or create (true) element 
			 * and return a pair of both (read/write)
			 *
			 * @return reference*/

			inline ft::pair<iterator, bool>	insert( const value_type& x)
			{
				return this->_tree.insert(x);
			}

			/* @member insert()
			 *
			 * @brief iterator to  read/write
			 *
			 * @return ft::pair<iterator, bool>*/

			inline iterator insert( iterator position, const value_type& x )
			{
				(void)position;
				return this->_tree.insert(x).first;
			}

			/* @member insert()
			 *
			 * @brief insert range of iterator before the position
			 *
			 * @return iterator*/

			template <class InputIterator>
			inline void insert(InputIterator first,
				typename enable_if< !is_integral<InputIterator>::value, InputIterator>::type last)
			{
				this->_tree.insert(first, last);
			}

			/* @member erase()
			 *
			 * @brief erase an elem (iterator) from current instance
			 *
			 * @return void*/

			inline void	erase( iterator position )
			{
				this->_tree.deleteNode(position);
			}

			/* @member erase()
			 *
			 * @brief erase an elem (iterator) from current instance
			 *
			 * @return size_type ( 0 if not deleted / 1 if deleted)*/

			inline size_type	erase( const key_type& x )
			{
				return this->_tree.deleteNode(x);
			}

			/* @member erase()
			 *
			 * @brief erase a range of iterator from current instance
			 *
			 * @return void*/

			inline void	erase( iterator first, iterator last )
			{
				while ( first != last )
					erase(first++);
			}

			/* @member swap()
			 *
			 * @brief swap 2 map
			 *
			 * @return void*/

			inline void	swap( map<Key, T, Compare, Allocator>& other )
			{
				this->_tree.swap(other._tree);
			}

			/* @member clear()
			 *
			 * @brief clear all elem in map
			 *
			 * @return void*/

			inline void clear( void )
			{
				this->_tree.deleteTree();
			}

			// ===== OBSERVERS =====

			/* @member key_comp()
			 *
			 * @brief return the compare fonction from map constructor
			 *
			 * @return key_compare*/

			inline key_compare	key_comp( void ) const
			{
				return this->_tree.key_comp();
			}

			/* @member value_comp()
			 *
			 * @brief return fonction that compare key from map pair
			 *
			 * @return value_compare*/

			inline value_compare value_comp( void ) const
			{
				return value_compare(this->_tree.key_comp());
			}

			// ===== MAP OPERATIONS =====

			/* @member find()
			 *
			 * @brief return the elem sought or end() if not
			 *
			 * @return iterator*/

			inline iterator	find( const key_type& x )
			{
				return this->_tree.find(x);
			}

			inline const_iterator	find( const key_type& x ) const
			{
				return this->_tree.find(x);
			}

			/* @member count()
			 *
			 * @brief the number of elements with key that compares
			 * equivalent to the specified argument
			 *
			 * @return size_type*/

			inline size_type	count( const key_type& x ) const
			{
				return this->_tree.findCheck(x);
			}

			/* @member lower_bound()
			 *
			 * @brief Returns an iterator pointing to the first element
			 * that is not less than (i.e. greater or equal to) key.
			 *
			 * @return iterator*/

			inline iterator lower_bound( const key_type& x )
			{
				return this->_tree.lower_bound(x);
			}

			inline const_iterator lower_bound( const key_type& x ) const
			{
				return this->_tree.lower_bound(x);
			}

			/* @member upper_bound()
			 *
			 * @brief Returns an iterator pointing to the first element
			 * that is greater than key.
			 *
			 * @return iterator*/

			inline iterator upper_bound( const key_type& x )
			{
				return this->_tree.upper_bound(x);
			}

			inline const_iterator upper_bound( const key_type& x ) const
			{
				return this->_tree.upper_bound(x);
			}

			/* @member equal_range()
			 *
			 * @brief Returns a range containing all elements with
			 * the given key in the container.
			 * The range is defined by two iterators,
			 * one pointing to the first element that is not less than
			 * key and another pointing to the first element
			 * greater than key. 
			 *
			 * @return pair<iterator, iterator>*/

			inline ft::pair<iterator,iterator>	equal_range( const key_type& x )
			{
				return ft::make_pair<iterator, iterator>(
					lower_bound(x), upper_bound(x)
				);
			}

			inline ft::pair<const_iterator,const_iterator>
				equal_range( const key_type& x ) const
			{
				return ft::make_pair<const_iterator, const_iterator>(
					lower_bound(x), upper_bound(x)
				);
			}

			#if VIEWER

				void	print( void )
				{
					this->_tree.print();
				}

			#endif

	};

	template <class Key, class T, class Compare, class Allocator>
	inline bool	operator==( const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y )
	{
		return x.size() == y.size()
				&& ft::equal(x.begin(), x.end(), y.begin());
	}

	template <class Key, class T, class Compare, class Allocator>
	inline bool	operator<( const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y )
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class Key, class T, class Compare, class Allocator>
	inline bool	operator!=( const map<Key, T, Compare, Allocator>& x,
		const map<Key, T, Compare, Allocator>& y )
	{
		return !(x == y);
	}

	template <class Key, class T, class Compare, class Allocator>
	inline bool	operator>( const map<Key, T, Compare, Allocator>& x,
		const map<Key, T, Compare, Allocator>& y )
	{
		return y < x;
	}

	template <class Key, class T, class Compare, class Allocator>
	inline bool	operator>=( const map<Key, T, Compare, Allocator>& x,
	const map<Key, T, Compare, Allocator>& y )
	{
		return !(x < y);
	}

	template <class Key, class T, class Compare, class Allocator>
	inline bool	operator<=( const map<Key, T, Compare, Allocator>& x,
		const map<Key, T, Compare, Allocator>& y )
	{
		return !(y < x);
	}

	template <class Key, class T, class Compare, class Allocator>
	inline void	swap(map<Key, T, Compare, Allocator>& x,
		map<Key, T, Compare, Allocator>& y)
	{
		x.swap(y);
	}


}

#endif
