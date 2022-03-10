#!/bin/bash
IFS=$'\n'
ssids=($(nmcli -t -f SSID dev wifi))
menu=$( ( printf "%s\n" "${ssids[@]}" | sort -u) | dmenu -i )
for i in "${!ssids[@]}"; do
  if [ ! -z "$menu" ] && [[ "${ssids[$i]}" = $menu ]]; then
    submenu=$( echo "${ssids[$i]}" | dmenu -i )
    if [ ! -z "$submenu" ] && [ "$submenu" != "${ssids[$i]}" ]; then
      $(eval nmcli device wifi connect \""${ssids[$i]}"\" password "$submenu" >/dev/null) && exit
    elif [ ! -z "$submenu" ]; then
      $(eval nmcli device wifi connect \""${ssids[$i]}"\" >/dev/null) && exit
    elif [ -z "$submenu" ]; then
      exit
    fi
  fi
done
