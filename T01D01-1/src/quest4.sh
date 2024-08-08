# смотрим все открытые процессы 

ids=$(fuser ai_door_control.sh | cut -c 1-21)

kill $ids