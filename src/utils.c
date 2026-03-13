#include "heart.h"

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void
malloc_error (void)
{
  const char *err_msg = "Fatal error: memory allocation failed\n";
  write (STDERR_FILENO, err_msg, strlen (err_msg));
}

void
garbage_collector (t_context *context)
{
  if (context->assets_path != NULL)
    {
      free (context->assets_path);
    }
  if (context->renderer != NULL)
    {
      SDL_DestroyRenderer (context->renderer);
    }
  if (context->window != NULL)
    {
      SDL_DestroyWindow (context->window);
    }

  memset (context, 0, sizeof (t_context));
}
