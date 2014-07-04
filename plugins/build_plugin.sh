#!/bin/bash
#
# Coin3D , SoQt , Boost
#
CPPFLAGS_COIN=`soqt-config --cppflags`
CXXFLAGS_COIN=`soqt-config --cxxflags`
LDFLAGS_COIN=`soqt-config --ldflags`
LIBS_COIN=`soqt-config --libs`

CPPFLAGS_QT=`soqt-config --cppflags`
CXXFLAGS_QT=`soqt-config --cxxflags`
LDFLAGS_QT=`soqt-config --ldflags`
LIBS_QT=`soqt-config --libs`
INCLUDEDIR_QT=" -I/usr/include/qt4 -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL  -I/usr/include/qt4/QtWebKit "
#`soqt-config --includedir`

BOOST_CPPFLAGS=" -pthread " 
BOOST_FILESYSTEM_LDFLAGS=" -L/usr/local/lib -Wl,-R,/usr/local/lib "
BOOST_FILESYSTEM_LIBS=" -lboost_filesystem "
BOOST_SYSTEM_LDFLAGS=" -L/usr/local/lib -Wl,-R,/usr/local/lib "
BOOST_SYSTEM_LIBS=" -lboost_system "
BOOST_THREAD_LDFLAGS=" -L/usr/local/lib -Wl,-R,/usr/local/lib "
BOOST_THREAD_LIBS=" -lboost_thread -lboost_system -pthread "

#
# [ -Wall ] display all warnings
# [ -fPIC ] generate Position Independent Code
#
#  MODEL g++ -c -Wall -fPIC plugin1.cpp  -o plugin1.o

g++ -std=c++11 -c -Wall -fPIC $INCLUDEDIR_QT $1 -o $2.o 

#
# [ -Wl,-snoname,<name> ] instuct the linker the
# linker to generate a Dynamic Shared Objects
# instead of an application
#
#g++             -shared -Wl,-soname,cos.so -o cos.so plugin1.o

g++ -std=c++11 $BOOST_CPPFLAGS $CPPFLAGS_COIN $CXXFLAGS_COIN $CPPFLAGS_QT $CXXFLAGS_QT -I$INCLUDEDIR_QT -shared -Wl,-soname,$3.so -o $3.so $2.o  $BOOST_SYSTEM_LDFLAGS $BOOST_SYSTEM_LIBS $BOOST_THREAD_LIBS $BOOST_THREAD_LDFLAGS $BOOST_FILESYSTEM_LDFLAGS $BOOST_FILESYSTEM_LIBS $LDFLAGS_COIN $LIBS_COIN  $LDFLAGS_QT $LIBS_QT
# create links
#ln -sf $3.so.1.0 $3.so.1
#ln -sf $3.so.1.0 $3.so
