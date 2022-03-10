#!/bin/bash
walls=($HOME/Pictures/Walls/*.png)
x=${#walls[@]}
if (( $(date +%M) != 00 )); then
  y=$(($RANDOM % $x))
  feh --bg-fill ${walls[$y]} && sleep 60
fi
while true; do
  if (( $(date +%M) == 00 )); then
    y=$(($RANDOM % $x))
    feh --bg-fill ${walls[$y]} && sleep 60
  else
    sleep 60
  fi
done
