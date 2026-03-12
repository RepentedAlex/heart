#ifndef HEART
#define HEART

#include <stdbool.h>

#define MAJOR_VERSION "0"
#define MINOR_VERSION "0"
#define PATCH_VERSION "0"
#define AUTHOR "Alejo"

typedef struct s_context
{
  int width;
  int height;
  char *assets_path;
} t_context;

extern bool verbose;

void malloc_error (void);
void garbage_collector (t_context *context);
void handle_options (t_context *context, int argc, char *argv[]);

#endif // !HEART
