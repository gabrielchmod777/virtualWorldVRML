#!/bin/bash
make clean
rm moc_*
autoreconf -i
./configure
make