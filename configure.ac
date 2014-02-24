AC_INIT([L3DClient],[0.01])

#
# Check for Qt4 library
#
PKG_CHECK_MODULES(QT4, [QtCore QtGui >= 4.4.0], [
  AC_PATH_PROGS(MOC, [moc-qt4 moc], moc,`eval $PKG_CONFIG --variable=exec_prefix QtCore`/bin)
  AC_PATH_PROG(RCC, rcc, rcc,`eval $PKG_CONFIG --variable=exec_prefix QtCore`/bin)
  AC_PATH_PROGS(UIC, [uic-qt4 uic], uic,`eval $PKG_CONFIG --variable=exec_prefix QtCore`/bin)
  ], [
  AC_MSG_ERROR([Qt 4 library not found])
])

#
# (dirty hack) Check for 'soqt-config' application. If it is installed,
# we can use it to store the flags needed to compile the program with SoQt 
#
# http://stackoverflow.com/questions/10799185/how-do-i-include-mysql-h-and-my-global-h-into-the-makefile-am
#
AC_CHECK_PROG(SOQT_CONFIG_CHECK,soqt-config,yes)
if test x"$SOQT_CONFIG_CHECK" != x"yes" ; then
    AC_MSG_ERROR([Please install SoQt (https://bitbucket.org/Coin3D/coin/downloads).])
fi

CPPFLAGS_SOXT=`soqt-config --cppflags`
CXXFLAGS_SOXT=`soqt-config --cxxflags`
LDFLAGS_SOXT=`soqt-config --ldflags`
LIBS_SOXT=`soqt-config --libs`
AC_SUBST([CPPFLAGS_SOXT])
AC_SUBST([CXXFLAGS_SOXT])
AC_SUBST([LDFLAGS_SOXT])
AC_SUBST([LIBS_SOXT])


#
# (dirty hack) Check for 'coin-config' application. If it is installed,
# we can use it to store the flags needed to compile the program with SoQt 
#
# http://stackoverflow.com/questions/10799185/how-do-i-include-mysql-h-and-my-global-h-into-the-makefile-am
#
AC_CHECK_PROG(SOXT_CONFIG_CHECK,coin-config,yes)
if test x"$SOXT_CONFIG_CHECK" != x"yes" ; then
    AC_MSG_ERROR([Please install Coin (https://bitbucket.org/Coin3D/coin/downloads).])
fi

CPPFLAGS_COIN=`coin-config --cppflags`
CXXFLAGS_COIN=`coin-config --cxxflags`
LDFLAGS_COIN=`coin-config --ldflags`
LIBS_COIN=`coin-config --libs`
AC_SUBST([CPPFLAGS_COIN])
AC_SUBST([CXXFLAGS_COIN])
AC_SUBST([LDFLAGS_COIN])
AC_SUBST([LIBS_COIN])

# end hacks

AM_INIT_AUTOMAKE([-Wall])

AC_CONFIG_FILES([Makefile])
AC_PROG_CXX

AC_OUTPUT