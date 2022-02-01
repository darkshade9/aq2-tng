# Capture 'n Hold

In this scenario type, your team must capture an area and hold it.  As long as your team 'owns' that area, everyone on the team gains points on an interval.  To capture an area, you must stand in or near the area with no other enemies in that same area for 2 seconds.  You can define up to two areas, one for each team to defend.  It tends to be more exciting to fight over one area, though ;)

### Scoring:

#### Defending team:
(Defending team is considered the current owner of the area)
* Capture a target area
    * 1 point
* Hold it for the defined interval
    * All members receive 10 points
* Defending the area (killing an enemy near the capture area)
    * 1 point each
* Killing enemy team members
    * 1 point each

##### Scoring example: I capture an area, hold it for 30 seconds and kill an enemy while in my capture area.  I score 1 point for capturing, 10 points for holding for 30 seconds, 1 point for killing an enemy member and 1 additional point for killing them in our capture area

#### Attacking team:
(Attacking team is considered in the enemy capture area)
* Capture an area from the other team (first player to reach the target area)
    * 10 points
* Killing enemy team members in their capture area
    * 1 point each
* Killing enemy team members
    * 1 point each

##### Scoring example: I invade an area that the enemy has captured and kill a player.  I get 1 point for killing an enemy team member, and 1 point for killing them in their capture area
---

## Parts of the Scene file

`SCENARIO` field in the scene file determines the name of the scenario, this is unique among all scenes loaded into memory, so it can be referenced directly

* `TARGET_AREA` are areas on the map that pertain to objectives in this scenario, in this case, it is a location to capture and hold
* `MODEL` reference to a model file to help players determine where a `TARGET_AREA` is

`TEAM` field sets the values for the other team members that are not leaders
* `SKIN` "model/skin"
* `WEAPONS` "all"
* `RESPAWN` multiple parameters
* `GOALS` assassinate other team's leader

`RESPAWN` options:

Time (choose one):
* INSTANT (instant respawn upon death)
* TIME [time] (wait [time] until respawn after death)
* FRACTION [percent] (will only respawn once the remaining amount of live players on the team reaches this percentage)  
Example: FRACTION 25 would mean you would only respawn if 25 percent of your players remain
* PERIODIC [time] (respawn every [time] seconds)

Location (choose one):
* INITIAL_SPAWN (always spawn at the original spawn point)
* AWAY_FROM [target_name] [spawn_spots] (spawn [spawn_spots] away from the [target_name]

`GOALS` option:
* HOLDALL [AREA_NAME] [INTERVAL] [TARGET_AREA]
    * Example: HOLDALL "The Egg Chamber" 30 "The Blue Egg"
    * Defines the name of the TARGET_AREA as "The Egg Chamber"
    * Scoring interval is 30 seconds
    * The TARGET_AREA is "The Blue Egg" as defined in the `TARGETS`

## Notes and Ideas

* Multiple targets can be defined
* The team only scores if _ALL_ capture points are held by the same team for the interval given
    * Example `GOALS` that would need to be held at once for 60 seconds
    * `HOLDALL "Hondo Arms Hotel" 60 "Lobby" "Room 101" "Room 102" "Room 201" "Room 202" "Roof Top"`
* All values with spaces must be surrounded with double quotes, though it's usually just a good idea to do it for all values except for integers