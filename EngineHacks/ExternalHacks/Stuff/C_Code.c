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

// 100 hit,
void ComputeBattleUnitEffectiveHitRate(struct BattleUnit* attacker, struct BattleUnit* defender) {
   if  (CheckFlag(HitFlag_Link)) {attacker->battleEffectiveHitRate = attacker->battleHitRate - defender->battleAvoidRate;}
   else
  { attacker->battleEffectiveHitRate = 100;}

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