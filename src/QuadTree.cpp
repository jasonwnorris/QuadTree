// QuadTree.cpp

#include <algorithm>

#include "QuadTree.hpp"

QuadTree::QuadTree(const Rectangle& p_Bounds) :
	m_Parent(),
	m_Children(),
	m_Bounds(p_Bounds),
	m_IsLeaf(true),
	m_ItemCount(0)
{
}

QuadTree::QuadTree(float p_Top, float p_Bottom, float p_Left, float p_Right) :
	QuadTree(Rectangle(p_Top, p_Bottom, p_Left, p_Right))
{
}

QuadTree::~QuadTree()
{
	if (m_IsLeaf)
	{
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		delete m_Children[i];
	}
}

bool QuadTree::Insert(Rectangle* p_Bounds, Object* p_Item)
{
	if (!m_Bounds.Contains(p_Bounds))
	{
		return false;
	}

	if (m_ItemCount == c_MaximumItemsPerNode)
	{
		Split();
	}

	if (m_IsLeaf)
	{
		m_Items.push_back(p_Item);
		m_ItemToBoundsLookup.insert(std::make_pair(p_Item, p_Bounds));
		++m_ItemCount;
	}
	else
	{
		bool isInserted = false;

		for (int i = 0; i < 4; ++i)
		{
			if (m_Children[i]->Insert(p_Bounds, p_Item))
			{
				isInserted = true;
				break;
			}
		}

		if (!isInserted)
		{
			m_Items.push_back(p_Item);
			m_ItemToBoundsLookup.insert(std::make_pair(p_Item, p_Bounds));
			++m_ItemCount;
		}
	}

	return true;
}

int QuadTree::Query(const Rectangle& p_Bounds, std::vector<Object*>& p_ReturnItems)
{
	if (!p_Bounds.Intersects(m_Bounds))
	{
		return 0;
	}

	int count = 0;

	if (!m_IsLeaf)
	{
		for (int i = 0; i < 4; ++i)
		{
			count += m_Children[i]->Query(p_Bounds, p_ReturnItems);
		}
	}

	for (int i = 0; i < m_ItemCount; ++i)
	{
		Object* item = m_Items[i];

		if (p_Bounds.Intersects(m_ItemToBoundsLookup[item]))
		{
			p_ReturnItems.push_back(item);
			
			++count;
		}
	}

	return count;
}

void QuadTree::Clear()
{
	if (!m_IsLeaf)
	{
		for (int i = 0; i < 4; ++i)
		{
			m_Children[i]->Clear();
		}
	}

	m_Items.clear();
}

void QuadTree::Split()
{
	float top = m_Bounds.GetTop();
	float bottom = m_Bounds.GetBottom();
	float left = m_Bounds.GetLeft();
	float right = m_Bounds.GetRight();
	float halfWidth = m_Bounds.GetWidth() / 2.0f;
	float halfHeight = m_Bounds.GetHeight() / 2.0f;

	m_Children[QuadIndex::TopLeft] = new QuadTree(top, top + halfHeight, left, left + halfWidth);
	m_Children[QuadIndex::TopRight] = new QuadTree(top, top + halfHeight, left + halfWidth, right);
	m_Children[QuadIndex::BottomLeft] = new QuadTree(top + halfHeight, bottom, left, left + halfWidth);
	m_Children[QuadIndex::BottomRight] = new QuadTree(top + halfHeight, bottom, left + halfWidth, right);

	m_IsLeaf = false;

	int i = 0;
	while (i < m_ItemCount)
	{
		bool inserted = false;
		Object* item = m_Items[i];
		Rectangle* rect = m_ItemToBoundsLookup[item];

		for (int j = 0; j < 4; ++j)
		{
			if (m_Children[j]->Insert(rect, item))
			{
				m_Items.erase(std::remove(m_Items.begin(), m_Items.end(), item), m_Items.end());
				--m_ItemCount;
				inserted = true;
				break;
			}
		}

		if (!inserted)
		{
			++i;
		}
	}
}

void QuadTree::Render(SDL_Renderer* p_Renderer)
{
	SDL_SetRenderDrawColor(p_Renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

	SDL_Rect rect = {
		(int)m_Bounds.GetLeft(),
		(int)m_Bounds.GetTop(),
		(int)m_Bounds.GetWidth(),
		(int)m_Bounds.GetHeight()
	};

	SDL_RenderDrawRect(p_Renderer, &rect);

	SDL_SetRenderDrawColor(p_Renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);

	for (int i = 0; i < m_ItemCount; ++i)
	{
		Object* item = m_Items[i];
		Rectangle* rectangle = m_ItemToBoundsLookup[item];

		SDL_Rect rect = {
			(int)rectangle->GetLeft(),
			(int)rectangle->GetTop(),
			(int)rectangle->GetWidth(),
			(int)rectangle->GetHeight()
		};

		SDL_RenderDrawRect(p_Renderer, &rect);
	}

	for (int i = 0; i < 4; ++i)
	{
		if (m_Children[i] != nullptr)
		{
			m_Children[i]->Render(p_Renderer);
		}
	}
}