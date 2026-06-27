#include "../include/raylib.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
    if (argc > 1){
		vector<string> files;

        for (int i = 1; i < argc; i++){
            if (filesystem::exists(argv[i])) files.push_back(string{argv[i]});
        }

        for (int i = 0; i < files.size(); i++){
            cout << files[i].c_str() << "\n" << "rid: Converting image to header\n";
            Image img = LoadImage(files[i].c_str()); cout << "rid: Loaded Image " << files[i].c_str() << "\n";
            size_t lastindex = files[i].find_last_of("."); 
            string name = files[i].substr(0, lastindex) + ".hpp";
            ExportImageAsCode(img, name.c_str()); cout << "rid: Exported Image as code " << name.c_str() << "\n";
            UnloadImage(img); cout << "rid: Freed memmory from " << files[i].c_str() << "\n";
        }
    }
	else{
		cout << "rid: No input files\nUsage: rid [image file(s)]\n";
	}

    return 0;
}
