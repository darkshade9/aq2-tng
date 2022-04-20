/* Stats Command */
void ResetStats(edict_t *ent);
void Stats_AddShot(edict_t *ent, int gun);
void Stats_AddHit(edict_t *ent, int gun, int hitPart);

void A_ScoreboardEndLevel (edict_t * ent, edict_t * killer);
void Cmd_Stats_f (edict_t *targetent, char *arg);
void Cmd_Statmode_f(edict_t *ent);

// Statlogs
#define MAXPRINTMSG     		4096
#define FS_MODE_APPEND          0x00000000
#define FS_MODE_READ            0x00000001
#define FS_MODE_WRITE           0x00000002
#define FS_FLAG_TEXT            0x00000400
#define FS_BUF_LINE             0x00000008
#define FS_BUF_NONE             0x0000000c
#define Q_isprint(c)    ((c) >= 32 && (c) < 127)
#define Q_isspace(c)    (c == ' ' || c == '\f' || c == '\n' || \
                         c == '\r' || c == '\t' || c == '\v')

typedef int qhandle_t;
size_t Q_vscnprintf(char *dest, size_t size, const char *fmt, va_list argptr);
qhandle_t FS_EasyOpenFile(char *buf, size_t size, unsigned mode,
                          const char *dir, const char *name, const char *ext);
cvar_t *Cvar_Set(const char *var_name, const char *value);
cvar_t *(*cvar_set)(const char *var_name, const char *value);

