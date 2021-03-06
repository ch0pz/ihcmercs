|- ihcwizutil.inc
|- Version 2.0
|- Updated: 4/25/2019
|- Thanks to Saar for additions and bug fixes
|--------------------------------------------------------------------------------------
|-Setup Variable Environment & Declares, Aliases
|--------------------------------------------------------------------------------------
Sub WizSetup
 |--------------------------------------------------------------------------------------
 |-Toggle switches toggling on/off modes from INI files
 |--------------------------------------------------------------------------------------
	/squelch /alias /tglalliance	/setvarint Toggle UseAlliance
	/squelch /alias /tglaoe			/setvarint Toggle UseAoE
	/squelch /alias /tglbp			/setvarint Toggle ChestCombatCast
	/squelch /alias /tgldicho		/setvarint Toggle UseDicho
	/squelch /alias /tglmanaburn	/setvarint Toggle UseManaBurn
	/squelch /alias /tgldps			/setvarint Toggle DoDPS
	/squelch /alias /tglevac		/setvarint Toggle EmergencyEvac
	/squelch /alias /tglmezbreak	/setvarint Toggle AllowMezBreak
	/squelch /alias /tglpet			/setvarint Toggle UsePet
	/squelch /alias /tglstrip		/setvarint Toggle StripBuffs
	/squelch /alias /tglweave		/setvarint Toggle WeaveAANukes
	| /squelch /alias /byos			/setvarint Toggle BringYourOwnSpells
 |--------------------------------------------------------------------------------------
 |-SET - values from INI for ability / spell requirements
 |--------------------------------------------------------------------------------------
	/squelch /alias /autodebuffat	/setvarint Set AutoDebuffAt
	/squelch /alias /harvestat 		/setvarint Set HarvestManaPct
 |--------------------------------------------------------------------------------------
 |-DECLARES AA and Spell variables
 |--------------------------------------------------------------------------------------
	/declare SelfHPBuff				string	outer	"NULL"
	/declare ACPyromancy			string	outer	"NULL"
	/declare FamiliarBuff			string	outer	"NULL"
	/declare SelfRune1				string	outer	"NULL"
	/declare SpellSet				string 	outer 	"auto"
	/declare spellmisc 				int 	outer 	8
	/declare spellgem				int 	outer 	1	
	/declare CastResult             string 	outer	"NULL"
	/declare miscspellremem			string 	outer 	"NULL"
	/declare spellrememtimer		timer 	outer 	0
	/declare WizzyCount				int 	outer 	1
 |-DebuffS-----------------------------------------------------------------------------
	/declare StripBuffSpell			string	outer	"NULL"
 |-DPS---------------------------------------------------------------------------------
	/declare AANukeRecasttimer		timer 	outer 	0
	/declare DPSRecastTimer			timer 	outer	0
	/declare AllianceSpell			string	outer	"NULL"
	/declare DichoSpell				string 	outer	"NULL"
	/declare ClawNuke				string 	outer	"NULL"
	/declare CloudburstNuke			string 	outer	"NULL"
	/declare FuseNuke				string 	outer	"NULL"
	/declare FireEtherealNuke		string 	outer	"NULL"
	/declare MagmaticAENuke			string 	outer	"NULL"
	/declare ChaosNuke				string 	outer	"NULL"
	/declare VortexNuke				string 	outer	"NULL"
	/declare TwincastSpell			string 	outer	"NULL"
	/declare ColdEtherealNuke		string 	outer	"NULL"
	/declare GambitSpell			string 	outer	"NULL"
	/declare WildNuke				string 	outer	"NULL"
	/declare FastNuke1				string 	outer	"NULL"
	/declare GeneralNuke1			string 	outer	"NULL"
 |-Pet---------------------------------------------------------------------------------
	/declare PetSpell				string	outer	"NULL"
	/declare PetAssistTimer			timer 	outer	0
 |-Utility
	/declare RootSpell				string	outer	"NULL" 
	/declare SnareSpell				string	outer	"NULL"
	/declare EvacSpell				string	outer	"NULL"
	/declare HarvestSpell			string 	outer	"NULL"
	/declare StunSpell				string 	outer	"NULL"
	/declare JoltSpell				string 	outer	"NULL"
 |-Config Options	
	/call LoadCommonConfig
	/call LoadIni Combat AllowMezBreak		 	int 0
	/call LoadIni Combat DoDPS					int 1
	/call LoadIni Combat UseAlliance			int 0
	/call LoadIni Combat UseDicho				int 0
	/call LoadIni Combat UseManaBurn			int 1
	/call LoadIni Combat UseMelee		 		int 0
	/call LoadIni Combat UsePet		 			int 1
	/call LoadIni Combat WeaveAANukes			int 0
	/call LoadIni Debuff AutoDebuffAt			int 99
	/call LoadIni Debuff StripBuffs				int 1
	/call LoadIni Item ChestItemName			string NULL
	/call LoadIni Item ChestCombatCast			int 0
	| /call LoadIni Options BringYourOwnSpells	int 0
	/call LoadIni Options EmergencyEvac			int 0
	/call LoadIni Options HarvestManaPct		int 75
	/call LoadIni Options StickHow				string NULL
