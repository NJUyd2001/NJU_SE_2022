#include<iostream>
#include<fstream>
#include"run_OJ.h"
using namespace std;

void run_OJ::getfiles(string path)
{    
    DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(path.c_str())))
        return;
    while((ptr = readdir(pDir))!=0) {
        string name=ptr->d_name;
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0&&name.find(".csv")==string::npos&&name.find(".txt")==string::npos&&name.find("out")==string::npos)
            files.push_back(path + "/" + ptr->d_name);
    }
    closedir(pDir);
    // for(int i=0;i<files.size();i++)
    // {
    //     cout<<files[i]<<endl;
    // }
}
void run_OJ::gen_out_file()
{
     for(int i=0;i<files.size();i++)
    {
         if(files[i].find("cpp")!=string::npos&&files[i].find("output")==string::npos)
         {
            string cur=files[i]+"_output.txt";
            ofstream output_file(cur,ios::app);
            output_file.close();
            string first_command="g++ ";
            first_command+=files[i]+" -o "+files[i].substr(0,files[i].length()-3)+"out"; 
            const char* first_char_command=first_command.data();
            system(first_char_command);
         }
    }
}
void run_OJ::gen_output_txt(string path)
{ 
    string path_input=path+"/input.txt";
    for(int i=0;i<files.size();i++)
    {   
        if(files[i].find("cpp")!=string::npos&&files[i].find("output")==string::npos)
        {   
            string cur=files[i]+"_output.txt";
            string second_command=files[i].substr(0,files[i].length()-3)+"out";
            second_command+=" <"+path_input+" >"+cur;
            const char* second_char_command=second_command.data();
            int res=system(second_char_command);
            run_results.push_back(res);
        }
    }
   
}
void run_OJ::clear_run_res()
{ 
    // for(int i=0;i<run_results.size();i++)
    // {
    //     cout<<run_results[i]<<" ";
    // }
    run_results.clear();
}