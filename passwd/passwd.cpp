#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

#include "getpass.h"
#include "checkuser.h"
#include "crypto/sha512/sha512.h"
#include "cutil/util.h"

#define SHADOW "/data/data/com.termux/files/usr/etc/shadow"

void replacefline(std::string line,std::string newline,std::string path){
    std::ifstream filein(path); 
    //std::ofstream fileout(path);
    std::string strTemp;
    std::string r="";
    while(filein >> strTemp)
    {
	//printf("%s<>%s\n",strTemp.c_str(),line.c_str());
        if(strTemp == line){
	    //printf("replacing %s->%s\n",strTemp.c_str(),newline.c_str());
            strTemp = newline;
        }
        strTemp += "\n";
        r+=strTemp;
    }
    std::ofstream out(path);
    out<<r;
    //printf("result:\n%s",r.c_str());
}
int main(int argc,char *argv[]){
	if(argc<2||strncmp2(argv[1],"-h",2)){
		fprintf(stderr,"%s -[hn] USER1,USER2,USER3...\n",argv[0]);
		return 0;
	}
	bool nopass=strncmp2(argv[1],"-n",2);
	for(int i=1+nopass;i<argc;i++){
		std::string passwd,rpasswd;
		if(checkuser(argv[i],SHADOW)){
		   printf("Old password for %s:",argv[i]);
		   passwd=getpass("");
		}else{
		   printf("%s:%s:No such user\n",argv[0],argv[i]);
		   continue;
		}
		if(getuserhash(argv[i],SHADOW)!=sha512(argv[i]+passwd)){
			printf("%s:%s:Login incorrect\n",argv[0],argv[i]);
			continue;
		}
		//std::ifstream shad(SHADOW);
		//shad(SHADOW);
		printf("New password for %s:",argv[i]);
		passwd=getpass("");
		rpasswd=getpass("Repeat password:");
		if(passwd!=rpasswd){
			printf("%s:%s:Skipping user:password mismatch\n",argv[0],argv[i]);
		}
		replacefline((std::string)argv[i]+":"+getuserhash(argv[i],SHADOW),(std::string)argv[i]+":"+sha512((std::string)argv[i]+passwd),SHADOW);
	        printf("%s:%s:Password updated succesfully\n",argv[0],argv[i]);
	}
	return 0;
}
			
