#!/bin/bash

# pulls data out according to times and logs time with roulette dealer name
grep -i '5\|8\|2\|11' *schedule | awk '{print substr($1,22,2)" "$2" "$5" "$6}'
