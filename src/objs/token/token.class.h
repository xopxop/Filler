#ifndef TOKEN_CLASS_H
#define TOKEN_CLASS_H
#include "token.interface.h"

t_token *new_token(char **raw_data);
void delete_token(t_token *obj);

#endif