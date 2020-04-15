Sub RogSetup
	|-Config Options
	/call LoadCommonConfig
	/declare CastResult             string outer	
	/call LoadIni Combat StickHow		string "snaproll !front 10 moveback uw"
	/call LoadIni Combat AllowMezBreak		 	int 0
	/call LoadIni Combat UseMelee		int 1
	/call LoadIni Combat UseOpener		int 1
	/call LoadIni Options DoAutoBag		int 1
	/call LoadIni Options DoBuffs		int 1
	/call LoadIni Options UseHideSneak		int 1
	| Poison buffage
	/call LoadIni Item ChestItemName			string "${Me.Inventory[17].Name}"
	/call LoadIni Item ChestCombatCast			int 0
	/call LoadIni Item PoisonClicky string "${Me.Inventory[18].Name}"
	/call LoadIni Item PoisonName				string "Consigned Bite of the Shissar XIX"
	/call LoadIni Item PoisonBuffName			string "Bite of the Shissar Poison"
	/call LoadIni Item UsePoisons		 		int 1 
	/call LoadIni Item ChestItemName string "${Me.Inventory[17].Name}"

    | Whenever: Conditioned Reflexes 
    /declare ConditionedReflexes string outer NULL 
	/if (${Me.Level}>=97 && ${Me.CombatAbility[${Spell[Conditioned Reflexes].RankName}]}) {
		/varset ConditionedReflexes ${Spell[Conditioned Reflexes].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set ConditionedReflexes as ${ConditionedReflexes}
    
	| Whenever: Thief's vision
    /declare Vision string outer NULL
	/declare VisionTimer timer outer 60s
	/if (${Me.Level}>=96 && ${Me.CombatAbility[${Spell[Thief's Vision].RankName}]}) {
		/varset Vision ${Spell[Thief's Vision].RankName}
	} else /if (${Me.Level}>=68 && ${Me.CombatAbility[${Spell[Thief's Eyes].RankName}]}) {
		/varset Vision ${Spell[Thief's Eyes].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set Vision as ${Vision}

    | Whenever: Shadow Hunter's Dagger
    /declare Shadowhunter string outer NULL 
	/if (${Me.Level}>=102 && ${Me.CombatAbility[${Spell[Shadow-Hunter's Dagger].RankName}]}) {
		/varset Shadowhunter ${Spell[Shadow-Hunter's Dagger].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set Shadowhunter as ${Shadowhunter}

    |Timer 1: Slice
    /declare Slice string outer NULL 
	/if (${Me.Level}>=113 && ${Me.CombatAbility[${Spell[Slash].RankName}]}) {
		/varset Slice ${Spell[Slash].RankName}
	} else /if (${Me.Level}>=108 && ${Me.CombatAbility[${Spell[Slice].RankName}]}) {
		/varset Slice ${Spell[Slice].RankName}
	} else /if (${Me.Level}>=103 && ${Me.CombatAbility[${Spell[Hack].RankName}]}) {
		/varset Slice ${Spell[Hack].RankName}
	} else /if (${Me.Level}>=98 && ${Me.CombatAbility[${Spell[Gash].RankName}]}) {
		/varset Slice ${Spell[Gash].RankName}
	} else /if (${Me.Level}>=93 && ${Me.CombatAbility[${Spell[Lacerate].RankName}]}) {
		/varset Slice ${Spell[Lacerate].RankName}
	} else /if (${Me.Level}>=88 && ${Me.CombatAbility[${Spell[Wound].RankName}]}) {
		/varset Slice ${Spell[Wound].RankName}
	} else /if (${Me.Level}>=83 && ${Me.CombatAbility[${Spell[Bleed].RankName}]}) {
		/varset Slice ${Spell[Bleed].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set Slice as ${Slice}

    |Timer 3 Executioner
    /declare Executioner string outer NULL 
	/if (${Me.Level}>=100 && ${Me.CombatAbility[${Spell[Executioner Discipline].RankName}]}) {
		/varset Executioner ${Spell[Executioner Discipline].RankName}
	} else /if (${Me.Level}>=95 && ${Me.CombatAbility[${Spell[Eradicator's Discipline].RankName}]}) {
		/varset Executioner ${Spell[Eradicator's Discipline].RankName}
	} else /if (${Me.Level}>=75 && ${Me.CombatAbility[${Spell[Assassin Discipline].RankName}]}) {
		/varset Executioner ${Spell[Assassin Discipline].RankName}
	} else /if (${Me.Level}>=59 && ${Me.CombatAbility[${Spell[Duelist Discipline].RankName}]}) {
		/varset Executioner ${Spell[Duelist Discipline].RankName}
	} else /if (${Me.Level}>=57 && ${Me.CombatAbility[${Spell[Kinesthetics Discipline].RankName}]}) {
		/varset Executioner ${Spell[Kinesthetics Discipline].RankName}
	} 
	/if (${DebugAll}) DEBUGROG Set Executioner as ${Executioner}

   |Timer 4 Twisted
    /declare Twisted string outer NULL 
	/if (${Me.Level}>=65 && ${Me.CombatAbility[${Spell[Twisted Chance Discipline].RankName}]}) {
		/varset Twisted ${Spell[Twisted Chance Discipline].RankName}
	} else /if (${Me.Level}>=54 && ${Me.CombatAbility[${Spell[Deadeye Discipline].RankName}]}) {
		/varset Twisted ${Spell[Deadeye Discipline].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set Twisted as ${Twisted}

    | Timer5 - ProcBuff

    /declare ProcBuff string outer NULL 
	/if (${Me.Level}>=97 && ${Me.CombatAbility[${Spell[Weapon Covenant].RankName}]}) {
		/varset ProcBuff ${Spell[Weapon Covenant].RankName}
	} else /if (${Me.Level}>=92 && ${Me.CombatAbility[${Spell[Weapon Bond].RankName}]}) {
		/varset ProcBuff ${Spell[Weapon Bond].RankName}
	} else /if (${Me.Level}>=87 && ${Me.CombatAbility[${Spell[Weapon Affiliation].RankName}]}) {
		/varset ProcBuff ${Spell[Weapon Affiliation].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set ProcBuff as ${ProcBuff}

    | Timer6 Frenzied
    /declare Frenzied string outer NULL 
	/if (${Me.Level}>=70 && ${Me.CombatAbility[${Spell[Frenzied Stabbing Discipline].RankName}]}) {
		/varset Frenzied ${Spell[Frenzied Stabbing Discipline].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set Frenzied as ${Frenzied}

    |Timer 7 Ambush
    /declare Ambush string outer NULL
    /declare AmbushMaxLevel int outer 0
	/if (${Me.Level}>=111 && ${Me.CombatAbility[${Spell[Bushwack].RankName}]}) {
		/varset Ambush ${Spell[Bushwack].RankName}
        /varset AmbushMaxLevel 115
	} else /if (${Me.Level}>=106 && ${Me.CombatAbility[${Spell[Lie in Wait].RankName}]}) {
		/varset Ambush ${Spell[Lie in Wait].RankName}
        /varset AmbushMaxLevel 110
	} else /if (${Me.Level}>=101 && ${Me.CombatAbility[${Spell[Surprise Attack].RankName}]}) {
		/varset Ambush ${Spell[Surprise Attack].RankName}
        /varset AmbushMaxLevel 105
	} else /if (${Me.Level}>=96 && ${Me.CombatAbility[${Spell[Beset].RankName}]}) {
		/varset Ambush ${Spell[Beset].RankName}
        /varset AmbushMaxLevel 100
	} else /if (${Me.Level}>=91 && ${Me.CombatAbility[${Spell[Accost].RankName}]}) {
		/varset Ambush ${Spell[Accost].RankName}
        /varset AmbushMaxLevel 95
	} else /if (${Me.Level}>=86 && ${Me.CombatAbility[${Spell[Assail].RankName}]}) {
		/varset Ambush ${Spell[Assail].RankName}
        /varset AmbushMaxLevel 90
	} else /if (${Me.Level}>=81 && ${Me.CombatAbility[${Spell[Ambush].RankName}]}) {
		/varset Ambush ${Spell[Ambush].RankName}
        /varset AmbushMaxLevel 85
	} else /if (${Me.Level}>=81 && ${Me.CombatAbility[${Spell[Waylay].RankName}]}) {
		/varset Ambush ${Spell[Waylay].RankName}
        /varset AmbushMaxLevel 80
	}
	/if (${DebugAll}) DEBUGROG Set Ambush as ${Ambush}

    |Timer 8 DrachnidBlade   
    /declare DrachnidBlade string outer NULL 
	/if (${Me.Level}>=113 && ${Me.CombatAbility[${Spell[Drachnid Blade].RankName}]}) {
		/varset DrachnidBlade ${Spell[Drachnid Blade].RankName}
	} else /if (${Me.Level}>=108 && ${Me.CombatAbility[${Spell[Skorpikis Blade].RankName}]}) {
		/varset DrachnidBlade ${Spell[Skorpikis Blade].RankName}
	} else /if (${Me.Level}>=103 && ${Me.CombatAbility[${Spell[Reefcrawler Blade].RankName}]}) {
		/varset DrachnidBlade ${Spell[Reefcrawler Blade].RankName}
	} else /if (${Me.Level}>=98 && ${Me.CombatAbility[${Spell[Asp Blade].RankName}]}) {
		/varset DrachnidBlade ${Spell[Asp Blade].RankName}
	} else /if (${Me.Level}>=93 && ${Me.CombatAbility[${Spell[Toxic Blade].RankName}]}) {
		/varset DrachnidBlade ${Spell[Toxic Blade].RankName}
	} 
	/if (${DebugAll}) DEBUGROG Set DrachnidBlade as ${DrachnidBlade}

    |Timer 9 Fellstrike
    /declare FellStrike string outer NULL 
	/if (${Me.Level}>=115 && ${Me.CombatAbility[${Spell[Blitzstrike].RankName}]}) {
		/varset FellStrike ${Spell[Blitzstrike].RankName}
	} else /if (${Me.Level}>=110 && ${Me.CombatAbility[${Spell[Fellstrike].RankName}]}) {
		/varset FellStrike ${Spell[Fellstrike].RankName}
	} else /if (${Me.Level}>=105 && ${Me.CombatAbility[${Spell[Barrage].RankName}]}) {
		/varset FellStrike ${Spell[Barrage].RankName}
	} else /if (${Me.Level}>=100 && ${Me.CombatAbility[${Spell[Incursion].RankName}]}) {
		/varset FellStrike ${Spell[Incursion].RankName}
	} else /if (${Me.Level}>=95 && ${Me.CombatAbility[${Spell[Onslaught].RankName}]}) {
		/varset FellStrike ${Spell[Onslaught].RankName}
	} else /if (${Me.Level}>=90 && ${Me.CombatAbility[${Spell[Battery].RankName}]}) {
		/varset FellStrike ${Spell[Battery].RankName}
	} else /if (${Me.Level}>=85 && ${Me.CombatAbility[${Spell[Assault].RankName}]}) {
		/varset FellStrike ${Spell[Assault].RankName}
	} else /if (${Me.Level}>=5 && ${Me.CombatAbility[${Spell[Elbow Strike].RankName}]}) {
		/varset FellStrike ${Spell[Elbow Strike].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set FellStrike as ${FellStrike}

    | Timer10 Pinpoint
    /declare Pinpoint string outer NULL 
	/if (${Me.Level}>=114 && ${Me.CombatAbility[${Spell[Pinpoint Defects].RankName}]}) {
		/varset Pinpoint ${Spell[Pinpoint Defects].RankName}
	} else /if (${Me.Level}>=109 && ${Me.CombatAbility[${Spell[Pinpoint Shortcomings].RankName}]}) {
		/varset Pinpoint ${Spell[Pinpoint Shortcomings].RankName}
	} else /if (${Me.Level}>=99 && ${Me.CombatAbility[${Spell[Pinpoint Deficiencies].RankName}]}) {
		/varset Pinpoint ${Spell[Pinpoint Deficiencies].RankName}
	} else /if (${Me.Level}>=94 && ${Me.CombatAbility[${Spell[Pinpoint Liabilities].RankName}]}) {
		/varset Pinpoint ${Spell[Pinpoint Liabilities].RankName}
	} else /if (${Me.Level}>=89 && ${Me.CombatAbility[${Spell[Pinpoint Flaws].RankName}]}) {
		/varset Pinpoint ${Spell[Pinpoint Flaws].RankName}
	} else /if (${Me.Level}>=84 && ${Me.CombatAbility[${Spell[Pinpoint Vitals].RankName}]}) {
		/varset Pinpoint ${Spell[Pinpoint Vitals].RankName}
	} else /if (${Me.Level}>=79 && ${Me.CombatAbility[${Spell[Pinpoint Weaknesses].RankName}]}) {
		/varset Pinpoint ${Spell[Pinpoint Weaknesses].RankName}
	} else /if (${Me.Level}>=74 && ${Me.CombatAbility[${Spell[Pinpoint Vulnerability].RankName}]}) {
		/varset Pinpoint ${Spell[Pinpoint Vulnerability].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set Pinpoint as ${Pinpoint}

    | Timer 12 Puncture
    /declare Puncture string outer NULL 
	/if (${Me.Level}>=109 && ${Me.CombatAbility[${Spell[Vexatious Puncture].RankName}]}) {
		/varset Puncture ${Spell[Vexatious Puncture].RankName}
	} else /if (${Me.Level}>=104 && ${Me.CombatAbility[${Spell[Disassociative Puncture].RankName}]}) {
		/varset Puncture ${Spell[Disassociative Puncture].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set Puncture as ${Puncture}

	| Timer13 Breather
    | nb I use the lower case naming scheme as it's used in generic includes.
    /declare endregen string outer NULL 
	/if (${Me.Level}>=101 && ${Me.CombatAbility[${Spell[Breather].RankName}]}) {
		/varset endregen ${Spell[Breather].RankName}
	} else /if (${Me.Level}>=96 && ${Me.CombatAbility[${Spell[Rest].RankName}]}) {
		/varset endregen ${Spell[Rest].RankName}
	} else /if (${Me.Level}>=91 && ${Me.CombatAbility[${Spell[Reprieve].RankName}]}) {
		/varset endregen ${Spell[Reprieve].RankName}
	} else /if (${Me.Level}>=86 && ${Me.CombatAbility[${Spell[Respite].RankName}]}) {
		/varset endregen ${Spell[Respite].RankName}
	} else /if (${Me.Level}>=82 && ${Me.CombatAbility[${Spell[Fourth Wind].RankName}]}) {
		/varset endregen ${Spell[Fourth Wind].RankName}
	} else /if (${Me.Level}>=77 && ${Me.CombatAbility[${Spell[Third Wind].RankName}]}) {
		/varset endregen ${Spell[Third Wind].RankName}
	} else /if (${Me.Level}>=72 && ${Me.CombatAbility[${Spell[Second Wind].RankName}]}) {
		/varset endregen ${Spell[Second Wind].RankName}
	}
    /if (${DebugAll}) DEBUGROG Set endregen as ${endregen}

    | Timer 14 EdgeDisc
    /declare EdgeDisc string outer NULL 
	/if (${Me.Level}>=107 && ${Me.CombatAbility[${Spell[Ragged Edge Discipline].RankName}]}) {
		/varset EdgeDisc ${Spell[Ragged Edge Discipline].RankName}
	} else /if (${Me.Level}>=92 && ${Me.CombatAbility[${Spell[Razor's Edge Discipline].RankName}]}) {
		/varset EdgeDisc ${Spell[Razor's Edge Discipline].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set EdgeDisc as ${EdgeDisc}

    |Timer 15:AspDisc
    /declare AspDisc string outer NULL 
	/if (${Me.Level}>=114 && ${Me.CombatAbility[${Spell[Chelicerae Discipline].RankName}]}) {
		/varset AspDisc ${Spell[Chelicerae Discipline].RankName}
	} else /if (${Me.Level}>=109 && ${Me.CombatAbility[${Spell[Aculeus Discipline].RankName}]}) {
		/varset AspDisc ${Spell[Aculeus Discipline].RankName}
	} else /if (${Me.Level}>=104 && ${Me.CombatAbility[${Spell[Arcwork Discipline].RankName}]}) {
		/varset AspDisc ${Spell[Arcwork Discipline].RankName}
	} else /if (${Me.Level}>=99 && ${Me.CombatAbility[${Spell[Aspbleeder Discipline].RankName}]}) {
		/varset AspDisc ${Spell[Aspbleeder Discipline].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set AspDisc as ${AspDisc}

    | //Aim - Timer 16:
    | Level 98 "Knifeplay Discipline"
    | Level 68 "Deadly Aim Discipline"
    /declare AimDisc string outer NULL 
	/if (${Me.Level}>=98 && ${Me.CombatAbility[${Spell[Knifeplay Discipline].RankName}]}) {
		/varset AimDisc ${Spell[Knifeplay Discipline].RankName}
	} else /if (${Me.Level}>=68 && ${Me.CombatAbility[${Spell[Deadly Aim  Discipline].RankName}]}) {
		/varset AimDisc ${Spell[Deadly Aim  Discipline].RankName}
	} 
	/if (${DebugAll}) DEBUGROG Set AimDisc as ${AimDisc}

    | //Mark - Timer 17:
    | Level ??? "Naive Mark" (ToV)
    | Level 106 "Dim-Witted Mark"
    | Level 101 "Wide-Eyed Mark"
    | Level 96 "Gullible Mark"
    | Level 91 "Simple Mark"
    | Level 86 "Easy Mark"
	/declare MarkDisc string outer NULL
    /if (${Me.Level}>=111 && ${Me.CombatAbility[${Spell[Naive Mark].RankName}]}) {
		/varset MarkDisc ${Spell[Naive Mark].RankName}
	} else /if (${Me.Level}>=106 && ${Me.CombatAbility[${Spell[Dim-Witted Mark].RankName}]}) {
		/varset MarkDisc ${Spell[Dim-Witted Mark].RankName}
	} else /if (${Me.Level}>=101 && ${Me.CombatAbility[${Spell[Wide-Eyed  Mark].RankName}]}) {
		/varset MarkDisc ${Spell[Wide-Eyed  Mark].RankName}
	} else /if (${Me.Level}>=96 && ${Me.CombatAbility[${Spell[Gullible Mark].RankName}]}) {
		/varset MarkDisc ${Spell[Gullible Mark].RankName}
	} else /if (${Me.Level}>=91 && ${Me.CombatAbility[${Spell[Simple Mark].RankName}]}) {
		/varset MarkDisc ${Spell[Simple Mark].RankName}
	} else /if (${Me.Level}>=86 && ${Me.CombatAbility[${Spell[Easy Mark].RankName}]}) {
		/varset MarkDisc ${Spell[Easy Mark].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set MarkDisc as ${MarkDisc}

	| Timer 18 Jugular
	/declare Jugular string outer NULL
    /if (${Me.Level}>=112 && ${Me.CombatAbility[${Spell[Jugular Cut].RankName}]}) {
		/varset Jugular ${Spell[Jugular Cut].RankName}
	} else /if (${Me.Level}>=107 && ${Me.CombatAbility[${Spell[Jugular Strike].RankName}]}) {
		/varset Jugular ${Spell[Jugular Strike].RankName}
	} else /if (${Me.Level}>=102 && ${Me.CombatAbility[${Spell[Jugular Hack].RankName}]}) {
		/varset Jugular ${Spell[Jugular Hack].RankName}
	}  else /if (${Me.Level}>=97 && ${Me.CombatAbility[${Spell[Jugular Lacerate].RankName}]}) {
		/varset Jugular ${Spell[Jugular Lacerate].RankName}
	}  else /if (${Me.Level}>=92 && ${Me.CombatAbility[${Spell[Jugular Gash].RankName}]}) {
		/varset Jugular ${Spell[Jugular Gash].RankName}
	} else /if (${Me.Level}>=87 && ${Me.CombatAbility[${Spell[Jugular Sever].RankName}]}) {
		/varset Jugular ${Spell[Jugular Sever].RankName}
	} 
	/if (${DebugAll}) DEBUGROG Set Jugular as ${Jugular}

    |Timer19 Phantom
	/declare Phantom string outer NULL
    /if (${Me.Level}>=100 && ${Me.CombatAbility[${Spell[Phantom Assassin].RankName}]}) {
		/varset Phantom ${Spell[Phantom Assassin].RankName}
	} 
	/if (${DebugAll}) DEBUGROG Set Phantom as ${Phantom}

    | Timer20 SecretBlade
  	/declare SecretBlade string outer NULL
    /if (${Me.Level}>=109 && ${Me.CombatAbility[${Spell[Secret Blade].RankName}]}) {
		/varset SecretBlade ${Spell[Secret Blade].RankName}
	} else /if (${Me.Level}>=101 && ${Me.CombatAbility[${Spell[Hidden Blade].RankName}]}) {
		/varset SecretBlade ${Spell[Hidden Blade].RankName}
	} else /if (${Me.Level}>=101 && ${Me.CombatAbility[${Spell[Holdout Blade].RankName}]}) {
		/varset SecretBlade ${Spell[Holdout Blade].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set SecretBlade as ${SecretBlade}

    | Timer21- Alliance (not using)
    | Level 108 "Poisonous Covenant"
    | Level 102 "Poisonous Alliance"

    | Timer22 = Dicho   
    /declare DichoSpell string outer NULL
    /if (${Me.Level}>=106 && ${Me.CombatAbility[${Spell[Dissident Weapons].RankName}]}) {
		/varset DichoSpell ${Spell[Dissident Weapons].RankName}
	} else /if (${Me.Level}>=101 && ${Me.CombatAbility[${Spell[Dichotomic Weapons].RankName}]}) {
		/varset DichoSpell ${Spell[Dichotomic Weapons].RankName}
	}
	/if (${DebugAll}) DEBUGROG Set DichoSpell as ${DichoSpell}

	| UseEpic
	/declare UseEpic int outer 0 
	/declare EpicWeapon string outer NULL
	/if (${FindItem[Nightshade, Blade of Entropy].ID}) {
		/varset EpicWeapon Nightshade, Blade of Entropy
		/if (${DebugAll}) DEBUGROG Using ${EpicWeapon} for its clicky  \agLine#: ${Macro.CurLine}
	} else /if (${FindItem[Fatestealer].ID}) {
		/varset EpicWeapon Fatestealer
		/if (${DebugAll}) DEBUGROG Using ${EpicWeapon} for its clicky  \agLine#: ${Macro.CurLine}
	} else {
		/if (${DebugAll}) DEBUGROG Turning off UseEpic as I can't find one! \agLine#: ${Macro.CurLine}
		/varset UseEpic 0
	}
/return 

| Stolen from Ranger. We would have different.
Sub ClassAliasSetup
|-Create Class Aliases 
	|-- Toggles
	/squelch /alias /tglbp			/togglevariable ChestCombatCast
	/squelch /alias /tglpoison		/togglevariable UsePoisons
	/squelch /alias /tglmezbreak	/togglevariable AllowMezBreak
	/squelch /alias /tgldebugall    /togglevariable DebugAll
	/squelch /alias /tgldebugdps    /togglevariable DebugDps
	/call AliasSetup
	/call SetIni General IHCMacVersion			string ${IHCVersion}
/return

|----------------------------------------------------------------------------
|- SUB: INIChanges
|---------------------------------------------------------------------------- 
Sub INIChanges
	/varset changetoini 0
	/call SaveCommonConfig
	/call SetIni Combat AllowMezBreak		int ${AllowMezBreak}
	/call SetIni Combat UseMelee		 	int ${UseMelee}
	/call SetIni Combat UseOpener			int ${UseOpener}
	/call SetIni Item ChestCombatCast		int ${ChestCombatCast}
	/call SetIni Item UsePoisons		 	int ${UsePoisons}
/return 