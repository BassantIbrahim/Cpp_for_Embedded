#include <iostream>
#include <sstream>
#include <regex>

using namespace std;

#define Music   0
#define Image   1
#define Movie   2
#define Other   3



int DSize(string s);
int DExtension(string s);

int main(void)
{
    int N_Conditions = 0;
    int * N_Cases = NULL;
    string Input_Line = "";
    int Size = 0;
    int Extension = Other;
    int Result[4]={0};
    cin>>N_Conditions;
    N_Cases = new int[N_Conditions]{0};
    for(int i = 0 ; i < N_Conditions ; i++)
    {
        cin>>N_Cases[i];
    }

    for(int i = 0 ; i < N_Conditions ; i++)
    {

        memset(Result,0,sizeof(Result));   
        for(int j = 0; j <N_Cases[i] ; j++)
        {
           
            getline(cin>>ws,Input_Line);
            Size = DSize(Input_Line);
            Extension = DExtension(Input_Line);
            Result[Extension]+=Size;
        }
        cout<<"music "<<Result[Music]<<"b images "<<Result[Image]<<"b movies "<<Result[Movie]<<"b other "<<Result[Other]<<"b"<<endl;
    }

    return 0;
}

int DExtension(string s)
{
    int Extension = Other;
    if(regex_match(s,regex(".*(flac|mp3|aac)\\s\\d+b")))
    {
        Extension = Music;
    }
    else if(regex_match(s,regex(".*(jpg|bmp|gif)\\s\\d+b")))
    {
        Extension = Image;
    }
    else if(regex_match(s,regex(".*(mp4|avi|mkv)\\s\\d+b")))
    {
        Extension = Movie;
    }

    return Extension;

}



int DSize(string s)
{
    string x = "";
    int Size = 0;
    stringstream line(s); 
    while(line>>x);
    Size = stoi(x); 
    return Size; 
}


