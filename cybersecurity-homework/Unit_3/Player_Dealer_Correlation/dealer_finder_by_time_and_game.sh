
#!/bin/bash

# finds the roullette dealer on a given data ($1) at a given time ($2)
# this script will return two name, the first being the dealer working the AM shift,
# the second being the dealer working the PM shift

clear && echo " =============\n Dealer Finder \n ============="

# selects a game
echo "\n Pick a game:\n 1: BlackJack\n 2: Roulette\n 3: Texas Hold Em\n"
read -p " $PS1" game && clear && echo " =============\n Dealer Finder \n ============="

# selects a date
echo "\n Pick a data (ex. 0310 = march 10): \n"
read -p " $PS1" date && clear && echo " =============\n Dealer Finder \n ============="

# selects a time
echo "\n Pick a time: \n"
read -p " $PS1" time_played && clear

echo " =============\n Dealer Finder \n =============\n"

if [ $(expr $game == 1) ]; then
    echo " Game: BlackJack"
elif [ $(expr $game == 2) ]; then
    echo " Game: Roulette"
else
    echo " Game: Texas Hold Em"
fi

echo " Date: $date\n Time: $time_played\n\n Results:"

# prints dealer name
if [ $(expr $game == 1) ]; then
    grep -i $time_played $date* | awk '{print " > "$3" "$4}'
elif [ $(expr $game == 2) ]; then
    grep -i $time_played $date* | awk '{print " > "$5" "$6}'
elif [ $(expr $game == 3) ]; then
    grep -i $time_played $date* | awk '{print " > "$7" "$8}'
else
    echo " ERROR: trouble reading user input" && sleep 3 && clear && exit 1
fi

echo "\n Note, the first name is the AM dealer and the second name is the PM dealer\n"
