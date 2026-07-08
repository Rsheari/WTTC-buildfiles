#include "C_Code.h"
//1/3, remove hit from wta, it already rigged to 100, why bother
void ComputeBattleUnitHitRate(struct BattleUnit* bu) {
   bu->battleHitRate = (bu->unit.skl * 2) + GetItemHit(bu->weapon) + (bu->unit.lck / 2);
 }
//2/3 add AS to WTA, repurposing wtrianglehitbonus
void ComputeBattleUnitSpeed(struct BattleUnit* bu)  {
    int effWt = GetItemWeight(bu->weaponBefore);

    effWt -= bu->unit.conBonus;
bu->battleSpeed = (bu->unit.spd * (100 + bu->wTriangleHitBonus) /100) - effWt;
} 
// 3/3 made might %
void ComputeBattleUnitAttack(struct BattleUnit* attacker, struct BattleUnit* defender) {
  
    attacker->battleAttack = (GetItemMight(attacker->weapon) * (100 + attacker->wTriangleDmgBonus)/100);

}

