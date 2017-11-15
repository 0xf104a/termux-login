#include <cstdio>
#include <cstdlib>
#include <string>
#include <unistd.h>

#define SHADOW "/data/data/com.termux/files/usr/etc/shadow"
#include "getpass.h"
#include "checkuser.h"
#include "crypto/sha512/sha512.h"
	
int main(int argc,char **argv){
	std::string login;
	std::string pass;
	char hostname[2048];
	gethostname(hostname,2048);
        for(;;){
	  printf("%s login:",hostname);
	  login=get_str();
	  pass=getpass("Password:");
	//printf("login=%s\npassword=%s\n",login.c_str(),pass.c_str());
	  std::string hash=sha512(login+pass);
	  std::string rhash=getuserhash(login,SHADOW);
	//printf("%s!=%s\n",rhash.c_str(),hash.c_str());
	  if(rhash==hash){
	     //system("/data/data/com.termux/bin/bash");
	     return 0;
	  }else{
	     printf("Login incorrect.\n");
	  }
	}
	return 0;
}

