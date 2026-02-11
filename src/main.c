#include <stdio.h>

#include <SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

int main(void)
{
  if (SDL_Init(0) < 0)
  {
    goto error;
  }
  
  SDL_Window *win = SDL_CreateWindow("My App", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 480, 0);
  if (win == NULL)
  {
    goto error;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL)
  {
    goto error;
  }
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0x00);


  int running = 1;
  while (running)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
	running = 0;
	break;
      }
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  return 0;

  error:
       return printf("SDL error: %s\n", SDL_GetError()) >= 0 ? 0 : -1;
}
