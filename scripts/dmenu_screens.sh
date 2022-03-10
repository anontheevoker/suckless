#!/bin/bash
options=(Mirror Left Right)
configs=("--same-as eDP1" "--left-of eDP1" "--right-of eDP1")
menu=$(printf '%s\n' "${options[@]}" | dmenu -i)
for i in "${!options[@]}"; do
  if [ ! -z "$menu" ] && [[ "${options[$i]}" = "${menu}" ]]; then
    xrandr --output HDMI2 --auto ${configs[i]}
  fi
done
