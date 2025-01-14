#include <iostream>
#include <string>

using namespace std;

void displayUsage()
{
    cout << "Usage: convert [up|down] [any string]\n";
}

void convert(bool flag,string input)
{
    string output=input;

    for(int i=0; i<input.size(); i++) {
		if(flag==true)
            output[i] = std::toupper(input[i]);
        else
            output[i] = std::tolower(input[i]);
	}
    cout << "output: " << output << std::endl;
}

int main(int argc,char* argv[]){

    if(argc < 3){
        displayUsage();        
        return 0;
    }        

    string strInput;
    for(int i=2;i<argc;i++){
        strInput = strInput + string(argv[i]);
        if(i<(argc-1))
            strInput = strInput + " ";
    }
    
    string strCase(argv[1]);
    if(strCase.compare("up")==0){
        convert(true,strInput);
        return 0;
    }
    else if(strCase.compare("down")==0){
        convert(false,strInput);
        return 0;
    }
    else{
        displayUsage();        
        return 0;
    }
    
    return 0;
}