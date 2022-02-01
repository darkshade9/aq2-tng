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

View scene files to get an understanding of the format

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
        * Reaching an escort point
        * Killing an enemy crewmember within X distance from Leader (harassing the bodyguard)
        * Capturing a capturepoint
        * Holding a capturepoint over an interval
    * New ways to score
        * Bonus points for Accuracy (triggered under the same conditions the announcer voiceover says "Accuracy!")
