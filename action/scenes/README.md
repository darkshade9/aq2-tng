# Detailed notes about Scenarios
### [Assassinate the Leader](ATL.md)
### [Capture and Hold](CNH.md)
### [Capture the Briefcase](CTB.md)
### [Escort the VIP](ETV.md)
### [Find/Retrieve/Defend](FRD.md)
### [One Flag Capture](OFC.md)
---
## Definitions

* `scene`: An indivdual file containing `scenarios`
* `scenario`: A set of rules on goals, teams and targets
* `continuous`: A scene that has `CONTINUOUS` enabled means that the round does not end when a team point is made, such as capturing a briefcase or holding a capture point.  This keeps the game moving as one continuous round until a timelimit, fraglimit or roundlimit is reached, and the next map loads.

## Espionage-specific settings requirements

* `scripts <0|1>` - enables Espionage mode and performs the following:
    * Enforces:
        * `teamplay 1`
        * `deathmatch 1`
        * `use_3teams 0` - There is no 3 team Espionage support (yet?)
        * `use_tourney 0` - Disables tournament mode (may revisit for Espionage Tournament Edition?)
        * `use_matchmode 0` - Disables matchmode (may revisit for Espionage Tournament Edition?)
        * `spawnProtect 0` - This is a DM-only feature
    * Requires:
        * `e_maxVolunteers <0|1>` - defaults to 0
        * `e_mustVolunteer <0|1>` - defaults to 0
        * `e_useDefaultScenario <0|1|2|3>` - defaults to 0
        * `e_defaultScenarioName ""` - defaults to "Assassinate The Leader"
        * `e_carrierReturn <0|1>` - defaults to 1
    * Ignores:
        * `wp_flags` - Weapon loadouts are managed by the scene, not a dmflag
        * `itm_flags` - Item loadouts are managed by the scene, not a dmflag


## Message formatting (`CenterPrintAll`)
### Minimum 1 player on each team
```
The round will begin in 20 seconds!
```

### Not enough players, and
### Volunteer needed (`e_mustVolunteer = 1` and no one used the `volunteer` command) 
```
Not enough active players on
team_1_name
to select
team_1_target_name
Someone needs to type 'volunteer'
in the console
```

### Round begin:
ETV:
```
team_1_name must:
assassinate team_2_target_name (actual_player_name)

team_2_name must:
escort team_2_target_name (actual_player_name) safely to 
target_area
```

CTB:
```
team_1_name must:
retrieve target_object_1 from target_area_2 and
bring it to target_area_1

team_2_name must:
retrieve target_object_2 from target_area_1 and
bring it to target_area_2
```

## Kill messaging:
* Killing a Leader
    * Player log:
        * `You get 10 bonus points for eliminating enemy_target_name`
    * Console log:
        * `player_name gets 10 bonus points for eliminating enemy_target_name`
* Within X amount of distance from Leader, or Leader yourself:
    * Player log:
        * `You get 3 bonus points for defending leader_name`
    * Console log:
        * `player_name gets 3 bonus points for defending leader_name`
* Alive when the round ends:
    * Player log:
        * `You get 10 bonus points for surviving the round`
    * No console log(?) since this can be a single player or an array of players


---

## Notes/Ideas/Improvements

### Notes
* ETE did not have a Kevlar Helmet, we would need to add support in the scene files for this item
* All values with spaces must be surrounded with double quotes, though it's usually just a good idea to do it for all values except for integers
* Currently there's a pretty bad bug with loading scenarios and the use of `gamemap` -- ETE was designed before `gamemap` functionality was a thing, it relies on the old `map` functionality to load in the scenario.  Using `gamemap` to go to the next map breaks this and scenarios will default to the first one loaded when the server started.

### Ideas

### Improvements
* I think scoring could be improved
    * Current ways to score
        * Killing an enemy or enemy Leader
        * Retrieving a briefcase
        * Capturing a briefcase
        * Reaching an escort point as the Leader
        * Killing an enemy crewmember within X distance from Leader (harassing the bodyguard)
        * Capturing a capturepoint
        * Holding a capturepoint over an interval
    * New ways to score
        * Bonus points for Accuracy (triggered under the same conditions the announcer voiceover says "Accuracy!")
