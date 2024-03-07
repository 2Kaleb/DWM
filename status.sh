#!/bin/bash

x=$(uptime -p)
while true; do
y=$(date '+%d.%m.%Y %H:%M:%S')
xsetroot -name "$x $y"
	sleep 1

done
