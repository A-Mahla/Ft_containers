/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:10:27 by amahla            #+#    #+#             */
/*   Updated: 2023/01/11 14:05:56 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

# include "rb_tree.hpp"

namespace ft {


	template< typename T1, typename T2 >
	struct pair {

		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair( void ) : first(), second() { }

		pair( const T1& x, const T2& y ) : first(x), second(y) { }

		template< class U1, class U2 >
		pair( const pair<U1, U2>& x ) : first(x.first), second(x.second) { }

		pair	& operator=( const pair& other )
		{
			this->first = other.first;
			this->second = other.second;
			return *this;
		}

	};

	template< class T1, class T2 >
	ft::pair<T1,T2>	make_pair( T1 t, T2 u )
	{
		return ft::pair<T1, T2>(t, u);
	}

	template< class T1, class T2 >
	bool	operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template< class T1, class T2 >
	bool	operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool	operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return lhs.first < rhs.first && lhs.second < rhs.second;
	}

	template< class T1, class T2 >
	bool	operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs < rhs);
	}

	template< class T1, class T2 >
	bool	operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return rhs < lhs;
	}

	template< class T1, class T2 >
	bool	operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs < rhs);
	}


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

//		private:
		public: // TO CHANGE JUST FOR TEST

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
				const Compare& comp = Compare(), const Allocator& = Allocator());

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
			 * @return reference*/

			inline T&	operator[]( const Key& key )
			{
				return insert(ft::make_pair(key, T())).first->second;
			}

			// ===== MODIFIERS =====

			inline ft::pair<iterator, bool>	insert( const value_type& x)
			{
				return this->_tree.insert(x);
			}

	};

}

#endif
