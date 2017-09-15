
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string str("Split me by whitespaces");
    string buf; // 버퍼 string
    stringstream ss(str); // string을 stream에 넣는다

    vector<string> tokens; // word들을 넣을 vector

    while (ss >> buf)
        tokens.push_back(buf);
}


#include <stdio.h>    //printf
#include <string.h>   //strtok
 
int main( )
{
    char *token = NULL;
    char str1[] = "This is\tTest,Program!\n";
    char str2[] = " ,\t\n";//' '이나 ','이나 '\t'이나 '\n'이 들어있는 문자열을 분리
 
    token = strtok( str1, str2 );
 
    while( token != NULL )
    {
        printf( "token = %s", token );
        putchar( '\n' );
        token = strtok( NULL, str2 );
    }
 
    return 0;
}