#ifndef GETPASSW_H
#define GETPASSW_H

#include <string>

std::string get_password(const char *prompt, bool show_asterisk=true,char mask='*');
std::string get_string();
#endif
