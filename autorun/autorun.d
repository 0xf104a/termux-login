import std.stdio;
import std.file;
import std.array;



string[string] config;

class BadConfigException : Exception {
    this(string msg, string file = __FILE__, size_t line = __LINE__) {
        super(msg, file, line);
    }
}

string[string] readconf(string fname){
	File f=File(fname,"r");
        string[string] config;
	while(!f.eof()){
		string line=f.readln();
		//writeln("line=",line);
		if(line.length<2||line[0]=="#"){
			continue;
		}
		config[line.split("=")[0]]=line.split("=")[1];
	}
	f.close();
	return config;
}

string[] readlist(string fname){
	File f=File(fname,"r");
	string[] list;
	while(!f.eof()){
		string line=f.readln();
		list[list.length-1]=line;
	}
	return list;
}


void main(string args[]){
	//writeln("Hello,world\n");
	config=readconf("test.cfg");
	
}
