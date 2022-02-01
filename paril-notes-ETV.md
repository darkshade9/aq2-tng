# Escort the VIP

In this game mode, one team must `ESCORT` their Leader to a point on the map.  The other team's objective is to kill the enemy Leader before they reach the point on the map.  This is similar to Assassinate the Leader in that the most important member of the team is the Leader, and the team that is escorting them must protect him.

If the escorting team brings the Leader to the defined `ESCORT` point, the defending team all dies at once immediately, the escorting team earns a team point, and all players on the escorting team earn points.

If the defending team kills the escorting team's Leader, the escorting team all dies at once immediately, the defending team earns a team point, and all players on the defending team earn points.

### Assuming 4v4

* Team A and B both have 4 players
* 1 is considered the 'Leader' on one team (the escorting team)
* All other members of the escorting team are considered 'Crew'
* Opposing team have no leader, only 'Crew'
* If `e_mustVolunteer` is set to `1`, the round cannot start unless one player on each team uses the `volunteer` command to volunteer for leader duty.  This only applies to the escorting team
* If `e_mustVolunteer` is set to `0`, the leader is chosen at random on each team at the beginning of each round
* Note: There may be some logic around the randomness, where if your team won, you will continue to be the leader until you are assassinated, and the random selection occurs again, perhaps weighted against the most recent leader so they have a less chance of being re-elected?xw

### Scoring:

#### Defending team:
* Killing the enemy leader
    * 1 Team point
    * 10 points for the player who killed the Leader
    * 1 point for every member of the defending team
* Killing escorting team members
    * 1 point each

#### Escorting team:
* Team Leader touches the target_area
    * 1 Team point
    * 10 points for the Leader
    * 1 point for every member of the escorting team
* Killing defending team members
    * 1 point each

---

## Parts of the Scene file

`SCENARIO` field in the scene file determines the name of the scenario, this is unique among all scenes loaded into memory, so it can be referenced directly

`TARGETS` are the objectives in this scenario, in this case, they are the defined points on the map that are referenced in other areas of the scenario file, and the information about the escorting team's Leader
* `PLAYER_RANDOM` "LeaderName" (`PLAYER_RANDOM` defaults to random player unless `e_mustVolunteer` is `1`)
* `TEAM` "TeamName" 
* `SKIN` "model/skin" 
* `WEAPONS` mean all weapons are enabled 
* +/- delimited list of available items to choose from

* `TARGET_AREA` creates a squared area between two points on the map (use viewpos to get coordinates)
* `MODEL` optional model to load at this `TARGET_AREA` -- helpful for players to 'see' where they need to go for an important area


Example: `PLAYER_RANDOM "Cyrus" TEAM "Robbers" SKIN "male/siris" WEAPONS + SILENCER + SLIPPERS + BANDOLIER + VEST + LASER`


Defines a team named "Robbers", led by "Cyris", whose skin is "male/siris", has all weapons available to the Leader, and is allow to choose the Silencer, Slippers, Bandolier, Kevlar Vest and Laser

`TEAM` field sets the values for the other team members that are not leaders
* `SKIN` "model/skin"
* `WEAPONS` "all"
* `RESPAWN` multiple parameters
* `GOALS` assassinate other team's leader

`RESPAWN` options:

* Time (choose one):
    * INSTANT (instant respawn upon death)
    * TIME [time] (wait [time] until respawn after death)
    * FRACTION [percent] (will only respawn once the remaining amount of live players on the team reaches this percentage)  
Example: FRACTION 25 would mean you would only respawn if 25 percent of your players remain
    * PERIODIC [time] (respawn every [time] seconds)

* Location (choose one):
    * INITIAL_SPAWN (always spawn at the original spawn point)
    * AWAY_FROM [target_name] [spawn_spots] (spawn [spawn_spots] away from the [target_name]

`GOALS` option:
* ASSASSINATE (kill the player defined as the target)
* ESCORT [target_name] TO [target_area] (Cyrus must reach target_area alive)

## Notes and Ideas

* ETE did not have a Kevlar Helmet, we would need to add support in the scene files for this item
* All values with spaces must be surrounded with double quotes, though it's usually just a good idea to do it for all values except for integers
