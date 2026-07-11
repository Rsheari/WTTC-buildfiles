#include "C_Code.h"
// FLags
extern int CritFlag_Link; 
extern int HitFlag_Link; 
// 0 dodge
void ComputeBattleUnitAvoidRate(struct BattleUnit * bu)
{
    if (CheckFlag(HitFlag_Link)) {bu->battleAvoidRate = 0; }
    else
    {bu->battleAvoidRate = (bu->battleSpeed * 2) + bu->terrainAvoid + (bu->unit.lck);}

    if (bu->battleAvoidRate < 0)
        bu->battleAvoidRate = 0;

     
}
// 100 hir
void ComputeBattleUnitHitRate(struct BattleUnit* bu) {
  
 if (CheckFlag(HitFlag_Link)) {bu->battleHitRate = 100;}
 else
 {bu->battleHitRate = (bu->unit.skl * 2) + GetItemHit(bu->weapon) + (bu->unit.lck / 2);}
 }

// 0 crit dodge

void ComputeBattleUnitDodgeRate(struct BattleUnit* bu) {
  if  (CheckFlag(CritFlag_Link))  {bu->battleDodgeRate = bu->unit.lck;}
 else  {bu->battleDodgeRate = 0;}
}
// 100 crit
void ComputeBattleUnitEffectiveCritRate(struct BattleUnit* attacker, struct BattleUnit* defender) {
  if  (CheckFlag(CritFlag_Link))  {attacker->battleEffectiveCritRate = attacker->battleCritRate - defender->battleDodgeRate;}
  else
  {attacker->battleEffectiveCritRate = 100 - defender->battleDodgeRate;}
}