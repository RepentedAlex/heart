#ifndef AST
#define AST

enum node_type
{
  NODE_DIALOGUE,
  NODE_CHOICE
};

typedef struct s_base_node
{
  enum node_type type;
  int id;
} base_node;

typedef struct s_dialogue_node
{
  base_node base;
  int sprite_id;
  char *text;
  base_node *next;
} dialogue_node;

typedef struct s_choice_node
{
  base_node *base;
  int num_choices;
  base_node **choices;
} choice_node;

#endif // !AST
