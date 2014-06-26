#!/bin/bash

telnetClients=10
rm ./*.out

echo "INCHIDEM SERVERUL ..."
kill -9 `pidof java` 
echo "START SERVER .... in 3 secunde "
java server &
sleep 3s
echo "OK" 

for ((1; i<=$telnetClients; ++i )) ; 
do
	fileName="./file_$i.out"
    telnet localhost 8080 | ./seconds_EPOCH.sh | tee -a $fileName &
done
