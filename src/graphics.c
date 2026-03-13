#include "heart.h"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

void
init (t_context *context)
{
  if (SDL_Init (SDL_INIT_VIDEO) == false)
    {
      // TODO: ERROR
    }

  if (context->width == 0 || context->height == 0)
    {
      int count;
      SDL_DisplayID *display_id = SDL_GetDisplays (&count);
      const SDL_DisplayMode *display_mode
          = SDL_GetCurrentDisplayMode (*display_id);

      context->width = display_mode->w;
      context->height = display_mode->h;
    }

  SDL_CreateWindowAndRenderer ("heart", context->width, context->height,
                               SDL_WINDOW_FULLSCREEN | SDL_WINDOW_RESIZABLE,
                               &context->window, &context->renderer);
  if (!context->window)
    {
      // TODO: ERROR
    }
}
