#!/bin/bash
options=(UK US)
layouts=(gb us)
menu=$(printf '%s\n' "${options[@]}" | dmenu -i)
for i in "${!options[@]}"; do
  if [ ! -z "$menu" ] && [[ "${options[$i]}" = "${menu}" ]]; then
    setxkbmap -layout "${layouts[i]}"
  fi
done
