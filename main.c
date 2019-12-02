#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
int read_cmd();
int main()
{
    read_cmd();
    return 0;
}
int read_cmd(){
    char cwd[256];
    char a[50];
    char ext[] = "exit";
    do{
        SetColor(10);
        printf("Simple Bash Shell In C:\n");
        SetColor(15);
        printf("$ ");
        gets(a);
        if(strcmp("cd",a) == 0){
            current_dir();
        }else if(strcmp("cmds",a) == 0){
            display_commands();
        }else if(strcmp("cls",a) == 0){
            clear_screen();
        }else{
            SetColor(4);
            printf("error - This command didn't match.Enter 'cmds' for help.\n");
        }
    }while(strcmp(ext,a)!=0);
    return 0;
}
void display_commands(){
    printf("\nAll commands\n");
    printf("exit - exit from shell.\n");
    printf("cd - display current directory.\n");
    printf("mkdir <dir name> - make directory with <dir name>.\n");
    printf("cls - clear screen.\n");
    printf("cmds - display all commands.\n\n");
}
void current_dir(){
    char cwd[256];
    if(getcwd(cwd, sizeof(cwd)) == NULL){
            printf("error");
    }else{
            printf("current directory:%s\n",cwd);
    }
}
void clear_screen(){
    system("cls");
}
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
