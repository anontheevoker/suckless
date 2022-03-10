#!/bin/bash
tpstat=$(xinput --list-props "TPPS/2 IBM TrackPoint" | grep "Device Enabled")
tpstatnum=${tpstat: -1}
if (( $tpstatnum == 1 )); then
  tpoption="Disable" && tpcommand="xinput --disable 'TPPS/2 IBM TrackPoint'"
elif (( $tpstatnum == 0 )); then
  tpoption="Enable" && tpcommand="xinput --enable 'TPPS/2 IBM TrackPoint'"
fi
menu=$(printf '%s\n' "$tpoption" | dmenu -i)
if [ ! -z "$menu" ] && [[ "$tpoption" = $menu ]]; then
 eval "$tpcommand" && exit
fi
