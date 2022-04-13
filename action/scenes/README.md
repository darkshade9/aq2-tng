# Detailed notes about Scenarios
### [Assassinate the Leader](ATL.md)
### [Capture and Hold](CNH.md)
### [Capture the Briefcase](CTB.md)
### [Escort the VIP](ETV.md)
### [Find/Retrieve/Defend](FRD.md)
### [One Flag Capture](OFC.md)
---
# AQDT Official Docs
### [ATL](https://assets.aq2world.com/archive/websites/aqdt.fear.net/aqdtdocs/scenarios-atl.htm) | [CNH](https://assets.aq2world.com/archive/websites/aqdt.fear.net/aqdtdocs/scenarios-cnh.htm) | [ETV](https://assets.aq2world.com/archive/websites/aqdt.fear.net/aqdtdocs/scenarios-etv.htm) | [CTB](https://assets.aq2world.com/archive/websites/aqdt.fear.net/aqdtdocs/scenarios-ctb.htm) | [FRD](https://assets.aq2world.com/archive/websites/aqdt.fear.net/aqdtdocs/scenarios-frd.htm)
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
        * `spawnProtect 0` - This would interfere with the continuous play
    * Requires:
        * `e_maxVolunteers <0|1>` - defaults to 0
        * `e_mustVolunteer <0|1>` - defaults to 0
        * `e_useDefaultScenario <0|1|2|3>` - defaults to 0
        * `e_defaultScenarioName ""` - defaults to "Assassinate The Leader"
        * `e_carrierReturn <0|1>` - defaults to 1
    * Ignores (weapons and items are set in the scene files):
        * `wp_flags` - Weapon loadouts are managed by the scene, not a dmflag
        * `itm_flags` - Item loadouts are managed by the scene, not a dmflag
---
## Espionage cvars and commands
* **goals**
    * Issued by a client when a map is loaded, it will centerprint the goals of the scenario.
* **volunteer**
    * Issued by a client after joining a team, a `volunteer` is chosen for 'special duty' to be the Leader in scenarios that use Leaders (ETV, ATL, FRD).  Players who do not issue the `volunteer` command are not eligible to become the Leader, unless `e_mustVolunteer` is enabled.  Matches that require at least 1 `volunteer` will not begin until that requirement is met.  Simiiar to how `captains` are issued, but multiple can `volunteer` up until the e_maxVolunteers value.
* **sv scenarios** 
    * Issued via rcon, this lists the maps and associated scenarios in rotation on the server
* **sv goto [scn num]**
    * Issued via rcon, the argument provided changes to the scene number provided by **sv scenarios** in the event that a map has multiple scenarios and the server admin wants to override the default one loaded
* **e_maxVolunteers**
    * Maximum amount of volunteer per team.  `0` value means there are no restrictions to the amount of volunteers per team.
* **e_mustVolunteer**
    * Requires players to issue the `volunteer` command to begin the match.  If this is set to `0`, players will be chosen at random for the Leader position on new round spawn.
* **e_useDefaultScenario**
    * Settings:
        * `0` - default to normal teamplay for maps where a scenario can't be found
        * `1` - use scenario specified in e_defaultScenarioName if a scenario can't be found (default)
        * `2` - use default scenario for all maps
        * `3` - use default scenario on maps in action.ini instead of action.scp 
