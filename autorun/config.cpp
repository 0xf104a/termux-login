#include <iostream>
#include <string>
#include <map>

std::map<std::string,std::string> read_config(std:string fname){
	std::string line;
	std::ifstream cfg(fname);
	if(cfg.is_open()){
	   while(getline(cfg,line)){
		
	   }
	}
