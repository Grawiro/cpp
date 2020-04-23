enum SIGN { SGN_CIRCLE = 'O', SGN_CROSS = 'X' };
enum FIELD { FLD_EMPTY, FLD_CIRCLE = SGN_CIRCLE, FLD_CROSS = SGN_CROSS };
enum GAMESTATE { GS_NOTSTARTED, GS_MOVE, GS_WON, GS_DRAW };

bool StartGry ();
bool Ruch (unsigned);
bool RysujPlansze ();

extern GAMESTATE g_StanGry;