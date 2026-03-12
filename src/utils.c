#include "heart.h"

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

  memset (context, 0, sizeof (t_context));
}
