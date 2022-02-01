# Find / Retrieve / Defend

This is a mixture of Escort the VIP and Capture the Briefcase. A player on one team is chosen to pickup a package from a fixed location, and deposit it at another fixed location. The enemy team's objective is to assassinate that player.  This scene involves a dual GOAL for the escorting team -- one goal is to `ESCORT` the carrier/leader to the `TARGET_AREA`, the other goal is to `RETRIEVE` the `TARGET_OBJECT` from the `TARGET_LOCATION`.

### Assuming 4v4

* Team A and B both have 4 players
* 1 is considered the 'Leader' on each team
* The others are 'Followers' or 'Crew'
* If `e_mustVolunteer` is set to `1`, the round cannot start unless one player on each team uses the `volunteer` command to volunteer for leader duty
* If `e_mustVolunteer` is set to `0`, the leader is chosen at random on each team at the beginning of each round
* Note: There may be some logic around the randomness, where if your team won, you will continue to be the leader until you are assassinated, and the random selection occurs again, perhaps weighted against the most recent leader so they have a less chance of being re-elected?

### Scoring:
Team A's goal is to find, retrieve and deliver the briefcase

Team B's goal is to kill the carrier/leader

* Team A successfully escorts carrier/leader to `TARGET_AREA`:
    * 1 point to all members of Team A
    * 1 point for the carrier/leader
* Team A captures the briefcase at the `TARGET_AREA`:
    * 1 team point for Team A
    * 10 points to all members of Team A
    * 10 points for the carrier/leader
* Team A crew member kills enemy while within near range of the carrier/loader
    * 1 point for defending the carrier/leader
* Team B kills Team A's carrier/leader:
    * 1 team point for Team B
    * 10 points for the killer
* Team member kills opposing team's crew members
    * 1 point

---

## Parts of the Scene file

`SCENARIO` field in the scene file determines the name of the scenario, this is unique among all scenes loaded into memory, so it can be referenced directly

`TARGETS` are the objectives in this scenario, in this case, they are the team's Leaders
* `PLAYER_RANDOM` "LeaderName" (`PLAYER_RANDOM` defaults to random player unless `e_mustVolunteer` is `1`)
    * `TEAM` "TeamName" 
    * `SKIN` "model/skin" 
    * `WEAPONS` mean all weapons are enabled 
        * +/- delimited list of available items to choose from
        * `+` means available to choose
        * `-` means unable to choose

Example: `PLAYER_RANDOM "Ramone" TEAM "The Rojos" SKIN "male/nut" WEAPONS + SILENCER + SLIPPERS + BANDOLIER + VEST + LASER`

* `TARGET_LOCATION` defines the area that the briefcase must be picked up from
* `TARGET_AREA` defines the area that the briefcase must be delivered to
* `TARGET_OBJECT` defines the object that the carrier must retrieve
    * `MODEL` reference to a model file of the briefcase at its spawn area
    * `PIC` reference to a pic file that skins the `VWEP`
    * `VWEP` reference to the model that is skinned by `PIC` while being held by the carrier


`TEAM` field sets the values for the other team members that are not leaders
* `SKIN` "model/skin"
* `WEAPONS` "all"
* `RESPAWN` multiple parameters
* `GOALS` assassinate other team's leader

`RESPAWN` options:

Time (choose one):
* `INSTANT` (instant respawn upon death)
* `TIME` [`time`] (wait [time] until respawn after death)
* `FRACTION` [`percent`] (will only respawn once the remaining amount of live players on the team reaches this percentage)  
Example: FRACTION 25 would mean you would only respawn if 25 percent of your players remain
* `PERIODIC` [`time`] (respawn every [time] seconds)

Location (choose one):
* `INITIAL_SPAWN` (always spawn at the original spawn point)
* `AWAY_FROM` [`target_name`] [`spawn_spots`] (spawn [`spawn_spots`] away from the [`target_name`]

`GOALS` option:
* ASSASSINATE (kill the player defined as the target)
* ESCORT "Drug Courier" TO "Limo Trunk"
* RETRIEVE "Drug Shipment" FROM "Truck" TO "Limo Trunk" BY "Drug Courier"

## Notes and Ideas

