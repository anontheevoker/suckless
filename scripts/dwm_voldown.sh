#!/bin/bash
vol=$(amixer get Master | sed -n 'N;s/^.*\[\([0-9]\+%\).*$/\1/p' | sed s/%//g)
if (( $vol >= 105 )); then
 lev=$(( $vol -5 )) && pactl -- set-sink-volume 0 $lev%
else
 amixer sset Master 5%- >> /dev/null
fi
