include ${top_srcdir}/moc.mk
bin_PROGRAMS = L3DClient

L3DClient_SOURCES = \
  src/main.cpp\
  src/vrmlreader.cpp\
  src/vrmlreader.h\
  src/coinviewer.cpp\
  src/coinviewer.h\
  moc_coinviewer.cpp\
  src/gui.cpp\
  src/gui.h\
  moc_gui.cpp

L3DClient_CXXFLAGS = -std=c++11 $(CXXFLAGS_COIN) $(CXXFLAGS_SOXT)
L3DClient_CPPFLAGS = $(QT4_CFLAGS) $(CPPFLAGS_COIN) $(CPPFLAGS_SOXT) 
L3DClient_LDFLAGS  = $(QT4_LIBS) $(LDFLAGS_COIN) $(LDFLAGS_SOXT)
L3DClient_LDADD = $(LIBS_COIN) $(LIBS_SOXT)