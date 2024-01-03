#/bin/sh

status () { 

	echo -n "BAT: $(acpi | awk '{print $4}' | sed s/,//) | $(date '+%d.%m.%Y %H:%M:%S')"
}

while :; do
	
	xsetroot -name "$(status)"
	sleep 1

done
