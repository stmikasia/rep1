#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    int fda[2];
    char buf[1];

    if (pipe(fda) < 0) cerr<<"create pipe failed";

    switch (fork()){
    case -1: cerr <<"fork failed";
    case 0:
        while(1)
        {
        close(fda[1]);
        read(fda[0],buf,1);
        cout << buf[0]<<endl;
        break;
        }
    default:
        while(1)
        {
        close(fda[0]);
        write(fda[1],"ar",1);
        break;
        }
    }

    return 0;
}
