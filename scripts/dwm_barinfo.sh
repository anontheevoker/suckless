#!/bin/sh
while true; do
	blestatus=$(echo -e 'show\n' | bluetoothctl | grep 'Powered: yes')
	if [ ! -z "$blestatus" ]; then
		blesym="Blu ·"
	else
		blesym=""
	fi
	ssid=$(nmcli dev wifi show | grep SSID | awk '{print $2;}' | cut -c 1-16)
	bat1cap=$(cat /sys/class/power_supply/BAT0/capacity)
	bat2cap=$(cat /sys/class/power_supply/BAT1/capacity)
	batmean=$(echo "scale=0 ; ($bat1cap + $bat2cap) / 2" | bc)
	if (( $batmean > 95 )); then
		batcap="FF"
	else
		batcap=$batmean
	fi
	bat1stat=$(cat /sys/class/power_supply/BAT0/status)
	bat2stat=$(cat /sys/class/power_supply/BAT1/status)
	if [ $bat1stat = "Charging" ] || [ $bat2stat = "Charging" ]; then
		batsym="+"
	else
		batsym="%"
	fi
	vol=$(amixer get Master | sed -n 'N;s/^.*\[\([0-9]\+%\).*$/\1/p' | sed s/%//g)
	if [ ! -z "$(amixer get Master | grep off)" ]; then
		volsym="-"
	else
		volsym="%"
	fi
	clock=$(date +"%a %d %b %I:%M %p ")
	xsetroot -name "$blesym $ssid · V $vol$volsym · B $batcap$batsym · $clock"
	sleep 15
done
