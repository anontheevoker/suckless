#!/bin/bash
while true; do
	bat1cap=$(cat /sys/class/power_supply/BAT0/capacity)
	bat2cap=$(cat /sys/class/power_supply/BAT1/capacity)
	bat1stat=$(cat /sys/class/power_supply/BAT0/status)
	bat2stat=$(cat /sys/class/power_supply/BAT1/status)
	batmean=$(echo "scale=0 ; ($bat1cap + $bat2cap) / 2" | bc)
	if (( $batmean < 15 )) && [ $bat1stat != "Charging" ] && [ $bat2stat != "Charging" ]; then
		eval "systemctl suspend"
	fi
	sleep 60
done
