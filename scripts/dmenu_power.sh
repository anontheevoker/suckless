#!/bin/bash
options=(Suspend Shutdown Reboot)
commands=("systemctl suspend" "systemctl poweroff" "systemctl reboot")
menu=$(printf '%s\n' "${options[@]}" | dmenu -i)
for i in "${!options[@]}"; do
  if [ ! -z "$menu" ] && [[ "${options[$i]}" = $menu ]]; then
    confirmation=(Cancel "$menu")
    submenu=$(printf '%s\n' "${confirmation[@]}" | dmenu -i );
    if [ ! -z "$menu" ] && [[ "${submenu}" = "$menu" ]]; then
      $(eval "${commands[i]}")
    fi
  fi
done
