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

---

## Notes/Ideas/Improvements

### Notes
* ETE did not have a Kevlar Helmet, we would need to add support in the scene files for this item
* All values with spaces must be surrounded with double quotes, though it's usually just a good idea to do it for all values except for integers

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
