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
#include <string>
#include <cstdlib>

using namespace std;

void getHelp(); // объявление функции 

// string=="--help"
int main(int argc , char *argv[])
{//argc аргумент counter счетчик
  // argv одномерный массив аргументов argument vector

  if (const char* env_p = getenv ("PATH")) {
    cout << "PATH:" << env_p << "/n";
  }

  bool needHelp = false;
  // for (int i = 0; i < argc; i++) {
  //     cout << "argv [ " << i << "] = " << argv[i] << '\n';
  // }
  // int socks[12];
  // for(int i=0 ; i < 12; i++){ //задает 
  //   socks [i]=i;
  // }
  // for(int i=0 ; i < 12; i++){//показывает
  //     cout << "socks[ " << i << " ] = " << socks[i] << "\n";
  // }

  for(int i=0 ; i < argc; i++){//показывает
    string arg = argv[i];
    cout << "argv[ " << i << " ] = " << argv[i] << "\n";
    if (arg == "--help") {
      needHelp = true;
    }
  }

  if (needHelp){
    getHelp();
  }
  
  return 0;
}
/*
void getHelp(){ 
  
  cout << "HEHEHEHEHLPLPPPP!!! \n";
  const char* author_ptr = getenv ("AUTHOR");
  const char* version_ptr = getenv ("VERSION");
  string AUTHOR = " ";
  string VERSION = " ";
  if (author_ptr){
    std::string AUTHOR = author_ptr;
  }else{
    cerr<<"iinnnooo AUTHOR not get!!1!"<<"\n";
  }
  if (version_ptr){
    std::string VERSION = version_ptr;
  }else{
    cerr<<"iinnnooo VERSION not get!!1!"<<"\n";
  }

  }

  */
