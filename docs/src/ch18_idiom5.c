// https://programming-idioms.org/idiom/162/execute-procedures-depending-on-options
#include <stdio.h>
#include <unistd.h>

void bat(){
    printf("bat\n");
}
void fox(){
    printf("fox\n");
}
int main(int argc, char * argv[])
{
        int optch;
        while ((optch = getopt(argc, argv, "bf")) != -1) {
                switch (optch) {
                        case 'b': bat(); break;
                        case 'f': fox(); break;
                }
        }
        return 0;
}