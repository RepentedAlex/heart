#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <getopt.h>

#include "heart.h"

// Options for the program:
// -a : Assets
// -h : Help
// -r : Resolution
// -v : Verbose
// -V : Version

bool verbose = false;

static int
parse_resolution (const char *res_str, t_context *context)
{
  int height = 0;
  int width = 0;
  char *runner = (char *)res_str;

  if (res_str == NULL)
    {
      return (-1);
    }

  runner = (char *)res_str;
  int i = 0;
  char tmp[8] = { 0 };
  while (runner[i] && runner[i] != 'x')
    {
      tmp[i] = runner[i];
      i++;
    }
  tmp[i] = '\0';
  width = atoi (tmp);
  if (width <= 0)
    {
      return (-1);
    }

  i++;
  runner = (char *)&res_str[i];

  i = 0;
  while (runner[i] && runner[i] != 'x')
    {
      tmp[i] = runner[i];
      i++;
    }
  tmp[i] = '\0';
  height = atoi (tmp);
  if (height <= 0)
    {
      return (-1);
    }

  context->width = width;
  context->height = height;
  return (0);
}

static void
assets_option (t_context *context, char *arg)
{
  if (access (arg, R_OK) == -1)
    {
      const char *tmp = ": File can not be opened.\n";
      char *err_msg
          = malloc (sizeof (char) * (strlen (arg) + strlen (tmp) + 1));
      if (err_msg == NULL)
        {
          malloc_error ();
          garbage_collector (context);
          exit (EXIT_FAILURE);
        }
      strcpy (err_msg, arg);
      strcat (err_msg, tmp);
      write (STDERR_FILENO, err_msg, strlen (err_msg));
      free (err_msg);
    }
  context->assets_path = strdup (arg);
}

static void
help_option (void)
{
  const char *helper_string
      = "Usage: heart [OPTION]...\nA visual novel about love.\n\n"
        "\t-a, --assets\t\tpath to the game assets\n"
        "\t-h, --help\t\tdisplay this help and exit\n"
        "\t-r, --resolution\tspecify a resolution for the game window\n"
        "\t-v, --verbose\t\ttoggle logs displaying\n"
        "\t-V, --version\t\toutput version information and exit\n\n";

  write (STDOUT_FILENO, helper_string, strlen (helper_string));
  exit (EXIT_SUCCESS);
}

static void
resolution_option (t_context *context, const char *arg)
{
  parse_resolution (arg, context);
}

static void
version_option (void)
{
  const char *version_string = "heart version " MAJOR_VERSION "." MINOR_VERSION
                               "." PATCH_VERSION "\n";
  const char *apropos = "Made with <3^2 by " AUTHOR "\n";

  write (STDOUT_FILENO, version_string, strlen (version_string));
  write (STDOUT_FILENO, "\n", 2);
  write (STDOUT_FILENO, apropos, strlen (apropos));
  exit (EXIT_SUCCESS);
}

void
handle_options (t_context *context, int argc, char *argv[])
{
  const char *shortopts = "a:hr:vV";
  const struct option longopts[] = { { "assets", 1, NULL, 'a' },
                                     { "help", 0, NULL, 'h' },
                                     { "resolution", 1, NULL, 'r' },
                                     { "verbose", 0, NULL, 'v' },
                                     { "version", 0, NULL, 'V' } };
  int opt;

  while ((opt = getopt_long (argc, argv, shortopts, longopts, NULL))
         && opt != -1)
    {
      switch (opt)
        {
        case 'a':
          assets_option (context, optarg);
          break;
        case 'h':
          help_option ();
          break;
        case 'r':
          resolution_option (context, optarg);
          break;
        case 'v':
          verbose = !verbose;
          break;
        case 'V':
          version_option ();
          break;
        default:
          abort ();
        }
    }
}
