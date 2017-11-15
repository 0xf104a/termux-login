#include <fstream>
#include <string>
#include <iostream>


bool checkuser(std::string uname,std::string fname){
	std::ifstream file(fname);
	std::string cur;
	while(std::getline(file,cur)){
//		std::cout<<cur<<std::endl;
		std::string cname=cur.substr(0,cur.find(":"));
		if(cname==uname){
			return true;
		}
	}
	
	return false;
}

std::string getuserhash(std::string uname,std::string fname){
	std::ifstream file(fname);
	std::string cur;
	std::string cname;
	while(std::getline(file,cur)){
		cname=cur.substr(0,cur.find(":"));
		if(cname==uname){
			return cur.substr(cur.find(":")+1,cur.size());
		}
	}
	return "NULL";
}
