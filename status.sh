#!/bin/bash

while true; do
x=$(uptime -p)
y=$(date '+%d.%m.%Y %H:%M:%S')
xsetroot -name "$x $y"
	sleep 1

done
