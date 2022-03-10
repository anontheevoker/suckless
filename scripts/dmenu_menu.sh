#!/bin/bash
scriptdir="$HOME/.suckless/scripts/"
options=(
"Lock"
"Power"
"Screenshot"
"Keyboard layouts"
"Screencast"
"Wifi"
"Bluetooth"
"External monitor"
"Trackpoint"
)
scripts=(
""
"dmenu_power.sh"
""
"dmenu_keyboardlayouts.sh"
"dmenu_screencast.sh"
"dmenu_wifi.sh"
"dmenu_bluetooth.sh"
"dmenu_screens.sh"
"dmenu_trackpoint.sh"
)
menu=$(printf '%s\n' "${options[@]}" | dmenu -i )
for i in "${!options[@]}"; do
  if [ ! -z "$menu" ] && [[ "$menu" = "Lock" ]]; then
    $(eval slock) && exit
  elif [ ! -z "$menu" ] && [[ "$menu" = "Screenshot" ]]; then
    $(eval scrot -d 0.1 $HOME/Pictures/'Screenshot_%Y-%M-%d_%H-%M-%S.png') && exit
  elif [ ! -z "$menu" ] && [[ "${options[$i]}" = $menu ]]; then
    "$scriptdir${scripts[i]}" && exit
  fi
done
