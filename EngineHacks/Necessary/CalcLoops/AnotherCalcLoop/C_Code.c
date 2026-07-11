#include "C_Code.h"
//1/3, remove hit from wta, it already rigged to 100, why bother, so moved to stuff mk2

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