/return
|----------------------------------------------------------------------------
|- SUB: INIChanges
|---------------------------------------------------------------------------- 
Sub INIChanges
	/varset changetoini 0
	/call SaveCommonConfig
	/call SetIni Combat AllowMezBreak		int ${AllowMezBreak}
	/call SetIni Combat DoDPS				int ${DoDPS}
	/call SetIni Combat UseAlliance			int ${UseAlliance}
	/call SetIni Combat UseDicho			int ${UseDicho}
	/call SetIni Combat UseManaBurn			int ${UseManaBurn}
	/call SetIni Combat UseMelee			int ${UseMelee}
	/call SetIni Combat UsePet				int ${UsePet}
	/call SetIni Combat WeaveAANukes		int ${WeaveAANukes}
	/call SetIni Debuff AutoDebuffAt		int ${AutoDebuffAt}
	/call SetIni Debuff StripBuffs			int ${StripBuffs}
	/call SetIni Item ChestCombatCast		int ${ChestCombatCast}
	| /call SetIni Options BringYourOwnSpells	int ${BringYourOwnSpells}
	/call SetIni Options EmergencyEvac		int ${EmergencyEvac}
	/call SetIni Options HarvestManaPct		int ${HarvestManaPct}
/return
|----------------------------------------------------------------------------
|- SUB: CheckOptions - Used to sort conflicting options at startup and set basic values if needed
|---------------------------------------------------------------------------- 
Sub CheckOptions
	/if (${AutoCampHold}) /moveto dist 2
