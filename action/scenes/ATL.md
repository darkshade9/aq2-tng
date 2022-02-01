# Assassinate the Leader

This is probably the easiest game mode to explain that deviates the least from standard teamplay.  The objective of the scenario is to kill the other team's leader before they kill yours.  If your team kills the opposing team's leader, all members of the opposing team dies, the round ends, and your team scores a team point (exactly like Teamplay).

### Assuming 4v4

* Team A and B both have 4 players
* 1 is considered the 'Leader' on each team
* The others are 'Followers' or 'Crew'
* If `e_mustVolunteer` is set to `1`, the round cannot start unless one player on each team uses the `volunteer` command to volunteer for leader duty
* If `e_mustVolunteer` is set to `0`, the leader is chosen at random on each team at the beginning of each round
* Note: There may be some logic around the randomness, where if your team won, you will continue to be the leader until you are assassinated, and the random selection occurs again, perhaps weighted against the most recent leader so they have a less chance of being re-elected?

### Scoring:

* Killing the enemy leader
    * 10 points to the killer
    * 1 team point
    * 1 point for every member of the winning team
* Killing crew members
    * 1 point
* Killing crew members within an area near the Leader (harassing defenders/bodyguards)
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

Example: `PLAYER_RANDOM "Ramone" TEAM "The Rojos" SKIN "male/nut" WEAPONS + SILENCER + SLIPPERS + BANDOLIER + VEST + LASER`

Defines a team named "The Rojos", led by "Ramone", whose skin is "male/nut", has all weapons available to the Leader, and is allow to choose the Silencer, Slippers, Bandolier, Kevlar Vest and Laser

`TEAM` field sets the values for the other team members that are not leaders
* `SKIN` "model/skin"
* `WEAPONS` mean all weapons are enabled 
    * +/- delimited list of available items to choose from
    * `+` means available to choose
    * `-` means unable to choose
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

## Notes and Ideas

* Unlike standard teamplay round-based games, this game type involves continuous play, it only ends when a timelimit, fraglimit or roundlimit is reached.
