#!/bin/bash

# dmenu overview menu

scriptdir="$HOME/.suckless/scripts/"

options=(
"Lock"
"Wifi"
"Power"
"Keyboard layouts"
"Screencast"
"Volume"
)

scripts=(
""
"dmenu_wifi.sh"
"dmenu_power.sh"
"dmenu_keyboardlayouts.sh"
"dmenu_screencast.sh"
"dmenu_volume.sh"
)

menu=$(printf '%s\n' "${options[@]}" | dmenu -i )

for i in "${!options[@]}"; do
  if [ ! -z "$menu" ] && [[ "$menu" = "Lock" ]]; then
    $(eval slock) && exit
  elif [ ! -z "$menu" ] && [[ "${options[$i]}" = $menu ]]; then
    "$scriptdir${scripts[i]}" && exit
  fi
done
