/* 
#include <iostream> 
using namespace std;
int main()
{ 
    cout << "Hello, world!" << endl;
    cerr << "ERROR!11!!1!" << endl; 
    int a;
    cin >> a;
    return a; 
 }
}




miao
компилятормяу
g++ -o hw hw.cpp НЕ ЗАБЫВАТЬ 11!!!1!11!


#include <iostream> 
using namespace std;
int main()
{
  int socks[12];
  for(int i=0 ; i < 12; i++){
    socks [i]=i;
  }
  for(int i=0 ; i < 12; i++){
      cout << "socks[ " << i << " ] = " << socks[i] << "\n";
  }
}







*/
#include <iostream> 
using namespace std;
int main(int argc , char* argv[])
{//argc аргумент counter счетчик
  // argv одномерный массив аргументов argument vector
  int socks[12];
  for(int i=0 ; i < 12; i++){ //задает 
    socks [i]=i;
  }
  for(int i=0 ; i < 12; i++){//показывает
      cout << "socks[ " << i << " ] = " << socks[i] << "\n";
  }
  for(int i=0 ; i < argc; i++){//показывает
      cout << "argv[ " << i << " ] = " << argv[i] << "\n";
  }
}
