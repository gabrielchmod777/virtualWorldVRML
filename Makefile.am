include ${top_srcdir}/moc.mk

ACLOCAL_AMFLAGS = -I ./build-aux

bin_PROGRAMS = L3DClient

dist_bin_SCRIPTS = scripts/l3dclient_mklocal_dir.sh

BUILT_SOURCES = \
  src/ui_left_form.h \
  src/ui_login.h 

ui_%.h: %.ui
	$(UIC) $< -o $@

clean-uic-extra:
	rm -vf src/uic_*.h *.o src/*.o moc_*.cpp buildaux/*

clean-local: clean-uic-extra


L3DClient_SOURCES = \
  src/main.cpp\
  src/vrml_utils.cpp\
  src/vrml_utils.h\
  src/coinviewer.cpp\
  src/coinviewer.h\
  moc_coinviewer.cpp\
  src/gui.cpp\
  src/gui.h\
  moc_gui.cpp\
  src/avatar.h\
  src/avatar.cpp\
  moc_avatar.cpp\
  src/client.cpp\
  src/executor.h\
  src/executor.cpp\
  src/message_observer.h\
  src/message_queue.h\
  src/message_queue.cpp\
  src/ui_login.h\
  src/login_dialog.h\
  src/login_dialog.cpp\
  moc_login_dialog.cpp

DIRTY_HACK_QT_WEBKIT_INCLUDE = -I/usr/include/qt4/QtWebKit
DIRTY_HACK_QT_WEBKIT_LIB = -lQtWebKit

L3DClient_CXXFLAGS = -std=c++11 -g $(CXXFLAGS_COIN) $(CXXFLAGS_SOXT) $(BOOST_CXXFLAGX) $(DIRTY_HACK_QT_WEBKIT_INCLUDE)
L3DClient_CPPFLAGS = -std=c++11 -g $(QT4_CFLAGS) $(CPPFLAGS_COIN) $(CPPFLAGS_SOXT) $(BOOST_CPPFLAGX) $(DIRTY_HACK_QT_WEBKIT_INCLUDE)
L3DClient_LDFLAGS  = $(QT4_LIBS) $(LDFLAGS_COIN) $(LDFLAGS_SOXT) $(BOOST_ASIO_LDFLAGS) $(BOOST_SYSTEM_LDFLAGS) $(BOOST_THREAD_LDFLAGS) 
L3DClient_LDADD = $(LIBS_COIN) $(LIBS_SOXT)  $(BOOST_ASIO_LIB) $(BOOST_SYSTEM_LIB) $(BOOST_THREAD_LIBS) $(DIRTY_HACK_QT_WEBKIT_LIB)

#install-icons:
#	for icon in $(private_icons); do \
#		mkdir -p $(DESTDIR)$(pkgdatadir)/icons/; \
#		$(INSTALL_DATA) $(srcdir)/$$icon $(DESTDIR)$(pkgdatadir)/icons/; \
#	done

NULL =

vrml_world_files = \
 vrml/world/brick-red.jpg \
 vrml/world/grass-texture.jpg \
 vrml/world/greek_museum.wrl \
 vrml/world/stone.jpg \
 vrml/world/tex_marble.jpg \
 vrml/world/wall-texture.jpg \
 vrml/world/classic_roof.wrl \
 vrml/world/grass.wrl \
 vrml/world/pinetree.wrl.gz \
 vrml/world/tex_blackmarble.jpg \
 vrml/world/utcn_logo.png \
 vrml/world/world.wrl \
 $(NULL)

vrml_avatar_files = \
 vrml/avatar/arm.wrl \
 vrml/avatar/arm2.wrl \
 vrml/avatar/body.wrl \
 vrml/avatar/human.wrl \
 vrml/avatar/avatar_female.wrl \
 vrml/avatar/avatar_male.wrl \
 vrml/avatar/RIGHT_LEG.wrl \
 vrml/avatar/LEFT_LEG.wrl \
 vrml/avatar/t_eye_n.png \
 vrml/avatar/t_eye.d.png \
 vrml/avatar/t_clubGirlsC_s.png \
 vrml/avatar/t_clubGirlsC_n.png \
 vrml/avatar/t_clubGirlsC_dm.png \
 vrml/avatar/head.wrl\
 vrml/avatar/RIGHT_LEG_MALE.wrl\
 vrml/avatar/RIGHT_ARM_MALE.wrl\
 vrml/avatar/LEFT_LEG_MALE.wrl\
 vrml/avatar/LEFT_ARM_MALE.wrl\
 vrml/avatar/body_male.wrl\
 vrml/avatar/BruceWayne_Suit_Torso_S.png\
 vrml/avatar/BruceWayne_Suit_Torso_N.png\
 vrml/avatar/BruceWayne_Suit_Torso_D.png\
 vrml/avatar/BruceWayne_Suit_Legs_S.png\
 vrml/avatar/BruceWayne_Suit_Legs_N.png\
 vrml/avatar/BruceWayne_Suit_Legs_D.png\
 vrml/avatar/BruceWayne_Head_S.png\
 vrml/avatar/BruceWayne_Head_N.png\
 vrml/avatar/BruceWayne_Head_D.png\
 $(NULL)

private_icons = \
  icons/male.png \
  icons/female.png
  $(NULL)

private_media = \
  media/hibou1.ogg \
  $(NULL)

install-pmedia:
	for mdia in $(private_media); do \
		mkdir -p $(DESTDIR)$(pkgdatadir)/media/; \
		$(INSTALL_DATA) $(srcdir)/$$mdia $(DESTDIR)$(pkgdatadir)/media/; \
	done

install-icons:
	for icon in $(private_icons); do \
		mkdir -p $(DESTDIR)$(pkgdatadir)/icons/; \
		$(INSTALL_DATA) $(srcdir)/$$icon $(DESTDIR)$(pkgdatadir)/icons/; \
	done

install-wrl-world:
	for wrmlfile in $(vrml_world_files); do \
		mkdir -p $(DESTDIR)$(pkgdatadir)/vrml/world/; \
		$(INSTALL_DATA) $(srcdir)/$$wrmlfile $(DESTDIR)$(pkgdatadir)/; \
	done

install-wrl-avatar:
	for wrmlfile in $(vrml_avatar_files); do \
		mkdir -p $(DESTDIR)$(pkgdatadir)/vrml/avatar/; \
		$(INSTALL_DATA) $(srcdir)/$$wrmlfile $(DESTDIR)$(pkgdatadir)/; \
	done

install-data-local: install-wrl-world install-wrl-avatar install-icons install-pmedia
