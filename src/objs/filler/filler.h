#ifndef FILLER_H
#define FILLER_H

typedef struct s_filler {
  char character;
  int (*play)(t_filler, t_board, t_token);
} t_filler;

t_filler *new_filler(void);
void delete_filler(t_filler *obj);

#endif