#include "heart.h"
#include <SDL3/SDL_events.h>

int
main (int argc, char *argv[])
{
  t_context context = { 0 };

  handle_options (&context, argc, argv);

  init (&context);

  context.running = true;
  while (context.running)
    {
      SDL_Event event;
      while (SDL_PollEvent (&event))
        {
          if (event.type == SDL_EVENT_QUIT)
            {
              context.running = false;
            }

          // Optional: Clear the screen so it's not just a transparent/black
          // box
          SDL_SetRenderDrawColor (context.renderer, 153, 102, 204,
                                  255); // Lavender
          SDL_RenderClear (context.renderer);
          SDL_RenderPresent (context.renderer);
        }
    }

  garbage_collector (&context);
  return (0);
}