* **e_defaultScenarioName**
    * Used in tandem with **e_useDefaultScenario**, it determines which scenario is used if a map is loaded if no scenes are specified.  See the [original documentation](https://assets.aq2world.com/archive/websites/aqdt.fear.net/aqdtdocs/esp6.htm) if this is still unclear.
* **e_carrierReturn**
    * Setting this to `0` means the carrier (the player that currently has the enemy briefcase) cannot touch his own briefcase to return it to base.  Setting this to `1` allows the carrier to return his own briefcase to base.
* **e_caseReturnTime**
    * Setting this to a value in seconds of how much time passes since the briefcase has dropped before it automatically returns to base.  Value if `0` means case does not return automatically.  Suggested values here are `45` to `120` seconds.  Maximum value is `300`.
* **allowMPELPSuicide** (optional)
    * It used to be a popular tactic to suicide by the `kill` command after being shot in the stomach by a sniper to deny the sniper his frag at the expense of your own score.  Setting this to `0` meant the game would deny this action.  Setting it to `1` would randomly allow it (<10% chance?)
---
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
---
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
## Scoring
Points listed here are equivalent to 'frags'
* **ATL**
    * Defending the Leader (3 pts)
        * Non-Leader near the Leader and killing an enemy
        * Leader killing an enemy
    * Harassing the Leader (3 pts)
        * Killing non-Leader near the Leader
    * Leader is assassinated (10 pts)
        * Awarded to all members of the defending team
    * You assassinated the Leader (10 pts)
        * Awarded to the assassin
* **ETV**
    * Defending the Leader (3 pts)
        * Non-Leader near the Leader and killing an enemy
        * Leader killing an enemy
    * Harassing the Leader (3 pts)
        * Killing non-Leader near the Leader
    * Leader reaches escort point (10 pts)
        * Awarded to all members of the escort team, dead or alive
    * Leader is assassinated (10 pts)
        * Awarded to all members of the defending team
    * You assassinated the Leader (10 pts)
        * Awarded to the assassin
* **CNH**
    * Capturing a point (1 pt)
    * Killing enemy near capture point (1 pt)
    * Capture point held for hold timer (10 pts)
        * Awarded to all members of the holding team
* **CTB/OFC** (Carrier is defined as the player who currently holds the briefcase)
    * Capturing enemy briefcase (10 pts)
        * Awarded to the Carrier
    * Defending the Carrier (3 pts)
        * Killing an enemy while near the Carrier
    * Harassing the Carrier (3 pts)
        * Killing a defender while they are near the Carrier
    * Killing the Carrier (5 pts)
* **FRD** (Leader is defined as the player volunteered for duty that has not picked up the briefcase yet.  Carrier is defined as the player who has picked up the briefcase.)
    * Capturing enemy briefcase (10 pts)
        * Awarded to the Carrier
    * Defending the Leader/Carrier (3 pts)
        * Killing an enemy while near the Carrier
    * Harassing the Leader/Carrier (3 pts)
        * Killing a defender while they are near the Carrier
    * Killing the Leader (5 pts)
    * Killing the Carrier (10 pts)
---

## Notes/Ideas/Improvements

### Notes
* ETE did not have a Kevlar Helmet, we would need to add support in the scene files for this item
* All values with spaces must be surrounded with double quotes, though it's usually just a good idea to do it for all values except for integers
* When the Leader dies, the rest of his team also immediately dies with him, ending the round.
* When the Leader reaches an Escort point (ETV) or delivers the package (FRD), all members of the defending team die immediately.
* Currently there's a pretty bad bug with loading scenarios and the use of `gamemap` -- ETE was designed before `gamemap` functionality was a thing, it relies on the old `map` functionality to load in the scenario.  Using `gamemap` to go to the next map breaks this and scenarios will default to the first one loaded when the server started.  Current q2pro settings to fix this are `sv_allow_map 1`

### Ideas

#### Interactions
In its final form, Espionage had a Tournament Edition that included Matchplay settings specifically for Espionage.  This was activated by
* `scripts 1`
* `matchplay 1`
Utilizing `matchmode` in TNG, we can incorporate the enhancements of TNG with Espionage to create a similar experience:
    * `captain` players assigning Leaders if they wish
    * No need for `teamname` or `teamskin` as they are set in the scene files 


#### Improvements
* Scoring
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
* Voting
    * Allow players to vote for scenario/map combinations
        * Assuming there's a valid scene for the map, defaults to `e_useDefaultScenario` logic
* Team Swaps
    * A setting for enabling team swaps in ETV and FRD matches, when halftime is reached (if timelimit is set) or halfway to a roundlimit is reached (10 out of 20 rounds for a single team), pauses the game and swaps members of the teams, and begins again.