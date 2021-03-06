|- ihcberutil.inc
|- Version 2.0
|- Updated: 4/25/2019
|--------------------------------------------------------------------------------------
|-Setup Variable Environment
|--------------------------------------------------------------------------------------
Sub BerSetup
 |-Create Alias's
 |-Toggles
	/squelch /alias /tglalliance 	/setvarint Toggle UseAlliance
	/squelch /alias /tglaoe			/setvarint Toggle UseAoE
	/squelch /alias /tglautoaxe		/setvarint Toggle AutoAxe
	/squelch /alias /tglautoaxe2	/setvarint Toggle AutoAxe2
	/squelch /alias /tglbp			/setvarint Toggle ChestCombatCast
	/squelch /alias /tglforce		/setvarint Toggle ForceAlliance
	/squelch /alias /tglintim		/setvarint Toggle UseIntimidate
	/squelch /alias /tglmezbreak	/setvarint Toggle AllowMezBreak
	/squelch /alias /tglopener		/setvarint Toggle UseOpener
	/squelch /alias /tglpet			/setvarint Toggle UsePet
	/squelch /alias /tglpoison		/setvarint Toggle UsePoisons	
 |-Declare AA's and Discs
	/declare endregen				string outer NULL
	/declare beraura				string outer NULL
	/declare DichoSpell				string outer NULL
	/declare Dfrenzy				string outer NULL
	/declare Dvolley				string outer NULL
	/declare Daxethrow				string outer NULL
	/declare Daxeof					string outer NULL
	/declare Phantom				string outer NULL
	/declare Alliance				string outer NULL
	/declare cheapshot				string outer NULL
	/declare AESlice				string outer NULL
	/declare AEVicious				string outer NULL
	/declare FrenzyBoost			string outer NULL
	/declare FrenzyBoostBuff		string outer NULL
	/declare RageStrike				string outer NULL
	/declare SharedBuff				string outer NULL
	/declare SharedBuffName			string outer NULL
	/declare PrimaryBurnDisc		string outer NULL
	/declare PrimaryBurnDiscID		int outer 0
	/declare CleavingDisc			string outer NULL
	/declare CleavingDiscID			int outer 0
	/declare FlurryDisc				string outer NULL
	/declare FlurryDiscID			int outer 0
	/declare DisconDisc				string outer NULL
	/declare DisconDiscID			int outer 0
	/declare ResolveDisc			string outer NULL
	/declare ResolveDiscID			int outer 0
	/declare HHEBuff				string outer NULL

 |-Config Options
	/call LoadCommonConfig
	/call LoadIni Combat AllowMezBreak		 	int 0
	/call LoadIni Combat DoBattleLeap			int 1
	/call LoadIni Combat ForceAlliance		 	int 0
	/call LoadIni Combat StickHow				string behind
	/call LoadIni Combat UseAlliance		 	int 1
	/call LoadIni Combat UseAoE			 		int 0
	/call LoadIni Combat UseIntimidate		 	int 1
	/call LoadIni Combat UseMelee		 		int 1
	/call LoadIni Combat UseOpener			 	int 1
	/call LoadIni Combat UsePet		 			int 1
	/call LoadIni Item ChestItemName			string NULL
	/call LoadIni Item ChestCombatCast			int 0
	/call LoadIni Item PoisonName				string NULL
	/call LoadIni Item PoisonBuffName			string NULL
	/call LoadIni Item UsePoisons		 		int 0
	/call LoadIni Options AutoAxe				int 0
	/call LoadIni Options AutoAxeCount			int 300
	/call LoadIni Options AutoAxeMin			int 60
	/call LoadIni Options AutoAxeName			string "Axe of the Demolisher"
	/call LoadIni Options AutoAxeComponents		string "Masterwork Axe Components"
	/call LoadIni Options AutoAxe2				int 0
	/call LoadIni Options AutoAxe2Count			int 300
	/call LoadIni Options AutoAxe2Min			int 60
	/call LoadIni Options AutoAxe2Name			string NULL
	/call LoadIni Options AutoAxe2Components	string NULL
	
	/declare ZerkerCount			int outer 1
	/declare epicaxe				string outer NULL
	/declare UseEpic				int outer 0
	/declare CastResult             string outer

 |- Check for epic
	/if (${FindItem[Raging Taelosian Alloy Axe].ID}) {
		/varset epicaxe		Raging Taelosian Alloy Axe
		/varset UseEpic 1
	} else /if (${FindItem[Vengeful Taelosian Blood Axe].ID}) {
		/varset epicaxe		Vengeful Taelosian Blood Axe
		/varset UseEpic 1
	}
	/if (${Me.AltAbility[962].Name.Find[disabled]} && ${Me.AltAbilityReady[962]}) {
		/alt act 962
		/delay 5
	}
