#include <iostream>
#include <string>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>

#define RETURN 10
#define BACKSPACE 127

int getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}


std::string get_str(){
	std::string s;
	unsigned char t;
	for(;;){
		t=getchar();
		if(t==BACKSPACE&&s.size()>0){
			s.resize(s.size()-1);
		}else if(t==RETURN){
			return s;
		}else{
			s+=t;
		}
	}
}

std::string getpass(const char *prompt, bool show_asterisk=true,char mask='*')
{

  std::string password;
  unsigned char ch=0;

  std::cout <<prompt;

  for(;;)
    {
       ch=getch();
       if(ch==RETURN){
	       break;
       }
       //printf("Return=%d",ch);
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 std::cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk){
                 std::cout <<mask;
	     }
         }
    }
  std::cout <<std::endl;
  //printf("\nCycle exited\n");
  return password;
}
#ifdef TEST_PASS
int main(){
	std::cout<<"testing password";
	std::string p=getpass("Password:");
	std::cout<<p<<std::endl;
	return 0;
}
#endif

