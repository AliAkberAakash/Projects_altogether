#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_image.h>
#include"headers/initializing functions.h">
#include<iostream>
#include<cstdlib>
#define BSIZE 80

using namespace std;

int main(int argc, char* argv[])
{
    if(!initialize())
        cout<<"Error initializing"<<endl;
//    else
//    {
//        if(!loadMedia())
//            cout<<"Error loading media"<<endl;
//        else
//            SDL_Event event
//            bool check = true;
//
//            while(check)
//            {
//            if(!checkevents())
//                check=false;
//            }
//    }
//
//    close();

    return 0;

}
