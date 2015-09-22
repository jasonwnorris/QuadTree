// main.cpp

#include <SDL2\SDL.h>

#include <iostream>
#include <time.h>

#include "QuadTree.hpp"

int main(int argc, char** argv)
{
	srand(static_cast<unsigned int>(time(nullptr)));

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("QuadTree", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WindowFlags::SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);

	const float qtWidth = 800.0f;
	const float qtHeight = 600.0f;
	const float qtRange = 25.0f;
	const int count = 50;
	Object objs[count];
	Rectangle rects[count];
	
	for (int i = 0; i < count; ++i)
	{
		int value = rand() % 100;
		float left = (rand() % 1000) / 1000.0f * (qtWidth - qtRange);
		float top = (rand() % 1000) / 1000.0f * (qtHeight - qtRange);
		float width = (rand() % 1000) / 1000.0f * (qtWidth - left);
		float height = (rand() % 1000) / 1000.0f * (qtHeight - top);

		objs[i] = Object(value);
		rects[i] = Rectangle(left, top, left + width, top + height);
	}

	QuadTree quadtree(Rectangle(0.0f, qtHeight, 0.0f, qtWidth));
	for (int i = 0; i < count; ++i)
	{
		if (!quadtree.Insert(&rects[i], &objs[i]))
		{
			std::cout << "Rectangle[" << i << "] was too large to fit into the QuadTree." << std::endl;
		}
	}

	bool isRunning = true;
	while (isRunning)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
				case SDL_QUIT:
					isRunning = false;
					break;
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							isRunning = true;
							break;
						default:
							break;
					}
					break;
				case SDL_KEYUP:
					switch (e.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							isRunning = true;
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		quadtree.Render(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}