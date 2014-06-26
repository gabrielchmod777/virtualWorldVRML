#!/bin/bash

echo 'Start test\n'
echo '-------------------------'
echo 'Testeaza -> Add 1 1'
v1=`java ApendixB Add 1 1`
./check.sh 2 $v1
echo '-------------------------'
echo 'Testeaza -> Add 5 1'
v1=`java ApendixB Add 5 1`
./check.sh 6 $v1
echo '-------------------------'
echo 'Testeaza -> Sub 1 1'
v1=`java ApendixB Sub 1 1`
./check.sh 0 $v1
echo '-------------------------'
echo 'Testeaza -> Sub 5 1'
v1=`java ApendixB Sub 5 1`
./check.sh 4 $v1
echo '-------------------------'
echo 'Testeaza -> Add 10 10'
v1=`java ApendixB Add 10 10`
./check.sh 20 $v1
echo '-------------------------'
echo 'Testeaza -> Sub 10 11'
v1=`java ApendixB Sub 10 11`
./check.sh -1 $v1
echo '-------------------------'
echo 'Testeaza -> Sub 19 3'
v1=`java ApendixB Sub 19 3`
./check.sh 16 $v1
echo '-------------------------'
echo 'Testeaza -> Add 101 10'
v1=`java ApendixB Add 101 10`
./check.sh 111 $v1
echo '-------------------------'
echo 'Testeaza -> Sub 0 3'
v1=`java ApendixB Sub 0 3`
./check.sh -3 $v1
echo '-------------------------'
echo 'Testeaza -> Sub 1 1'
v1=`java ApendixB Sub 1 1`
./check.sh 0 $v1
echo '-------------------------'
echo 'Stop test\n'
