#!/bin/bash

p0=~
echo $p0
p1=$p0'/.l3dclient/plugins/'$1
p2=$p0'/.l3dclient/plugins/'$2
p3='ln -sf '$p1' '$p2
 
echo $p3

$p3
  
