// QuadTree.hpp

#ifndef __QUADTREE_HPP__
#define __QUADTREE_HPP__

#include <SDL2\SDL.h>

#include <map>
#include <vector>

#include "Object.hpp"
#include "Rectangle.hpp"

class QuadTree
{
	private:
		static const int c_MaximumItemsPerNode = 3;

		enum QuadIndex
		{
			TopLeft,
			TopRight,
			BottomLeft,
			BottomRight,
		};

	public:
		QuadTree(const Rectangle& p_Bounds);
		QuadTree(float p_Top, float p_Bottom, float p_Left, float p_Right);
		~QuadTree();

		bool Insert(Rectangle* p_Bounds, Object* p_Item);
		int Query(const Rectangle& p_Bounds, std::vector<Object*>& p_ReturnItems);
		void Clear();
		void Render(SDL_Renderer* p_Renderer);

	private:
		void Split();

		QuadTree* m_Parent;
		QuadTree* m_Children[4];
		Rectangle m_Bounds;
		bool m_IsLeaf;
		std::vector<Object*> m_Items;
		int m_ItemCount;
		std::map<Object*, Rectangle*> m_ItemToBoundsLookup;
};

#endif
