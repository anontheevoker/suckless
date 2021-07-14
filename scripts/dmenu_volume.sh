#!/bin/bash

# volume dialog for dmenu

vol=$(amixer get Master | sed -n 'N;s/^.*\[\([0-9]\+%\).*$/\1/p')

if [ ! -z "$(amixer get Master | grep off)" ]; then
  mutestatus="Unmute" # muted, so unmute
else
  mutestatus="Mute"   # unmuted, so mute
fi

menu=$(printf $mutestatus | dmenu -p "$vol ->")

if [ ! -z "$menu" ] && [[ $(($menu)) = $menu ]] && (("$menu" >= 0 && "$menu" <= 100)); then
  amixer sset Master "${menu}"% && exit
elif [ ! -z "$menu" ] && [[ $menu = $mutestatus ]]; then
  amixer sset Master toggle && exit
fi
