# exValide
SDL2 side project, let's make a game engine~ (and maybe a game)
SDL2: https://www.libsdl.org

## Intro:
Using SDL2, we shall recreate a 2D top-down sprite based RPG.  
The combat will not be a turn-base system but rather the player will attack in real time similar to the old Zelda games.  

## Story (WIP):  
  The player wakes up nearby in a forest and is found by a villager that lives on the outskirts of town.  
  The player repays the villager's hospitality by gathering resources from the forest and dungeons to rebuild the house.  
  Villager wants to open a shop for exotic items so the player will need to trade and barter with the townsfolks.  
  Player will try to survive day to day repaying debt to outskirt villager / Run the store.  


## Engine Goals: (WIP)  
By nature a game engine must require a main game loop in which the execution will run repeatedly until user dictates exit  
  Two main parts that make up the game loop are:  
    1) _Render_ -> Allows us to display images and stuff on the screen  
    2) _Logic_ -> Dictates how those objects interact with each other  
  Logic-wise, the `Game Requirements` will dictate how we code the logic but for now we focus on the Render part in this section  
  
>  - Display Background image (for world map)  
>  - Allow for user to get Tick (time from the last update frame call in ms)  
>  - Display static object (stationary object above the background image)  
>  - Display dynamic objects (objects dictated by code that can move around the screen)  
>  - Cull dynamic objects (used for displaying/hiding object on the Z-axis, for example behind a tree, or rock, or infront)  
>  - Basic Collision Detection for Dynamic objects and static objects`  
  
  
## Game Requirements: (WIP)  
>  + A world the player can move around in along with mini-area's (ie. houses, caves, etc...)  
>  + Save and Load System  
>  + Player Inventory and equipment (Player UI ?)  
>  + Barter and Trade system  
>  + Non-player character dialogue and interface system  
>  + Enemies to fight  
>  + Items and loot drop  
  
## Future Goals (May or may not be implemented but nice to have)  
> + Implement a scripting system for super moddability to add objects
> + Implement world editor of some sort, allows for editing tile maps?
