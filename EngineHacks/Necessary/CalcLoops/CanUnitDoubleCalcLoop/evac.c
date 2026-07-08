struct BattleForecastProc {
    /* 00 */ PROC_HEADER;

    /* 2C */ int unk_2C;
    /* 30 */ s8 x;
    /* 31 */ s8 y;
    /* 32 */ u8 frameKind;
    /* 33 */ s8 ready;
    /* 34 */ s8 needContentUpdate;
    /* 35 */ s8 side; // -1 is left, +1 is right
    /* 36 */ s8 unk_36;
    /* 38 */ struct Text unitNameTextA;
    /* 40 */ struct Text unitNameTextB;
    /* 48 */ struct Text itemNameText;
    /* 50 */ s8 hitCountA;
    /* 51 */ s8 hitCountB;
    /* 52 */ s8 isEffectiveA;
    /* 53 */ s8 isEffectiveB;
};
void NewInitBattleForecastBattleStats(struct BattleForecastProc* proc); 

void NewInitBattleForecastBattleStats(struct BattleForecastProc* proc) {
    struct BattleUnit* buFirst;
    struct BattleUnit* buSecond;


    int usesA = GetItemUses(gBattleActor.weaponBefore);
    int usesB = GetItemUses(gBattleTarget.weaponBefore);

    s8 followUp = BattleGetFollowUpOrder(&buFirst, &buSecond);

    proc->hitCountA = 0;
    proc->isEffectiveA = 0;

    if ((gBattleActor.weapon != 0) || (gBattleActor.weaponBroke)) {
        BattleForecastHitCountUpdate(&gBattleActor, (u8*)&proc->hitCountA, &usesA);

        if ((followUp != 0) && (buFirst == &gBattleActor)) {
            BattleForecastHitCountUpdate(buFirst, (u8*)&proc->hitCountA, &usesA);
        }


        if (IsItemEffectiveAgainst(gBattleActor.weaponBefore, &gBattleTarget.unit) != 0) {
            proc->isEffectiveA = 1;
        }

        if ((gBattleActor.wTriangleHitBonus > 0) && (gBattleActor.weaponAttributes & IA_REVERTTRIANGLE) != 0) {
            proc->isEffectiveA = 1;
        }
    }

    proc->hitCountB = 0;
    proc->isEffectiveB = 0;

    if ((gBattleTarget.weapon != 0) || (gBattleTarget.weaponBroke)) {
        BattleForecastHitCountUpdate(&gBattleTarget, (u8*)&proc->hitCountB, &usesB);
        if ((followUp != 0) && (buFirst == &gBattleTarget)) {
            BattleForecastHitCountUpdate(buFirst, (u8*)&proc->hitCountB, &usesB);
        }
        if ((followUp == BothFollowUp)) { // added 
            BattleForecastHitCountUpdate(buSecond, (u8*)&proc->hitCountB, &usesB);
        }

        if (IsItemEffectiveAgainst(gBattleTarget.weaponBefore, &gBattleActor.unit) != 0) {
            proc->isEffectiveB = 1;
        }

        if ((gBattleTarget.wTriangleHitBonus > 0) && (gBattleTarget.weaponAttributes & IA_REVERTTRIANGLE) != 0) {
            proc->isEffectiveB = 1;
        }
    }

    return;
}


