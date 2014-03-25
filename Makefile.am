include ${top_srcdir}/moc.mk

ACLOCAL_AMFLAGS = -I ./build-aux

bin_PROGRAMS = L3DClient

BUILT_SOURCES = src/ui_camerapositioning_dialog.h

ui_%.h: %.ui
	$(UIC) $< -o $@

clean-uic-extra:
	rm -vf src/uic_*.h

clean-am: clean-uic-extra


L3DClient_SOURCES = \
  src/main.cpp\
  src/vrmlreader.cpp\
  src/vrmlreader.h\
  src/coinviewer.cpp\
  src/coinviewer.h\
  moc_coinviewer.cpp\
  src/gui.cpp\
  src/gui.h\
  moc_gui.cpp\
  src/avatar.h\
  src/avatar.cpp\
  moc_avatar.cpp\
  src/ui_untitled.h\
  src/vector2f.cpp\
  src/client.h\
  src/client.cpp\
  src/executor.h\
  src/executor.cpp\
  src/message_observer.h\
  src/message_queue.h\
  src/message_queue.cpp

L3DClient_CXXFLAGS = -std=c++11 -g $(CXXFLAGS_COIN) $(CXXFLAGS_SOXT) $(BOOST_CXXFLAGX) 
L3DClient_CPPFLAGS = -std=c++11 -g $(QT4_CFLAGS) $(CPPFLAGS_COIN) $(CPPFLAGS_SOXT) $(BOOST_CPPFLAGX)
L3DClient_LDFLAGS  = $(QT4_LIBS) $(LDFLAGS_COIN) $(LDFLAGS_SOXT) $(BOOST_ASIO_LDFLAGS) $(BOOST_SYSTEM_LDFLAGS)
L3DClient_LDADD = $(LIBS_COIN) $(LIBS_SOXT)  $(BOOST_ASIO_LIB) $(BOOST_SYSTEM_LIBS)