/return 

|----------------------------------------------------------------------------
|- SUB: INIChanges
|---------------------------------------------------------------------------- 
Sub INIChanges
	/varset changetoini 0
	/call SaveCommonConfig
	/call SetIni Combat AllowMezBreak		int ${AllowMezBreak}
	/call SetIni Combat DoBattleLeap		int ${DoBattleLeap}
	/call SetIni Combat ForceAlliance		int ${ForceAlliance}
	/call SetIni Combat UseAlliance		 	int ${UseAlliance}
	/call SetIni Combat UseAoE			 	int ${UseAoE}
	/call SetIni Combat UseIntimidate		int ${UseIntimidate}
	/call SetIni Combat UseMelee		 	int ${UseMelee}
	/call SetIni Combat UseOpener			int ${UseOpener}
	/call SetIni Combat UsePet		 		int ${UsePet}
	/call SetIni Item ChestCombatCast		int ${ChestCombatCast}
	/call SetIni Item UsePoisons		 	int ${UsePoisons}
	/call SetIni Options AutoAxe			int ${AutoAxe}
	/call SetIni Options AutoAxe2			int ${AutoAxe2}
/return 

|----------------------------------------------------------------------------
|- SUB: SetupDiscs
|---------------------------------------------------------------------------- 
Sub SetupDiscs
 |---One off abilities
	/if (${Me.Level}>=100 && ${Me.CombatAbility[${Spell[Phantom Assailant].RankName}]}) /varset Phantom ${Spell[Phantom Assailant].RankName}
	/if (${Me.Level}>=102 && ${Me.CombatAbility[${Spell[Demolisher's Alliance].RankName}]}) /varset Alliance ${Spell[Demolisher's Alliance].RankName}
 |---Battle Cry - HHE Buff
	/if (${Me.Level}>=65 && ${Me.CombatAbility[Ancient Cry of Chaos]}) {
		/varset HHEBuff Ancient Cry of Chaos
	} else /if (${Me.Level}>=65 && ${Me.CombatAbility[Battle Cry of the Mastruq]}) {
		/varset HHEBuff Battle Cry of the Mastruq
	} else /if (${Me.Level}>=64 && ${Me.CombatAbility[War Cry of Dravel]}) {
		/varset HHEBuff War Cry of Dravel
	} else /if (${Me.Level}>=57 && ${Me.CombatAbility[Battle Cry of Dravel]}) {
		/varset HHEBuff Battle Cry of Dravel
	} else /if (${Me.Level}>=50 && ${Me.CombatAbility[War Cry]}) {
		/varset HHEBuff War Cry
	} else /if (${Me.Level}>=30 && ${Me.CombatAbility[Battle Cry]}) {
		/varset HHEBuff Battle Cry
	}
 |---Primary Burn Disc Setup - Expanded for lower level use
	/if (${Me.Level}>=100 && ${Me.CombatAbility[${Spell[Brutal Discipline].RankName}]}) {
		/varset PrimaryBurnDisc ${Spell[Brutal Discipline].RankName}
	} else /if (${Me.Level}>=95 && ${Me.CombatAbility[${Spell[Sundering Discipline].RankName}]}) {
		/varset PrimaryBurnDisc ${Spell[Sundering Discipline].RankName}
	} else /if (${Me.Level}>=75 && ${Me.CombatAbility[${Spell[Berserking Discipline].RankName}]}) {
		/varset PrimaryBurnDisc ${Spell[Berserking Discipline].RankName}
	}
	/if (${Me.CombatAbility[${PrimaryBurnDisc}]}) /varset PrimaryBurnDiscID ${Spell[${PrimaryBurnDisc}].ID}
 |---Cleaving Disc
	/if (${Me.Level}>=86 && ${Me.CombatAbility[${Spell[Cleaving Acrimony Discipline].RankName}]}) {
		/varset CleavingDisc ${Spell[Cleaving Acrimony Discipline].RankName}
	} else /if (${Me.Level}>=65 && ${Me.CombatAbility[${Spell[Cleaving Anger Discipline].RankName}]}) {
		/varset CleavingDisc ${Spell[Cleaving Anger Discipline].RankName}
	}
	/if (${Me.CombatAbility[${CleavingDisc}]}) /varset CleavingDiscID ${Spell[${CleavingDisc}].ID}
 |---Flurry Disc
	/if (${Me.Level}>=89 && ${Me.CombatAbility[${Spell[Avenging Flurry Discipline].RankName}]}) {
		/varset FlurryDisc ${Spell[Avenging Flurry Discipline].RankName}
	} else /if (${Me.Level}>=70 && ${Me.CombatAbility[${Spell[Vengeful Flurry Discipline].RankName}]}) {
		/varset FlurryDisc ${Spell[Vengeful Flurry Discipline].RankName}
	}
	/if (${Me.CombatAbility[${FlurryDisc}]}) /varset FlurryDiscID ${Spell[${FlurryDisc}].ID}
 |---Disconcerting
	/if (${Me.Level}>=104 && ${Me.CombatAbility[${Spell[Disconcerting Discipline].RankName}]}) {
		/varset DisconDisc ${Spell[Disconcerting Discipline].RankName}
		/varset DisconDiscID ${Spell[DisconDisc].ID}
	}
 |---Resolve Disc
	/if (${Me.Level}>=94 && ${Me.CombatAbility[${Spell[Frenzied Resolve Discipline].RankName}]}) {
		/varset ResolveDisc ${Spell[Frenzied Resolve Discipline].RankName}
		/varset ResolveDiscID ${Spell[ResolveDisc].ID}
	}
 |---Frenzy Boost - Updated for RoS and Expanded for lower level
	/if (${Me.Level}>=109 && ${Me.CombatAbility[${Spell[Bolstered Frenzy].RankName}]}) {
		/varset FrenzyBoost ${Spell[Bolstered Frenzy].RankName}
		/varset FrenzyBoostBuff Bolstered Frenzy Effect
	} else /if (${Me.Level}>=104 && ${Me.CombatAbility[${Spell[Amplified Frenzy].RankName}]}) {
		/varset FrenzyBoost ${Spell[Amplified Frenzy].RankName}
		/varset FrenzyBoostBuff Amplified Frenzy Effect
	} else /if (${Me.Level}>=99 && ${Me.CombatAbility[${Spell[Augmented Frenzy].RankName}]}) {
		/varset FrenzyBoost ${Spell[Augmented Frenzy].RankName}
		/varset FrenzyBoostBuff Augmented Frenzy Effect
	}
 |---SharedBuff - Updated for RoS and Expanded for lower level
	/if (${Me.Level}>=110 && ${Me.CombatAbility[${Spell[Shared Ruthlessness].RankName}]}) {
		/varset SharedBuff ${Spell[Shared Ruthlessness].RankName}
		/varset SharedBuffName Shared Ruthlessness
	} else /if (${Me.Level}>=105 && ${Me.CombatAbility[${Spell[Shared Cruelty].RankName}]}) {
		/varset SharedBuff ${Spell[Shared Cruelty].RankName}
		/varset SharedBuffName Shared Cruelty
	} else /if (${Me.Level}>=100 && ${Me.CombatAbility[${Spell[Shared Viciousness].RankName}]}) {
		/varset SharedBuff ${Spell[Shared Viciousness].RankName}
		/varset SharedBuffName Shared Viciousness
	} else /if (${Me.Level}>=95 && ${Me.CombatAbility[${Spell[Shared Savagery].RankName}]}) {
		/varset SharedBuff ${Spell[Shared Savagery].RankName}
		/varset SharedBuffName Shared Savagery
	} else /if (${Me.Level}>=90 && ${Me.CombatAbility[${Spell[Shared Brutality].RankName}]}) {
		/varset SharedBuff ${Spell[Shared Brutality].RankName}
		/varset SharedBuffName Shared Brutality
	} else /if (${Me.Level}>=85 && ${Me.CombatAbility[${Spell[Shared Bloodlust].RankName}]}) {
		/varset SharedBuff ${Spell[Shared Bloodlust].RankName}
		/varset SharedBuffName Shared Bloodlust
	}
 |---RageStrike - Updated for RoS and Expanded for lower level
	/if (${Me.Level}>=107 && ${Me.CombatAbility[${Spell[Smoldering Rage].RankName}]}) {
		/varset RageStrike ${Spell[Smoldering Rage].RankName}
	} else /if (${Me.Level}>=102 && ${Me.CombatAbility[${Spell[Bubbling Rage].RankName}]}) {
		/varset RageStrike ${Spell[Bubbling Rage].RankName}
	} else /if (${Me.Level}>=98 && ${Me.CombatAbility[${Spell[Festering Rage].RankName}]}) {
		/varset RageStrike ${Spell[Festering Rage].RankName}
	}
 |---Cheapshot ability EX: Kick in the shins - Updated for RoS
	/if (${Me.Level}>=107 && ${Me.CombatAbility[${Spell[Sucker Punch].RankName}]}) {
		/varset cheapshot ${Spell[Sucker Punch].RankName}
	} else /if (${Me.Level}>=102 && ${Me.CombatAbility[${Spell[Kick in the Shins].RankName}]}) {
		/varset cheapshot ${Spell[Kick in the Shins].RankName}
	} else /if (${Me.Level}>=97 && ${Me.CombatAbility[${Spell[Punch in the Throat].RankName}]}) {
		/varset cheapshot ${Spell[Punch in the Throat].RankName}
	} else /if (${Me.Level}>=92 && ${Me.CombatAbility[${Spell[Kick in the Teeth].RankName}]}) {
		/varset cheapshot ${Spell[Kick in the Teeth].RankName}
	} else /if (${Me.Level}>=87 && ${Me.CombatAbility[${Spell[Slap in the Face].RankName}]}) {
		/varset cheapshot ${Spell[Slap in the Face].RankName}
	}
 |---Dicho Spell*
	/if (${Me.Level}>=${Spell[Dissident Rage].Level} && ${Me.CombatAbility[${Spell[Dissident Rage].RankName}]}) {
		/varset DichoSpell ${Spell[Dissident Rage].RankName}
	} else /if (${Me.Level}>=${Spell[Dichotomic Rage].Level} && ${Me.CombatAbility[${Spell[Dichotomic Rage].RankName}]}) {
		/varset DichoSpell ${Spell[Dichotomic Rage].RankName}
	}
 |---Frenzy Combat Ability not normal Frenzy - Updated for RoS
	/if (${Me.Level}>=106 && ${Me.CombatAbility[${Spell[Mangling Frenzy].RankName}]}) {
		/varset Dfrenzy ${Spell[Mangling Frenzy].RankName}
	} else /if (${Me.Level}>=101 && ${Me.CombatAbility[${Spell[Demolishing Frenzy].RankName}]}) {
		/varset Dfrenzy ${Spell[Demolishing Frenzy].RankName}
	} else /if (${Me.Level}>=96 && ${Me.CombatAbility[${Spell[Vanquishing Frenzy].RankName}]}) {
		/varset Dfrenzy ${Spell[Vanquishing Frenzy].RankName}
	} else /if (${Me.Level}>=91 && ${Me.CombatAbility[${Spell[Conquering Frenzy].RankName}]}) {
		/varset Dfrenzy ${Spell[Conquering Frenzy].RankName}
	} else /if (${Me.Level}>=86 && ${Me.CombatAbility[${Spell[Overwhelming Frenzy].RankName}]}) {
		/varset Dfrenzy ${Spell[Overwhelming Frenzy].RankName}
	} else /if (${Me.Level}>=81 && ${Me.CombatAbility[${Spell[Overpowering Frenzy].RankName}]}) {
		/varset Dfrenzy ${Spell[Overpowering Frenzy].RankName}
	}
 |---Volley - Updated for RoS
	/if (${Me.Level}>=109 && ${Me.CombatAbility[${Spell[Mangling Volley].RankName}]}) {
		/varset Dvolley ${Spell[Mangling Volley].RankName}
	} else /if (${Me.Level}>=104 && ${Me.CombatAbility[${Spell[Demolishing Volley].RankName}]}) {
		/varset Dvolley ${Spell[Demolishing Volley].RankName}
	} else /if (${Me.Level}>=99 && ${Me.CombatAbility[${Spell[Brutal Volley].RankName}]}) {
		/varset Dvolley ${Spell[Brutal Volley].RankName}
	} else /if (${Me.Level}>=94 && ${Me.CombatAbility[${Spell[Sundering Volley].RankName}]}) {
		/varset Dvolley ${Spell[Sundering Volley].RankName}
	} else /if (${Me.Level}>=89 && ${Me.CombatAbility[${Spell[Savage Volley].RankName}]}) {
		/varset Dvolley ${Spell[Savage Volley].RankName}
	} else /if (${Me.Level}>=84 && ${Me.CombatAbility[${Spell[Eradicator's Volley].RankName}]}) {
		/varset Dvolley ${Spell[Eradicator's Volley].RankName}
	} else /if (${Me.Level}>=79 && ${Me.CombatAbility[${Spell[Decimator's Volley].RankName}]}) {
		/varset Dvolley ${Spell[Decimator's Volley].RankName}
	} else /if (${Me.Level}>=74 && ${Me.CombatAbility[${Spell[Annihilator's Volley].RankName}]}) {
		/varset Dvolley ${Spell[Annihilator's Volley].RankName}
	} else /if (${Me.Level}>=69 && ${Me.CombatAbility[${Spell[Destroyer's Volley].RankName}]}) {
		/varset Dvolley ${Spell[Destroyer's Volley].RankName}
	} else /if (${Me.Level}>=61 && ${Me.CombatAbility[${Spell[Rage Volley].RankName}]}) {
		/varset Dvolley ${Spell[Rage Volley].RankName}
	}
 |---Axe Throw - Updated for RoS
	/if (${Me.Level}>=108 && ${Me.CombatAbility[${Spell[Mangling Axe Throw].RankName}]}) {
		/varset Daxethrow ${Spell[Mangling Axe Throw].RankName}
	} else /if (${Me.Level}>=103 && ${Me.CombatAbility[${Spell[Demolishing Axe Throw].RankName}]}) {
		/varset Daxethrow ${Spell[Demolishing Axe Throw].RankName}
	} else /if (${Me.Level}>=98 && ${Me.CombatAbility[${Spell[Brutal Axe Throw].RankName}]}) {
		/varset Daxethrow ${Spell[Brutal Axe Throw].RankName}
	} else /if (${Me.Level}>=93 && ${Me.CombatAbility[${Spell[Spirited Axe Throw].RankName}]}) {
		/varset Daxethrow ${Spell[Spirited Axe Throw].RankName}
	} else /if (${Me.Level}>=88 && ${Me.CombatAbility[${Spell[Energetic Axe Throw].RankName}]}) {
		/varset Daxethrow ${Spell[Energetic Axe Throw].RankName}
	} else /if (${Me.Level}>=83 && ${Me.CombatAbility[${Spell[Vigorous Axe Throw].RankName}]}) {
		/varset Daxethrow ${Spell[Vigorous Axe Throw].RankName}
	}
 |---Axe of - No Update
	/if (${Me.Level}>=107 && ${Me.CombatAbility[${Spell[Axe of Empyr].RankName}]}) {
		/varset Daxeof ${Spell[Axe of Empyr].RankName}
	} else /if (${Me.Level}>=102 && ${Me.CombatAbility[${Spell[Axe of the Aeons].RankName}]}) {
		/varset Daxeof ${Spell[Axe of the Aeons].RankName}
	} else /if (${Me.Level}>=100 && ${Me.CombatAbility[${Spell[Axe of Zurel].RankName}]}) {
		/varset Daxeof ${Spell[Axe of Zurel].RankName}
	} else /if (${Me.Level}>=95 && ${Me.CombatAbility[${Spell[Axe of Illdaera].RankName}]}) {
		/varset Daxeof ${Spell[Axe of Illdaera].RankName}
	} else /if (${Me.Level}>=90 && ${Me.CombatAbility[${Spell[Axe of Graster].RankName}]}) {
		/varset Daxeof ${Spell[Axe of Graster].RankName}
	} else /if (${Me.Level}>=85 && ${Me.CombatAbility[${Spell[Axe of Rallos].RankName}]}) {
		/varset Daxeof ${Spell[Axe of Rallos].RankName}
	}
 |---AE Slice Attack - 4 targets or less DIRECTIONAL Range 40
	/if (${Me.Level}>=104 && ${Me.CombatAbility[${Spell[Arcslice].RankName}]}) {
		/varset AESlice ${Spell[Arcslice].RankName}
	} else /if (${Me.Level}>=99 && ${Me.CombatAbility[${Spell[Arcblade].RankName}]}) {
		/varset AESlice ${Spell[Arcblade].RankName}
	}
 |---AE Viscious Attack - Up to 12 targets Range 25
	/if (${Me.Level}>=107 && ${Me.CombatAbility[${Spell[Vicious Cycle].RankName}]}) {
		/varset AEVicious ${Spell[Vicious Cycle].RankName}
	} else /if (${Me.Level}>=102 && ${Me.CombatAbility[${Spell[Vicious Cyclone].RankName}]}) {
		/varset AEVicious ${Spell[Vicious Cyclone].RankName}
	} else /if (${Me.Level}>=97 && ${Me.CombatAbility[${Spell[Vicious Spiral].RankName}]}) {
		/varset AEVicious ${Spell[Vicious Spiral].RankName}
	}
 |---Fast Endurance regen - No Update
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
 |---Aura Set up	
	/if (${Me.Level}>=70 && ${Me.CombatAbility[${Spell[Bloodlust Aura].RankName}]}) {
		/varset beraura ${Spell[Bloodlust Aura].RankName}
	} else /if (${Me.Level}>=55 && ${Me.CombatAbility[${Spell[Aura of Rage].RankName}]}) {
		/varset beraura ${Spell[Aura of Rage].RankName}
	}
/return

|----------------------------------------------------------------------------
|-SUB: Bind Change Var Int resets various interger settings from ini file
|----------------------------------------------------------------------------
Sub Bind_SetVarInt(string ISection, string IName, int IVar)
	/docommand /varset changetoini 1
 |-Toggles
		/if (${ISection.Equal[Toggle]}) {
 |--Pet
			/if (${IName.Equal[UsePet]}) {
				/if (!${UsePet}) {
					/echo \aw Setting UsePet to \ag ON
					/varset UsePet 1
				} else {
					/echo \aw Resetting UsePet to \ar OFF
					/varset UsePet 0
			}
 |--Alliance
		} else /if (${IName.Equal[UseAlliance]}) {
			/if (!${UseAlliance}) {
				/echo \aw Setting UseAlliance to \ag ON
				/varset UseAlliance 1
				/call AllianceCheck
			} else {
				/echo \aw Resetting UseAlliance to \ar OFF
				/varset UseAlliance 0
			}
 |--Opener
		} else /if (${IName.Equal[UseOpener]}) {
			/if (!${UseOpener}) {
				/echo \aw Setting UseOpener to \ag ON
				/varset UseOpener 1
			} else {
				/echo \aw Resetting UseOpener to \ar OFF
				/varset UseOpener 0
			}
 |--LootOn
		| } else /if (${IName.Equal[LootOn]}) {
			| /if (!${LootOn}) {
				| /echo \aw Setting LootOn to \ag ON
				| /varset LootOn 1
			| } else {
				| /echo \aw Resetting LootOn to \ar OFF
				| /varset LootOn 0
			| }
 |--Intimidate
		} else /if (${IName.Equal[UseIntimidate]}) {
			/if (!${UseIntimidate}) {
				/echo \aw Setting UseIntimidate to \ag ON
				/varset UseIntimidate 1
			} else {
				/echo \aw Resetting UseIntimidate to \ar OFF
				/varset UseIntimidate 0
			}
 |--Allow MezBreak
		} else /if (${IName.Equal[AllowMezBreak]}) {
			/if (!${AllowMezBreak}) {
				/echo \aw Setting AllowMezBreak to \ag ON
				/varset AllowMezBreak 1
			} else {
				/echo \aw Resetting AllowMezBreak to \ar OFF
				/varset AllowMezBreak 0
			}
 |--Force Alliance
		} else /if (${IName.Equal[ForceAlliance]}) {
			/if (!${ForceAlliance}) {
				/echo \aw Setting ForceAlliance to \ag ON
				/varset ForceAlliance 1
			} else {
				/echo \aw Resetting ForceAlliance to \ar OFF
				/varset ForceAlliance 0
			}
 |--UseAoE
		} else /if (${IName.Equal[UseAoE]}) {
			/if (!${UseAoE}) {
				/echo \aw Setting UseAoE to \ag ON
				/varset UseAoE 1
			} else {
				/echo \aw Resetting UseAoE to \ar OFF
				/varset UseAoE 0
			}
 |--AutoAxe
		} else /if (${IName.Equal[AutoAxe]}) {
			/if (!${AutoAxe}) {
				/echo \aw Setting AutoAxe to \ag ON
				/varset AutoAxe 1
			} else {
				/echo \aw Resetting AutoAxe to \ar OFF
				/varset AutoAxe 0
			}
 |--Chest Combat Cast
		} else /if (${IName.Equal[ChestCombatCast]}) {
			/if (!${ChestCombatCast}) {
				/echo \aw Setting ChestCombatCast to \ag ON
				/varset ChestCombatCast 1
			} else {
				/echo \aw Resetting ChestCombatCast to \ar OFF
				/varset ChestCombatCast 0
			}
 |--Use Poisons
		} else /if (${IName.Equal[UsePoisons]}) {
			/if (!${UsePoisons}) {
				/echo \aw Setting UsePoisons to \ag ON
				/varset UsePoisons 1
			} else {
				/echo \aw Resetting UsePoisons to \ar OFF
				/varset UsePoisons 0
			}
		}
	}
/return

|----------------------------------------------------------------------------
|-SUB: BIND CmdList - 
|----------------------------------------------------------------------------
Sub Bind_CmdList
	/call CommonHelp
	/echo \ag===${MacroName} Commands=== 
	/echo \ag/tglalliance\aw - Use ber alliance? there still needs to be >=3 zerkers for it to fire
	/echo \ag/tglaoe\aw - Turn the use of AE abilities on/off
	/echo \ag/tglautoaxe\aw - Turn the Auto Axe summoning feature on/off
	/echo \ag/tglautoaxe2\aw - Turn the Auto Axe 2 summoning feature on/off
	/echo \ag/tglbp\aw - Turn on/off the use of a Chest piece defined in the ini
	/echo \ag/tglforce\aw - Force Alliance Use. Use when other Zerkers are present but not in the same group 
	/echo \ag/tglintim\aw - Use Intimidation skill?
	/echo \ag/tglloot\aw - Turn auto looting on/off
	/echo \ag/tglmezbreak\aw - Allow attacking mez'd mobs if below assistat % - Ignores waiting for MA
	/echo \ag/tglopener\aw - Toggle ${cheapshot} ability ON/OFF
	/echo \ag/tglpet\aw - Pet toggle...cause sometimes they arent allowed
	/echo \ag/tglpoison\aw - Turn on/off the use of poison buffs
/return 