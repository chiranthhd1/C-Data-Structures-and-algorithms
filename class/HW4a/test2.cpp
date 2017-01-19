/* strtok example */
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

int main ()
{
  char str[] ="- This, a sample string.";
  char* pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);

  fstream myFile("HW4a.txt", ios_base::in);
  string instruct1,instruct2;
  int a[3] = {0};
  int b,c;
  int flag = 0;
  if(myFile.is_open())
  {
    while( getline(myFile,str,'\n'))
    {

      pch = strtok (str," ,.-");
      while (pch != NULL)
      {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
      }
  //return 0;
  }
}