//-----------------------------------------------------------------------------
// Voting stuff
//
// $Id: a_vote.h,v 1.2 2001/09/28 13:48:34 ra Exp $
//
//-----------------------------------------------------------------------------
// $Log: a_vote.h,v $
// Revision 1.2  2001/09/28 13:48:34  ra
// I ran indent over the sources. All .c and .h files reindented.
//
// Revision 1.1.1.1  2001/05/06 17:24:24  igor_rock
// This is the PG Bund Edition V1.25 with all stuff laying around here...
//
//-----------------------------------------------------------------------------

//=== map voting ===========================================================
//==========================================================================

typedef struct votelist_s
{
  char *mapname;
  int num_votes;
  int num_allvotes;		// added by Igor[Rock]

  struct votelist_s *next;
}
votelist_t;

#define MAPMENUTITLE "Mapmenu"

void Cmd_Votemap_f (edict_t * ent, char *t);
void Cmd_Maplist_f (edict_t * ent, char *dummy);
void _MapInitClient (edict_t * ent);
void _RemoveVoteFromMap (edict_t * ent);
void _MapExitLevel (char *NextMap);
qboolean _CheckMapVotes (void);
void _MapWithMostVotes (void);
cvar_t *_InitMapVotelist (ini_t * ini);
void MapVoteMenu (edict_t * ent, pmenu_t * p);

//Igor[Rock] Begin
extern votelist_t *map_votes;
extern int map_num_maps;
//Igor[Rock] End


//=== kick voting ==========================================================
//==========================================================================

#define KICKMENUTITLE "Kickmenu"

cvar_t *_InitKickVote (ini_t * ini);
void _InitKickClient (edict_t * ent);
void _ClientKickDisconnect (edict_t * ent);
void _KickVoteSelected (edict_t * ent, pmenu_t * p);
void _CheckKickVote (void);
void Cmd_Votekick_f (edict_t * ent, char *argument);
void Cmd_Votekicknum_f (edict_t * ent, char *argument);
void Cmd_Kicklist_f (edict_t * ent, char *argument);

//=== player ignoring ======================================================
//==========================================================================

#define IGNOREMENUTITLE "Ignoremenu"
#define PG_MAXPLAYERS 11

typedef edict_t *ignorelist_t[PG_MAXPLAYERS];

void Cmd_Ignoreclear_f (edict_t * self, char *s);
void Cmd_Ignorelist_f (edict_t * self, char *s);
void Cmd_Ignorenum_f (edict_t * self, char *s);
void Cmd_Ignore_f (edict_t * self, char *s);
void _ClrIgnoresOn (edict_t * target);
int IsInIgnoreList (edict_t * source, edict_t * subject);
void _IgnoreVoteSelected (edict_t * ent, pmenu_t * p);
void _ClearIgnoreList (edict_t * ent);

//=== config voting ========================================================
//==========================================================================

typedef struct configlist_s
{
  char *configname;
  int num_votes;

  struct configlist_s *next;
}
configlist_t;

#define CONFIGMENUTITLE "Configmenu"

void Cmd_Voteconfig_f (edict_t * ent, char *t);
void Cmd_Configlist_f (edict_t * ent, char *dummy);
void _ConfigInitClient (edict_t * ent);
void _RemoveVoteFromConfig (edict_t * ent);
void _ConfigExitLevel (char *NextConfig);
qboolean _CheckConfigVotes (void);
void _ConfigWithMostVotes (void);
cvar_t *_InitConfiglist (ini_t * ini);
void ConfigVoteMenu (edict_t * ent, pmenu_t * p);

//Igor[Rock] Begin
extern configlist_t *config_votes;
extern int config_num_configs;
//Igor[Rock] End


//=== leave team ==========================================================
//==========================================================================

#define LEAVETEAMSTITLE "Leave Team"

void LeaveTeams (edict_t * ent, pmenu_t * p);
