#include "heart.h"

int
main (int argc, char *argv[])
{
  t_context context = { 0 };

  handle_options (&context, argc, argv);

  garbage_collector (&context);
  return (0);
}
