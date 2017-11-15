#include <stdio.h>
#include <string>
//#include <boost/program_options/cmdline.hpp>
#include <fstream>

#include "crypto/sha512/sha512.h"
#include "getpass.h"
#include "cutil/util.h"
#include "checkuser.h"

void adduser(std::string name,std::string password){
	std::fstream shadow;
	shadow.open("/data/data/com.termux/files/usr/etc/shadow",std::fstream::in | std::fstream::out | std::ios_base::app);
	shadow<<name+":"+sha512(name+password)<<"\n";
}

int main(int argc,char *  argv[]){
	bool nopass=0;
	std::string password;
	if(argc<2||strncmp2(argv[1],"-h",2)){
			printf("Usage:%s [-hn] USER1 USER2 USER3...\n",argv[0]);
			return 0;
	}
	if(strncmp2(argv[1],"-n",2)){
		nopass=1;
	}
	for(int i=1;i<argc-nopass;i++){
		if(checkuser(argv[i+nopass],"/data/data/com.termux/files/usr/etc/shadow")){
				fprintf(stderr,"%s:User already exists\n",argv[i+nopass]);
				continue;
		}
		if(nopass){
			adduser(argv[i+1],"");
			printf("Created user:%s\n",argv[i+1]);
		}else{

			printf("Password for %s:",argv[i]);
			password=getpass("");
			adduser(argv[i],password);
			printf("Created user:%s\n",argv[i]);
		}
	}
	return 0;
}
	

