#ifndef __XBINARY_TREE_H
#define __XBINARY_TREE_H

/***************************************************************************************
Xanadu Open GL Windows Game Engine
Copyright (C) 2017  William W. Westlake Jr.
wwestlake@lagdaemon.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************************/

#include "defines.h"
#include "vector"

namespace Xanadu {
	namespace Engine {

		enum XANADU_API_HEADER_ONLY NodeComparatorResult {
			LeftOf,
			EquivalentTo,
			RightOf
		};

		template <typename T>
		class XANADU_API_HEADER_ONLY NodeComparator {
		public:
			virtual NodeComparatorResult operator() (const T& current, const T& data) = 0;
		};

		template <typename T>
		class XANADU_API_HEADER_ONLY NodeSearchFunctor {
		public:
			virtual NodeComparatorResult operator() (const T& current) = 0;
		};

		template <typename T>
		class XANADU_API_HEADER_ONLY NodeFilterFunctor {
		public:
			virtual bool operator() (const T& current) = 0;
		};


		template <typename T>
		class XANADU_API_HEADER_ONLY XBinaryTree {

			template <typename Tnode> 
			class Node {
			public:
				Node(Tnode data) {
					_data = data;
				}

				void Insert(Tnode newData, NodeComparator<Tnode>* comp) {

					if (comp->operator()(_data, newData) == NodeComparatorResult::LeftOf) {
						if (_left != nullptr) {
							_left->Insert(newData, comp);
						}
						else {
							_left = new Node(newData);
						}
					}
					else {
						if (_right != nullptr) {
							_right->Insert(newData,comp);
						}
						else {
							_right = new Node(newData);
						}
					}

				}



				Node<Tnode>* RotateLeft(Node<Tnode>* node) {
					Node<Tnode>* right = node->_right;
					Node<Tnode>* rightleft = right->_left;
					right->_left = node;
					node->_right = rightleft;
					return right;
				}

				Node<Tnode>* RotateRight(Node<Tnode>* node) {
					Node<Tnode>* left = node->_left;
					Node<Tnode>* leftright = left->_right;
					left->_right = node;
					node->_left = leftright;
					return left;
				}


				Tnode Search(NodeSearchFunctor<Tnode>* functor) {
					if (functor->operator()(_data) == NodeComparatorResult::EquivalentTo) return _data;
					if (functor->operator()(_data) == NodeComparatorResult::LeftOf) {
						if (_left != nullptr) {
							return _left->Search(functor);
						}
						else { return Tnode(); }
					}
					else {
						if (_right != Tnode()) {
							return _right->Search(functor);
						}
						else { return Tnode(); }
					}
				}

				void filter(NodeFilterFunctor<Tnode>* filter, std::vector<Tnode>& accum) {
					if (filter->operator()(_data)) accum.push_back(_data);
					if (_left != nullptr) {
						_left->filter(filter, accum);
					}
					if (_right != nullptr) {
						_right->filter(filter, accum);
					}
				}

				void flatten(std::vector<Tnode>& accum) {
					if (_left != nullptr) _left->flatten(accum);
					accum.push_back(_data);
					if (_right != nullptr) _right->flatten(accum);
				}

				int height(Node* node) {
					if (node == nullptr) return 0;
					else if (node->_left == nullptr && node->_right == nullptr) return 1;
					else if (node->_left != nullptr && node->_right != nullptr) return max(height(node->_left), height(node->_right)) + 1;
					else if (node->_left != nullptr) return height(node->_left) + 1;
					else if (node->_right != nullptr) return height(node->_right) + 1;
				}

				int height() {
					return height(this);
				}

				int ballanceFactor(Node* node) {
					if (node == nullptr) return 0;
					return height(node->_right) - height(node->_left);
				}

				int ballanceFactor() {
					return ballanceFactor(this);
				}

			protected:
				Tnode _data;
				Node* _left = nullptr;
				Node* _right = nullptr;

				int max(int i, int j) { return  i > j ? i : j; }

			};


		public:

			XBinaryTree() {

			}


			void Insert(T data,NodeComparator<T>* comp) {
				if (_root == nullptr) {
					_root = new Node<T>(data);
				}
				else {
					_root->Insert(data, comp);
				}
			}

			T Search(NodeSearchFunctor<T>* functor) {
				if (_root == nullptr) return T();
				return _root->Search(functor);
			}

			void filter(NodeFilterFunctor<T>* filter, std::vector<T>& accum) {
				if (_root == nullptr) return;
				return _root->filter(filter, accum);
			}

			void flatten(std::vector<T>& accum) {
				_root->flatten(accum);
			}

			int height() {
				return _root->height();
			}

			int ballanceFactor() {
				return _root->ballanceFactor();
			}

		protected:
			Node<T>* _root = nullptr;
		};

	}
}

#endif

