# Capture the Briefcase

This is CTF, but with briefcases, and a few twists.  One unique aspect of this is that in order to pick up the briefcase, you must have a single MK23 or throwing/slashing knives equipped.  You can't hold a briefcase with two hands on a gun, after all.  If you pick up the briefcase with a knife in hand, for instance, and you switch to a handcannon, you will drop the briefcase at the point you switched weapons.  If you attempt to walk over a briefcase to pick it up and you don't have a free hand, you do not pick up or return the briefcase, you walk through it.  Another aspect is that you cannot return your briefcase unless your own briefcase is at home base.  This means you have to decide how many team members to send after the enemy briefcase holder while still defending your own.

### Scoring:

* Capturing enemy briefcase
    * 10 points to the carrier
    * 1 point for each team member of the capturing team
* Killing briefcase carrier
    * 5 points
* Returning your own briefcase (if `e_carrierReturn` is `1`)
    * 1 point
* Killing opposing team members
    * 1 point
* Defending the briefcase (being within a certain distance of the briefcase and killing an enemy, including if you are the briefcase carrier!)
    * 1 point

---

## Parts of the Scene file
`CONTINUOUS` field sets the action for the entire scenario to 'continuous play', as in when a Team Point is scored, it doesn't end the round, but the play continues.  Without `CONTINOUS`, when a Team Point is scored (such as holding a capture point for 30 seconds), the round wound end, players would despawn/respawn in a new round like standard Teamplay.

`SCENARIO` field in the scene file determines the name of the scenario, this is unique among all scenes loaded into memory, so it can be referenced directly

### TARGETS
* `TARGET_AREA` are areas on the map that pertain to objectives in this scenario, in this case, they are capture points and briefcase locations
    * `MODEL` reference to a model file to help players determine where a `TARGET_AREA` is
* `TARGET_OBJECT` are objects that pertain to this scenario, in this case, they are briefcases
    * `MODEL` reference to a model file of the briefcase at its spawn area
    * `PIC` reference to a pic file that skins the `VWEP`
    * `VWEP` reference to the model that is skinned by `PIC` while being held by the carrier

`TEAM` field sets the values for the other team members that are not leaders
* `SKIN` "model/skin"
* `WEAPONS` "all"
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
* RETRIEVE [TARGET_OBJECT_1] FROM [TARGET_AREA_1] TO [TARGET_AREA_2] WITH [TARGET_OBJECT_2] TOUCH_RETURN (TOUCH_RETURN simply means you need to touch the target area)


## Notes and Ideas

* Unlike standard teamplay round-based games, this game type involves continuous play, it only ends when a timelimit, fraglimit or roundlimit is reached.
