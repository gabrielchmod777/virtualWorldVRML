AC_INIT([L3DClient],[0.01])

PKG_CHECK_MODULES(QT4, [QtCore QtGui >= 4.4.0], [
  AC_PATH_PROGS(MOC, [moc-qt4 moc], moc,`eval $PKG_CONFIG --variable=exec_prefix QtCore`/bin)
  AC_PATH_PROG(RCC, rcc, rcc,`eval $PKG_CONFIG --variable=exec_prefix QtCore`/bin)
  AC_PATH_PROGS(UIC, [uic-qt4 uic], uic,`eval $PKG_CONFIG --variable=exec_prefix QtCore`/bin)
  ], [
  AC_MSG_ERROR([Qt 4 library not found])
])

AM_INIT_AUTOMAKE([-Wall])

AC_CONFIG_FILES([Makefile])
AC_PROG_CXX

AC_OUTPUT