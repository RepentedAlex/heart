#ifndef HEART
#define HEART

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <stdbool.h>

#include <SDL3/SDL.h>

#define MAJOR_VERSION "0"
#define MINOR_VERSION "0"
#define PATCH_VERSION "0"
#define AUTHOR "Alejo"

typedef struct s_context
{
  int width;
  int height;
  char *assets_path;

  SDL_Window *window;
  SDL_Renderer *renderer;
  bool running;
} t_context;

extern bool verbose;

void malloc_error (void);
void garbage_collector (t_context *context);
void handle_options (t_context *context, int argc, char *argv[]);

void init (t_context *context);

#endif // !HEART
