#!/bin/bash
poweredon=$(echo -e 'show\n' | bluetoothctl | grep 'Powered: yes')
if [ ! -z "$poweredon" ]; then
  poweroption="Power off" && powercommand="echo -e 'power off\n' | bluetoothctl"
  else
  poweroption="Power on" && powercommand="echo -e 'power on\n' | bluetoothctl"
fi
menu=$(printf '%s\n' "$poweroption" | dmenu -i)
if [ ! -z "$menu" ] && [[ "$poweroption" = $menu ]]; then
 eval "$powercommand" && exit
fi
