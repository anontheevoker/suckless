#!/bin/bash
blevel=$(xbacklight -get)
if (( $(echo "$blevel > 5" | bc -l ) )); then
  xbacklight -5
fi
