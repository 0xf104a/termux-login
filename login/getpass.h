#ifndef GETPASS_H
#define GETPASS_H

#include <string>

std::string getpass(const char *prompt, bool show_asterisk=true,char mask='*');
std::string get_str();
#endif
