/* Stats Command */
void ResetStats(edict_t *ent);
void Stats_AddShot(edict_t *ent, int gun);
void Stats_AddHit(edict_t *ent, int gun, int hitPart);

void A_ScoreboardEndLevel (edict_t * ent, edict_t * killer);
void Cmd_Stats_f (edict_t *targetent, char *arg);
void Cmd_Statmode_f(edict_t *ent);

// Statlogs
void Com_StatPrintf(const char *fmt, ...)
size_t Q_vscnprintf(char *dest, size_t size, const char *fmt, va_list argptr);
qhandle_t FS_EasyOpenFile(char *buf, size_t size, unsigned mode,
                          const char *dir, const char *name, const char *ext);
cvar_t *Cvar_Set(const char *var_name, const char *value);

cvar_t *(*cvar_set)(const char *var_name, const char *value);
