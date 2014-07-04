#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

bool isFilePresent( const char* name )
{
  bool haveFile = false;
  path p( name );

  if( exists( p ) )
    {
      haveFile = true;
    }
  else
    {
      haveFile = false;
    }
  return haveFile;
}


int main(int argc, char ** argv)
{

  bool have = isFilePresent( argv[1] );
  if( have )
    {
      return 0;
    }
  else 
    {
      return 1;
    }

}
