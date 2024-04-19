#ifndef FILLER_INTERFACE_H
#define FILLER_INTERFACE_H
#include "board.interface.h"
#include "token.inteface.h"

typedef struct s_filler {
  char character;
  int (*play)(t_filler, t_board, t_token);
} t_filler;

#endif