/return
|* ------------------------------------------------------------------------------------------
| SUB: LoadSpellBar
|------------------------------------------------------------------------------------------ *|
Sub LoadSpellBar
 	/if (${Me.Standing}) {
		/sit
		/delay 10 ${Me.Sitting}
		/echo \aw Loading Spell Bar
		/delay 5
		/if (${Me.AltAbility[Mnemonic Retention].Rank}==5) /varset spellmisc 13
		/if (${Me.AltAbility[Mnemonic Retention].Rank}==4) /varset spellmisc 12
		/if (${Me.AltAbility[Mnemonic Retention].Rank}==3) /varset spellmisc 11
		/if (${Me.AltAbility[Mnemonic Retention].Rank}==2) /varset spellmisc 10
		/if (${Me.AltAbility[Mnemonic Retention].Rank}==1) /varset spellmisc 9
		/if (${Me.AltAbility[25].Name.Find[disabled]} && ${Me.AltAbilityReady[25]}) {
			/alt act 25
			/delay 5
		}
			/call LoadSpellGem "${ClawNuke}" 1
			/call LoadSpellGem "${CloudburstNuke}" 2
			/call LoadSpellGem "${FireEtherealNuke}" 3
			/call LoadSpellGem "${ColdEtherealNuke}" 4
		/if (${WizzyCount}>=3) {
			/call LoadSpellGem "${AllianceSpell}" 5
		} else {
			/call LoadSpellGem "${StunSpell}" 5
		}
		/if (${Me.AltAbility[Mnemonic Retention].Rank}==5) {
			/call LoadSpellGem "${FuseNuke}" 6
			/call LoadSpellGem "${VortexNuke}" 7
			/call LoadSpellGem "${ChaosNuke}" 8
			/call LoadSpellGem "${DichoSpell}" 9
		| /if (${DichoSpell.NotEqual[NULL]} && ${Me.Book[${Spell[${DichoSpell}].RankName}]}) {
			| } else {
				| /call LoadSpellGem "${StunSpell}" 9
		} 
 | Spell Slot #10
			/call LoadSpellGem "${TwincastSpell}" 10
 | Spell Slot #11 with Cond
		/if (${GambitSpell.NotEqual[NULL]} && ${Me.Book[${Spell[${GambitSpell}].RankName}]}) {
			/call LoadSpellGem "${GambitSpell}" 11
		} else {
			/call LoadSpellGem "${HarvestSpell}" 11
		}
			/call LoadSpellGem "${WildNuke}" 12
			/call LoadSpellGem "${JoltSpell}" 13
			/varset miscspellremem ${JoltSpell}
		} else /if (${Me.AltAbility[Mnemonic Retention].Rank}==4) {
		/if (${FuseNuke.NotEqual[NULL]} && ${Me.Book[${Spell[${FuseNuke}].RankName}]}) {
			/call LoadSpellGem "${FuseNuke}" 6
		} else {
		/if (${UsePet}) {
			/call LoadSpellGem "${PetSpell}" 6
		} else {
			/call LoadSpellGem "${GeneralNuke1}" 6
		}
	  }
		/if (${VortexNuke.NotEqual[NULL]} && ${Me.Book[${Spell[${VortexNuke}].RankName}]}) {
				/call LoadSpellGem "${VortexNuke}" 7
		} else {
			/call LoadSpellGem "${FastNuke1}" 7
			/call LoadSpellGem "${ChaosNuke}" 8
		}
		/if (${DichoSpell.NotEqual[NULL]} && ${Me.Book[${Spell[${DichoSpell}].RankName}]}) {
			/call LoadSpellGem "${DichoSpell}" 9
		} else {
			/call LoadSpellGem "${JoltSpell}" 9
		}
			/call LoadSpellGem "${TwincastSpell}" 10
		/if (${GambitSpell.NotEqual[NULL]} && ${Me.Book[${Spell[${GambitSpell}].RankName}]}) {
			/call LoadSpellGem "${GambitSpell}" 11
		} else {
			/call LoadSpellGem "${HarvestSpell}" 11
			/call LoadSpellGem "${WildNuke}" 12
			/varset miscspellremem ${WildNuke}
		} else /if (${Me.AltAbility[Mnemonic Retention].Rank}==3) {
			/call LoadSpellGem "${ChaosNuke}" 5
			/call LoadSpellGem "${WildNuke}" 6
			/call LoadSpellGem "${FastNuke1}" 7
			/call LoadSpellGem "${StunSpell}" 8
			/call LoadSpellGem "${JoltSpell}" 9
			/call LoadSpellGem "${HarvestSpell}" 10
			/varset miscspellremem ${GeneralNuke1}
		} else /if (${Me.AltAbility[Mnemonic Retention].Rank}==2) {
			/call LoadSpellGem "${ChaosNuke}" 5
			/call LoadSpellGem "${WildNuke}" 6
			/call LoadSpellGem "${FastNuke1}" 7
			/call LoadSpellGem "${StunSpell}" 8
			/call LoadSpellGem "${HarvestSpell}" 9
			/varset miscspellremem ${GeneralNuke1}
		} else /if (${Me.AltAbility[Mnemonic Retention].Rank}==1) {
			/call LoadSpellGem "${ChaosNuke}" 5
			|-6
			|-7
			/call LoadSpellGem "${HarvestSpell}" 8
		} else {
			|-6
			/call LoadSpellGem "${HarvestSpell}" 7
		}
	 }
	/if (${Me.Sitting}) /stand
	/delay 10 ${Me.Standing}
/return 
|* ------------------------------------------------------------------------------------------
| SUB: SetWizSpells
|------------------------------------------------------------------------------------------ *|
Sub SetWizSpells
	/if (!${SpellSet.Equal[auto]} && !${SpellSet.Equal[fire]} && !${SpellSet.Equal[cold]} && !${SpellSet.Equal[magic]}) /varset SpellSet auto
 |-Arco/Cryo/Pyromancy
	/if (${SpellSet.Equal[auto]} || ${SpellSet.Equal[fire]}) {
		/varset ACPyromancy Pyromancy
	} else /if (${SpellSet.Equal[cold]}) {
		/varset ACPyromancy Cryomancy
	} else /if (${SpellSet.Equal[magic]}) {
		/varset ACPyromancy Arcomancy
	}
 |-Familiar Buff
	/if (${Me.AltAbility[Improved Familiar].Rank}>=1) {
		/varset FamiliarBuff "Improved Familiar"
	} else /if (${Me.Level}>=60 && ${Me.Book[${Spell[Greater Familiar].RankName}]}) {
		/varset FamiliarBuff ${Spell[Greater Familiar].RankName}
	}
 |-Self HP Buff * Var Name: SelfHPBuff string outer
	/if (${Me.Level}>=106 && ${Me.Book[${Spell[Shield of Scales].RankName}]}) {
		/varset SelfHPBuff ${Spell[Shield of Scales].RankName}
	} else /if (${Me.Level}>=101 && ${Me.Book[${Spell[Shield of the Pellarus].RankName}]}) {
		/varset SelfHPBuff ${Spell[Shield of the Pellarus].RankName}
	} else /if (${Me.Level}>=96 && ${Me.Book[${Spell[Shield of the Dauntless].RankName}]}) {
		/varset SelfHPBuff ${Spell[Shield of the Dauntless].RankName}
	} else /if (${Me.Level}>=91 && ${Me.Book[${Spell[Shield of Bronze].RankName}]}) {
		/varset SelfHPBuff ${Spell[Shield of Bronze].RankName}
	} else /if (${Me.Level}>=86 && ${Me.Book[${Spell[Shield of Dreams].RankName}]}) {
		/varset SelfHPBuff ${Spell[Shield of Dreams].RankName}
	} else /if (${Me.Level}>=81 && ${Me.Book[${Spell[Shield of the Void].RankName}]}) {
		/varset SelfHPBuff ${Spell[Shield of the Void].RankName}
	}
 |-Self Rune 1 * Var Name: SelfRune1 string outer
	/if (${Me.Level}>=108 && ${Me.Book[${Spell[Armor of Wirn].RankName}]}) {
		/varset SelfRune1 ${Spell[Armor of Wirn].RankName}
	} else /if (${Me.Level}>=103 && ${Me.Book[${Spell[Armor of the Codex].RankName}]}) {
		/varset SelfRune1 ${Spell[Armor of the Codex].RankName}
	} else /if (${Me.Level}>=98 && ${Me.Book[${Spell[Armor of the Stonescale].RankName}]}) {
		/varset SelfRune1 ${Spell[Armor of the Stonescale].RankName}
	} else /if (${Me.Level}>=93 && ${Me.Book[${Spell[Armor of the Crystalwing].RankName}]}) {
		/varset SelfRune1 ${Spell[Armor of the Crystalwing].RankName}
	} else /if (${Me.Level}>=88 && ${Me.Book[${Spell[Dermis of the Crystalwing].RankName}]}) {
		/varset SelfRune1 ${Spell[Dermis of the Crystalwing].RankName}
	} else /if (${Me.Level}>=83 && ${Me.Book[${Spell[Squamae of the Crystalwing].RankName}]}) {
		/varset SelfRune1 ${Spell[Squamae of the Crystalwing].RankName}
	}
 |-StripBuffSpell
	/if (${Me.Level}>=100 && ${Me.AltAbilityReady[Eradicate Magic]}) {
		/varset StripBuffSpell Eradicate Magic
	} else /if (${Me.Level}>=53 && ${Me.Book[${Spell[Annul Magic].RankName}]}) {
		/varset StripBuffSpell ${Spell[Annul Magic].RankName}
	}
 |-AllianceSpell
	/if (${Me.Level}>=106 && ${Me.Book[${Spell[Frostbound Covenant].RankName}]}) {
		/varset AllianceSpell ${Spell[Frostbound Covenant].RankName}
	} else /if (${Me.Level}>=102 && ${Me.Book[${Spell[Frostbound Alliance].RankName}]}) {
		/varset AllianceSpell ${Spell[Frostbound Alliance].RankName}
	}
 |-DichoSpell
	/if (${Me.Level}>=106 && ${Me.Book[${Spell[Dissident Fire].RankName}]}) {
		/varset DichoSpell ${Spell[Dissident Fire].RankName}
	} else /if (${Me.Level}>=101 && ${Me.Book[${Spell[Dichotomic Fire].RankName}]}) {
		/varset DichoSpell ${Spell[Dichotomic Fire].RankName}
	}
 |-Root Spell * Var Name: RootSpell string outer
	/if (${Me.Level}>=61 && ${Me.Book[${Spell[Greater Fetter].RankName}]}) {
		/varset RootSpell ${Spell[Greater Fetter].RankName}
	} else /if (${Me.Level}>=58 && ${Me.Book[${Spell[Fetter].RankName}]}) {
		/varset RootSpell ${Spell[Fetter].RankName}
	}
 |-TwincastSpell
	/if (${Me.Level}>=85 && ${Me.Book[${Spell[Twincast].RankName}]}) {
		/varset TwincastSpell ${Spell[Twincast].RankName}
	}
 |-SnareSpell
	/if (${Me.Level}>=93 && ${Me.Book[${Spell[Atol's Concussive Shackles].RankName}]}) {
		/varset SnareSpell ${Spell[Atol's Concussive Shackles].RankName}
	} else /if (${Me.Level}>=51 && ${Me.Book[${Spell[Atol's Spectral Shackles].RankName}]}) {
		/varset SnareSpell ${Spell[Atol's Spectral Shackles].RankName}
	} else /if (${Me.Level}>=27 && ${Me.Book[${Spell[Bonds of Force].RankName}]}) {
		/varset SnareSpell ${Spell[Bonds of Force].RankName}
	}	
 |-JoltSpell
	/if (${Me.Level}>=106 && ${Me.Book[${Spell[Concussive Volley].RankName}]}) {
		/varset JoltSpell ${Spell[Concussive Volley].RankName}
	} else /if (${Me.Level}>=101 && ${Me.Book[${Spell[Concussive Storm].RankName}]}) {
		/varset JoltSpell ${Spell[Concussive Storm].RankName}
	} else /if (${Me.Level}>=96 && ${Me.Book[${Spell[Concussive Salvo].RankName}]}) {
		/varset JoltSpell ${Spell[Concussive Salvo].RankName}
	} else /if (${Me.Level}>=91 && ${Me.Book[${Spell[Concussive Barrage].RankName}]}) {
		/varset JoltSpell ${Spell[Concussive Barrage].RankName}
	} else /if (${Me.Level}>=86 && ${Me.Book[${Spell[Concussive Burst].RankName}]}) {
		/varset JoltSpell ${Spell[Concussive Burst].RankName}
	}
 |-HarvestSpell
	/if (${Me.Level}>=107 && ${Me.Book[${Spell[Musing Harvest].RankName}]}) {
		/varset HarvestSpell ${Spell[Musing Harvest].RankName}
	} else /if (${Me.Level}>=102 && ${Me.Book[${Spell[Quiescent Harvest].RankName}]}) {
		/varset HarvestSpell ${Spell[Quiescent Harvest].RankName}
	} else /if (${Me.Level}>=97 && ${Me.Book[${Spell[Bucolic Harvest].RankName}]}) {
		/varset HarvestSpell ${Spell[Bucolic Harvest].RankName}
	} else /if (${Me.Level}>=92 && ${Me.Book[${Spell[Placid Harvest].RankName}]}) {
		/varset HarvestSpell ${Spell[Placid Harvest].RankName}
	} else /if (${Me.Level}>=87 && ${Me.Book[${Spell[Soothing Harvest].RankName}]}) {
		/varset HarvestSpell ${Spell[Soothing Harvest].RankName}
	}
 |-GambitSpell
	/if (${Me.Level}>=110 && ${Me.Book[${Spell[Musing Gambit].RankName}]}) {
		/varset GambitSpell ${Spell[Musing Gambit].RankName}
	} else /if (${Me.Level}>=104 && ${Me.Book[${Spell[Quiescent Gambit].RankName}]}) {
		/varset GambitSpell ${Spell[Quiescent Gambit].RankName}
	} else /if (${Me.Level}>=99 && ${Me.Book[${Spell[Bucolic Gambit].RankName}]}) {
		/varset GambitSpell ${Spell[Bucolic Gambit].RankName}
	}
 |-PetSpell
	/if (${Me.Level}>=109 && ${Me.Book[${Spell[Virnax's Pyroblade].RankName}]}) {
		/varset PetSpell ${Spell[Virnax's Pyroblade].RankName}
	} else /if (${Me.Level}>=104 && ${Me.Book[${Spell[Yulin's Pyroblade].RankName}]}) {
		/varset PetSpell ${Spell[Yulin's Pyroblade].RankName}
	} else /if (${Me.Level}>=99 && ${Me.Book[${Spell[Mul's Pyroblade].RankName}]}) {
		/varset PetSpell ${Spell[Mul's Pyroblade].RankName}
	} else /if (${Me.Level}>=94 && ${Me.Book[${Spell[Burnmaster's Pyroblade].RankName}]}) {
		/varset PetSpell ${Spell[Burnmaster's Pyroblade].RankName}
	} else /if (${Me.Level}>=89 && ${Me.Book[${Spell[Lithara's Pyroblade].RankName}]}) {
		/varset PetSpell ${Spell[Lithara's Pyroblade].RankName}
	} else /if (${Me.Level}>=84 && ${Me.Book[${Spell[Daveron's Pyroblade].RankName}]}) {
		/varset PetSpell ${Spell[Daveron's Pyroblade].RankName}
	}
 |-ClawNuke
	/if (${Me.Level}>=110 && ${Me.Book[${Spell[Claw of Travenro].RankName}]} && ${SpellSet.Equal[cold]}) {
		/varset ClawNuke ${Spell[Claw of Travenro].RankName}
	} else /if (${Me.Level}>=108 && ${Me.Book[${Spell[Claw of Qunard].RankName}]} && (${SpellSet.Equal[auto]} || ${SpellSet.Equal[fire]})) {
		/varset ClawNuke ${Spell[Claw of Qunard].RankName}
	} else /if (${Me.Level}>=106 && ${Me.Book[${Spell[Claw of Ellarr].RankName}]} && ${SpellSet.Equal[magic]}) {
		/varset ClawNuke ${Spell[Claw of Ellarr].RankName}
	} else /if (${Me.Level}>=105 && ${Me.Book[${Spell[Claw of the Oceanlord].RankName}]} && ${SpellSet.Equal[cold]}) {
		/varset ClawNuke ${Spell[Claw of the Oceanlord].RankName}
	} else /if (${Me.Level}>=103 && ${Me.Book[${Spell[Claw of the Flameweaver].RankName}]} && (${SpellSet.Equal[auto]} || ${SpellSet.Equal[fire]})) {
		/varset ClawNuke ${Spell[Claw of the Flameweaver].RankName}
	} else /if (${Me.Level}>=101 && ${Me.Book[${Spell[Claw of the Indagatori].RankName}]} && ${SpellSet.Equal[magic]}) {
		/varset ClawNuke ${Spell[Claw of the Indagatori].RankName}
	} else /if (${Me.Level}>=100 && ${Me.Book[${Spell[Claw of the Icewing].RankName}]} && ${SpellSet.Equal[cold]}) {
		/varset ClawNuke ${Spell[Claw of the Icewing].RankName}
	} else /if (${Me.Level}>=98 && ${Me.Book[${Spell[Claw of the Flamewing].RankName}]}) {
		/varset ClawNuke ${Spell[Claw of the Flamewing].RankName}
	} else /if (${Me.Level}>=96 && ${Me.Book[${Spell[Claw of the Ashwing].RankName}]}) {
		/varset ClawNuke ${Spell[Claw of the Ashwing].RankName}
	} else /if (${Me.Level}>=95 && ${Me.Book[${Spell[Claw of the Abyss].RankName}]}) {
		/varset ClawNuke ${Spell[Claw of the Abyss].RankName}
	} else /if (${Me.Level}>=90 && ${Me.Book[${Spell[Glacial Claw].RankName}]}) {
		/varset ClawNuke ${Spell[Glacial Claw].RankName}
	}
 |-CloudburstNuke
	/if (${Me.Level}>=107 && ${Me.Book[${Spell[Cloudburst Thunderbolt].RankName}]}) {
		/varset CloudburstNuke ${Spell[Cloudburst Thunderbolt].RankName}
	} else /if (${Me.Level}>=102 && ${Me.Book[${Spell[Cloudburst Stormstrike].RankName}]}) {
		/varset CloudburstNuke ${Spell[Cloudburst Stormstrike].RankName}
	} else /if (${Me.Level}>=97 && ${Me.Book[${Spell[Cloudburst Thunderbolt].RankName}]}) {
		/varset CloudburstNuke ${Spell[Cloudburst Thunderbolt].RankName}
	} else /if (${Me.Level}>=92 && ${Me.Book[${Spell[Cloudburst Tempest].RankName}]}) {
		/varset CloudburstNuke ${Spell[Cloudburst Tempest].RankName}
	} else /if (${Me.Level}>=87 && ${Me.Book[${Spell[Cloudburst Storm].RankName}]}) {
		/varset CloudburstNuke ${Spell[Cloudburst Storm].RankName}
	}
 |-FuseNuke
	/if (${Me.Level}>=110 && ${Me.Book[${Spell[Ethereal Braid].RankName}]}) {
		/varset FuseNuke ${Spell[Ethereal Braid].RankName}
	} else /if (${Me.Level}>=105 && ${Me.Book[${Spell[Ethereal Fuse].RankName}]}) {
		/varset FuseNuke ${Spell[Ethereal Fuse].RankName}
	} else /if (${Me.Level}>=100 && ${Me.Book[${Spell[Ethereal Weave].RankName}]}) {
		/varset FuseNuke ${Spell[Ethereal Weave].RankName}
	}
	|  else {
 |-		/varset FuseNuke ${CloudburstNuke}
	| }
 |-WildNuke
	/if (${Me.Level}>=106 && ${Me.Book[${Spell[Wildflash Strike].RankName}]}) {
		/varset WildNuke ${Spell[Wildflash Strike].RankName}
	} else /if (${Me.Level}>=101 && ${Me.Book[${Spell[Wildflash Barrage].RankName}]}) {
		/varset WildNuke ${Spell[Wildflash Barrage].RankName}
	} else /if (${Me.Level}>=96 && ${Me.Book[${Spell[Wildether Barrage].RankName}]}) {
		/varset WildNuke ${Spell[Wildether Barrage].RankName}
	} else /if (${Me.Level}>=91 && ${Me.Book[${Spell[Wildspark Barrage].RankName}]}) {
		/varset WildNuke ${Spell[Wildspark Barrage].RankName}
	} else /if (${Me.Level}>=86 && ${Me.Book[${Spell[Wildmana Barrage].RankName}]}) {
		/varset WildNuke ${Spell[Wildmana Barrage].RankName}
	}
 |-VortexNuke
	/if (${Me.Level}>=108 && ${Me.Book[${Spell[Stormjolt Vortex].RankName}]}) {
		/varset VortexNuke ${Spell[Stormjolt Vortex].RankName}
	} else /if (${Me.Level}>=103 && ${Me.Book[${Spell[Shocking Vortex].RankName}]}) {
		/varset VortexNuke ${Spell[Shocking Vortex].RankName}
	} else /if (${Me.Level}>=100 && ${Me.Book[${Spell[Hoarfrost Vortex].RankName}]} && (${SpellSet.Equal[auto]} || ${SpellSet.Equal[fire]})) {
		/varset VortexNuke ${Spell[Hoarfrost Vortex].RankName}
	} else /if (${Me.Level}>=98 && ${Me.Book[${Spell[Ether Vortex].RankName}]} && ${SpellSet.Equal[cold]}) {
		/varset VortexNuke ${Spell[Ether Vortex].RankName}
	} else /if (${Me.Level}>=96 && ${Me.Book[${Spell[Incandescent Vortex].RankName}]} && ${SpellSet.Equal[magic]}) {
		/varset VortexNuke ${Spell[Incandescent Vortex].RankName}
	} else /if (${Me.Level}>=95 && ${Me.Book[${Spell[Frost Vortex].RankName}]} && (${SpellSet.Equal[auto]} || ${SpellSet.Equal[fire]})) {
		/varset VortexNuke ${Spell[Frost Vortex].RankName}
	} else /if (${Me.Level}>=93 && ${Me.Book[${Spell[Power Vortex].RankName}]} && ${SpellSet.Equal[cold]}) {
		/varset VortexNuke ${Spell[Power Vortex].RankName}
	} else /if (${Me.Level}>=91 && ${Me.Book[${Spell[Flame Vortex].RankName}]} && ${SpellSet.Equal[magic]}) {
		/varset VortexNuke ${Spell[Flame Vortex].RankName}
	} else /if (${Me.Level}>=90 && ${Me.Book[${Spell[Ice Vortex].RankName}]} && (${SpellSet.Equal[auto]} || ${SpellSet.Equal[fire]})) {
		/varset VortexNuke ${Spell[Ice Vortex].RankName}
	} else /if (${Me.Level}>=88 && ${Me.Book[${Spell[Mana Vortex].RankName}]} && ${SpellSet.Equal[cold]}) {
		/varset VortexNuke ${Spell[Mana Vortex].RankName}
	} else /if (${Me.Level}>=86 && ${Me.Book[${Spell[Fire Vortex].RankName}]} && ${SpellSet.Equal[magic]}) {
		/varset VortexNuke ${Spell[Fire Vortex].RankName}
	}
 |-ChaosNuke
	/if (${Me.Level}>=108 && ${Me.Book[${Spell[Chaos Burn].RankName}]}) {
		/varset ChaosNuke ${Spell[Chaos Burn].RankName}
	} else /if (${Me.Level}>=103 && ${Me.Book[${Spell[Chaos Scintillation].RankName}]}) {
		/varset ChaosNuke ${Spell[Chaos Scintillation].RankName}
	} else /if (${Me.Level}>=99 && ${Me.Book[${Spell[Chaos Incandescence].RankName}]}) {
		/varset ChaosNuke ${Spell[Chaos Incandescence].RankName}
	} else /if (${Me.Level}>=94 && ${Me.Book[${Spell[Chaos Blaze].RankName}]}) {
		/varset ChaosNuke ${Spell[Chaos Blaze].RankName}
	} else /if (${Me.Level}>=89 && ${Me.Book[${Spell[Chaos Char].RankName}]}) {
		/varset ChaosNuke ${Spell[Chaos Char].RankName}
	}
 |-MagmaticAENuke
	/if (${Me.Level}>=109 && ${Me.Book[${Spell[Magmatic Explosion].RankName}]}) {
		/varset MagmaticAENuke ${Spell[Magmatic Explosion].RankName}
	} else /if (${Me.Level}>=104 && ${Me.Book[${Spell[Magmatic Burst].RankName}]}) {
		/varset MagmaticAENuke ${Spell[Magmatic Burst].RankName}
	} else /if (${Me.Level}>=99 && ${Me.Book[${Spell[Magmatic Vent].RankName}]}) {
		/varset MagmaticAENuke ${Spell[Magmatic Vent].RankName}
	} else /if (${Me.Level}>=94 && ${Me.Book[${Spell[Magmatic Outburst].RankName}]}) {
		/varset MagmaticAENuke ${Spell[Magmatic Outburst].RankName}
	} else /if (${Me.Level}>=89 && ${Me.Book[${Spell[Magmatic Downpour].RankName}]}) {
		/varset MagmaticAENuke ${Spell[Magmatic Downpour].RankName}
	} else /if (${Me.Level}>=84 && ${Me.Book[${Spell[Magmatic Eruption].RankName}]}) {
		/varset MagmaticAENuke ${Spell[Magmatic Eruption].RankName}
	}
 |-FireEtherealNuke
	/if (${Me.Level}>=110 && ${Me.Book[${Spell[Ethereal Skyfire].RankName}]}) {
		/varset FireEtherealNuke ${Spell[Ethereal Skyfire].RankName}
	} else /if (${Me.Level}>=105 && ${Me.Book[${Spell[Ethereal Skyblaze].RankName}]}) {
		/varset FireEtherealNuke ${Spell[Ethereal Skyblaze].RankName}
	} else /if (${Me.Level}>=100 && ${Me.Book[${Spell[Ethereal Incandescence].RankName}]}) {
		/varset FireEtherealNuke ${Spell[Ethereal Incandescence].RankName}
	} else /if (${Me.Level}>=95 && ${Me.Book[${Spell[Ethereal Blaze].RankName}]}) {
		/varset FireEtherealNuke ${Spell[Ethereal Blaze].RankName}
	} else /if (${Me.Level}>=90 && ${Me.Book[${Spell[Ethereal Inferno].RankName}]}) {
		/varset FireEtherealNuke ${Spell[Ethereal Inferno].RankName}
	} else /if (${Me.Level}>=85 && ${Me.Book[${Spell[Ethereal Combustion].RankName}]}) {
		/varset FireEtherealNuke ${Spell[Ethereal Combustion].RankName}
	}
 |-ColdEtherealNuke
	/if (${Me.Level}>=109 && ${Me.Book[${Spell[Ethereal Icefloe].RankName}]}) {
		/varset ColdEtherealNuke ${Spell[Ethereal Icefloe].RankName}
	} else /if (${Me.Level}>=104 && ${Me.Book[${Spell[Ethereal Rimeblast].RankName}]}) {
		/varset ColdEtherealNuke ${Spell[Ethereal Rimeblast].RankName}
	} else /if (${Me.Level}>=99 && ${Me.Book[${Spell[Ethereal Hoarfrost].RankName}]}) {
		/varset ColdEtherealNuke ${Spell[Ethereal Hoarfrost].RankName}
	} else /if (${Me.Level}>=94 && ${Me.Book[${Spell[Ethereal Frost].RankName}]}) {
		/varset ColdEtherealNuke ${Spell[Ethereal Frost].RankName}
	} else /if (${Me.Level}>=89 && ${Me.Book[${Spell[Ethereal Glaciation].RankName}]}) {
		/varset ColdEtherealNuke ${Spell[Ethereal Glaciation].RankName}
	} else /if (${Me.Level}>=84 && ${Me.Book[${Spell[Ethereal Iceblight].RankName}]}) {
		/varset ColdEtherealNuke ${Spell[Ethereal Iceblight].RankName}
	}
 |-EvacSpell
	/if (${Me.Level}>=57 && ${Me.Book[${Spell[Evacuate].RankName}]}) {
		/varset EvacSpell ${Spell[Evacuate].RankName}
	} else /if (${Me.Level}>=18 && ${Me.Book[${Spell[Lesser Evacuate].RankName}]}) {
		/varset EvacSpell ${Spell[Lesser Evacuate].RankName}
	}
 |-StunSpell
	/if (${Me.Level}>=110 && ${Me.Book[${Spell[Telanata].RankName}]}) {
		/varset StunSpell ${Spell[Telanata].RankName}
	} else /if (${Me.Level}>=105 && ${Me.Book[${Spell[Telanara].RankName}]}) {
		/varset StunSpell ${Spell[Telanara].RankName}
	} else /if (${Me.Level}>=100 && ${Me.Book[${Spell[Telanaga].RankName}]}) {
		/varset StunSpell ${Spell[Telanaga].RankName}
	} else /if (${Me.Level}>=95 && ${Me.Book[${Spell[Telanama].RankName}]}) {
		/varset StunSpell ${Spell[Telanama].RankName}
	} else /if (${Me.Level}>=90 && ${Me.Book[${Spell[Telakama].RankName}]}) {
		/varset StunSpell ${Spell[Telakama].RankName}
	} else /if (${Me.Level}>=85 && ${Me.Book[${Spell[Telajara].RankName}]}) {
		/varset StunSpell ${Spell[Telajara].RankName}
	}
 |-FastNuke1 Fastest casting general nuke not already used 
	/if (${Me.Level}>=107 && ${Me.Book[${Spell[Leap of Stormjolts].RankName}]}) {
		/varset FastNuke1 ${Spell[Leap of Stormjolts].RankName}
	} else /if (${Me.Level}>=102 && ${Me.Book[${Spell[Leap of Stormbolts].RankName}]}) {
		/varset FastNuke1 ${Spell[Leap of Stormbolts].RankName}
	} else /if (${Me.Level}>=97 && ${Me.Book[${Spell[Leap of Static Sparks].RankName}]}) {
		/varset FastNuke1 ${Spell[Leap of Static Sparks].RankName}
	} else /if (${Me.Level}>=92 && ${Me.Book[${Spell[Leap of Plasma].RankName}]}) {
		/varset FastNuke1 ${Spell[Leap of Plasma].RankName}
	} else /if (${Me.Level}>=87 && ${Me.Book[${Spell[Leap of Corposantum].RankName}]}) {
		/varset FastNuke1 ${Spell[Leap of Corposantum].RankName}
	} else /if (${Me.Level}>=82 && ${Me.Book[${Spell[Leap of Static Jolts].RankName}]}) {
		/varset FastNuke1 ${Spell[Leap of Static Jolts].RankName}
	}
 |-GeneralNuke1 Slower casting biggest nuke not already used
	/if (${Me.Level}>=110 && ${Me.Book[${Spell[Dragoflux's Fire].RankName}]}) {
		/varset GeneralNuke1 ${Spell[Dragoflux's Fire].RankName}
	} else /if (${Me.Level}>=105 && ${Me.Book[${Spell[Narendi's Fire].RankName}]}) {
		/varset GeneralNuke1 ${Spell[Narendi's Fire].RankName}
	} else /if (${Me.Level}>=100 && ${Me.Book[${Spell[Gosik's Fire].RankName}]}) {
		/varset GeneralNuke1 ${Spell[Gosik's Fire].RankName}
	} else /if (${Me.Level}>=95 && ${Me.Book[${Spell[Daevan's Fire].RankName}]}) {
		/varset GeneralNuke1 ${Spell[Daevan's Fire].RankName}
	} else /if (${Me.Level}>=90 && ${Me.Book[${Spell[Lithara's Fire].RankName}]}) {
		/varset GeneralNuke1 ${Spell[Lithara's Fire].RankName}
	} else /if (${Me.Level}>=85 && ${Me.Book[${Spell[Klixcxyk's Fire].RankName}]}) {
		/varset GeneralNuke1 ${Spell[Klixcxyk's Fire].RankName}
	}
/return 
|----------------------------------------------------------------------------
|- SUB: Bind Set Var Int resets various interger settings from ini file
|----------------------------------------------------------------------------
Sub Bind_SetVarInt(string ISection, string IName, int IVar)
    /docommand /varset changetoini 1
 |-Toggles
	/if (${ISection.Equal[Toggle]}) {
		/if (${IName.Equal[UseManaBurn]}) {
 |-ManaBurn
			/if (!${UseManaBurn}) {
				/echo \aw Setting  UseManaBurn to \ag ON
				/varset UseManaBurn 1
			} else {
				/echo \aw Resetting  UseManaBurn to \ar OFF
				/varset UseManaBurn 0
			}
 |-Dicho
		} else /if (${IName.Equal[UseDicho]}) {
			/if (!${UseDicho}) {
				/echo \aw Setting UseDicho to \ag ON
				/varset UseDicho 1
			} else {
				/echo \aw Resetting UseDicho to \ar OFF
				/varset UseDicho 0
			}
 |-EmergencyEvac
		} else /if (${IName.Equal[EmergencyEvac]}) {
			/if (!${EmergencyEvac}) {
				/echo \aw Setting EmergencyEvac to \ag ON
				/varset EmergencyEvac 1
			} else {
				/echo \aw Resetting EmergencyEvac to \ar OFF
				/varset EmergencyEvac 0
			}
 |-ChestCombatCast
		} else /if (${IName.Equal[ChestCombatCast]}) {
			/if (!${ChestCombatCast}) {
				/echo \aw Setting ChestCombatCast to \ag ON
				/varset ChestCombatCast 1
			} else {
				/echo \aw Resetting ChestCombatCast to \ar OFF
				/varset ChestCombatCast 0
			}
 |-StripBuffs
		} else /if (${IName.Equal[StripBuffs]}) {
			/if (!${StripBuffs}) {
				/echo \aw Setting StripBuffs to \ag ON
				/varset StripBuffs 1
			} else {
				/echo \aw Resetting StripBuffs to \ar OFF
				/varset StripBuffs 0
			}
 |-WeaveAANukes
		} else /if (${IName.Equal[WeaveAANukes]}) {
			/if (!${WeaveAANukes}) {
				/echo \aw Setting WeaveAANukes to \ag ON
				/varset WeaveAANukes 1
			} else {
				/echo \aw Resetting WeaveAANukes to \ar OFF
				/varset WeaveAANukes 0
			}
		}
 |-Set's
	} else /if (${ISection.Equal[Set]}) {
		/if (${IName.Equal[]}) {
			/if (${IVar}>=2 && ${IVar}<=100) {
				/varset  ${IVar}
				/echo \aw ${IName} set to \ag ${IVar}
			} else {
				/beep
				/echo \ar Invalid \ag ${IName} \aw - Set between 2-100 mobs
			}
		} else /if (${IName.Equal[]}) {
			/if (${IVar}>=3 && ${IVar}<=100) {
				/varset  ${IVar}
				/echo \aw ${IName} set to \ag ${IVar}
			} else {
				/beep
				/echo \ar Invalid \ag ${IName} \aw - Set between 3-100 mobs
			}
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
		}	
/return
|----------------------------------------------------------------------------
|- SUB: BIND CmdList - 
|----------------------------------------------------------------------------
Sub Bind_CmdList
	/call CommonHelp
	/echo \ag===${MacroName} Commands=== 
	/echo \ag/autodebuffat\aw - HP % to start debuffing at
	| /echo \ag/byos\aw - 
	/echo \ag/harvestat\aw - Harvest Mana %
	/echo \ag/tglalliance\aw - Toggles use of Alliance
	/echo \ag/tglaoe\aw - Toggle use of AOE Spells 
	/echo \ag/tglbp\aw - Toggle use of chest item
	/echo \ag/tgldicho\aw - Toggle use of Dicho spell
	/echo \ag/tgldps\aw - Turns ALL DPS On/Off
	/echo \ag/tglevac\aw - Toggles Evac if tank dies
	/echo \ag/tglmezbreak\aw - Toggles Allowing mez break
	/echo \ag/tglpet\aw - Pet toggle...cause sometimes they arent allowed
	/echo \ag/tglstrip\aw - Turns Enemy Buff stripping On/Off
	/echo \ag/tglweave\aw - Toggles weaving of AA Nukes
/return 