# SO_LONG
Summary: <br>
This project is a very small 2D game.<br>
Its purpose is to make you work with textures, sprites,<br>
and some other very basic gameplay elements.<br>
##
Version: 2.3<br>

{42 Lisboa}

##

## Map rules

> [!IMPORTANT]
> Rules for creating a map.<br>
<br>
The map can be composed of only these 5 characters:<br>
 `0` for an empty space,<br>
 `1` for a wall,<br>
 `C` for a collectible,<br>
 `E` for a map exit,<br>
 `P` for the player’s starting position.<br>
<br>
> [!IMPORTANT]
> The map must and the last line in `null` .<br>

 The map must be rectangular.<br>
 The map must be closed/surrounded by walls. If it’s not, the program must return an error.<br>
 You have to check if there’s a valid path in the map.<br>
 You must be able to parse any kind of map, as long as it respects the above rules.<br>
<br>

## How to use

In the folder `SO_LONG/files` execute the command `make` and lete da magic bigine.<br>
In the folder `SO_LONG/maps` you cand create a new level if you want or edit.<br>
and rune ```./so_long ../maps/level_1.ber``` .<br>

## Erro: list

> [!NOTE]
> 01x means that it was executed successfully.<br>
> 01x:<br>
> Erro: 5 : You win the game!!<br>
> Erro: 4 : You chose the wind<br>
> Erro: 1 : You exited the game<br>

> [!WARNING]
> 00x:<br>
> Erro: 30 : Argumantos a mais<br>
> Erro: 25 : Invalid name map<br>
> Erro: 24 : Invalid name map, fill do not exist<br>
> Erro: 20 : Invalid map, empty or empty line<br>
> Erro: 19 : Invalid map, not rectangular<br>
> Erro: 18 : Invalid map, name missing ".ber"<br>
> Erro: 17 : Invalid map, no coins found<br>
> Erro: 16 : Invalid map, too many or missing exits<br>
> Erro: 15 : Invalid map, too many or missing players<br>
> Erro: 14 : Invalid map, player doesn't reach the exit<br>
> Erro: 13 : Invalid map, player doesn't reach the coins<br>
> Erro: 12 : Invalid map, other characters in the middle<br>
> Erro: 11 : Invalid map, not surrounded by walls<br>
> Erro: 10 : Invalid map, content outside the map<br>

