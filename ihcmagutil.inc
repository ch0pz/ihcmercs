|- ihcmagutil.inc
|- Version 2.0
|- Updated: 4/25/2019
|--------------------------------------------------------------------------------------
|-Setup Variable Environment
|--------------------------------------------------------------------------------------
Sub MagSetup
|-Create Alias
|-- Toggles
	/squelch /alias /tglaoe			/setvarint Toggle UseAoE
	/squelch /alias /tglbp			/setvarint Toggle ChestCombatCast
	/squelch /alias /tglpet			/setvarint Toggle UsePet
	/squelch /alias /tgldps			/setvarint Toggle DoDPS
	/squelch /alias /tglmezbreak	/setvarint Toggle AllowMezBreak
|-	/squelch /alias /tglstrip		/setvarint Toggle StripBuffs
|-	/squelch /alias /tglalliance	/setvarint Toggle UseAlliance
|-	/squelch /alias /tglweave		/setvarint Toggle WeaveAANukes
|-	/squelch /alias /autodebuffat	/setvarint Set AutoDebuffAt
| -	/squelch /alias /harvestat 		/setvarint Set HarvestManaPct
|-------------------------------------------------------------------------------------
|-Declare spells and INI settings
|-------------------------------------------------------------------------------------
|-General Spell timers & Misc
	/declare spellmisc 			int outer 13
	/declare GroupBuffRecast 	int outer 0
	/declare miscspellremem		string outer NULL
	/declare CastResult         string outer
	/declare spellrememtimer	timer outer 0
	/declare groupbufftimer		timer outer 0
	/declare DPSRecastTimer		timer outer 0
|-BUFFS
	/declare MeleeShield		string outer NULL
	/declare ManaRegenBuff		string outer NULL
	/declare ManaRegenBuffName	string outer NULL
	/declare DamageShield		string outer NULL
	/declare ShieldSpell		string outer NULL
	| /declare SelfHPBuff			string outer NULL	- "to replace ShieldSpell"
|-DPS
	/declare NukeSpell1			string outer NULL
	/declare NukeSpell2			string outer NULL
	/declare NukeSpell3			string outer NULL
	/declare NukeSpell4			string outer NULL
	/declare NukeSpell5			string outer NULL
	/declare DichoSpell			string outer NULL
	/declare TwinSpell			string outer NULL	
|-PET
	/declare SwarmPet			string outer NULL
	/declare PetHealSpell		string outer NULL
	/declare PetSpell			string outer NULL
	/declare PetType			string outer NULL
	/declare PetOffenseBuff		string outer NULL
	/declare PetDefenseBuff		string outer NULL
	/declare PetHaste			string outer NULL
	| /declare FirePet			string outer NULL
	| /declare PetAir			string outer NULL
	| /declare WaterPet			string outer NULL
	| /declare EarthPet			string outer NULL
|----------------------------------------------------------------------------
|-Config IHCMag.INI settings
|----------------------------------------------------------------------------
	/call LoadCommonConfig
	/call LoadIni Buffs UseShield				int 1
	/call LoadIni Buffs UseDmgShield			int 1
	/call LoadIni Combat AllowMezBreak		 	int 0
	/call LoadIni Combat DoDPS					int 1
	/call LoadIni Combat Manatonuke				int 5
	/call LoadIni Combat StickHow				string behind
	/call LoadIni Combat StopNukeAggro			int 80
	/call LoadIni Combat UseAoE					int 0
	/call LoadIni Combat UseMelee		 		int 1
	/call LoadIni Healing PetHealpoint			int 40
	/call LoadIni Item ChestItemName			string NULL
	/call LoadIni Item ChestCombatCast			int 0
	/call LoadIni Pet UsePet		 			int 1
	/call LoadIni Pet DoPetTank		 			int 0
	/call LoadIni Pet UseSwarmpet		 		int 0
	| /call LoadIni Options HarvestManaPct		int 75
	| /call LoadIni Pet PetType					string NULL	
/return 
|----------------------------------------------------------------------------
|- SUB: INIChanges
|---------------------------------------------------------------------------- 
Sub INIChanges
	/varset changetoini 0
	/call SaveCommonConfig
	/call SetIni Combat AllowMezBreak		 	int ${AllowMezBreak}
	/call SetIni Combat DoDPS					int ${DoDPS}
	/call SetIni Combat Manatonuke				int ${Manatonuke}
	/call SetIni Combat StopNukeAggro			int ${StopNukeAggro}
	/call SetIni Combat UseAoE					int ${UseAoE}
	/call SetIni Combat UseMelee		 		int ${UseMelee}
	/call SetIni Healing PetHealpoint			int ${PetHealpoint}
	/call SetIni Item ChestCombatCast			int ${ChestCombatCast}
	/call SetIni Pet UsePet		 				int ${UsePet}
	/call SetIni Pet DoPetTank		 			int ${DoPetTank}
	/call SetIni Pet UseSwarmpet		 		int ${UseSwarmpet}
	| /call SetIni Pet HarvestManaPct		 		int ${HarvestManaPct}
 	| /call SetIni Pet PetType		 			int ${PetType}
/return
|* ------------------------------------------------------------------------------------------
| SUB: LoadSpellBar
|------------------------------------------------------------------------------------------ *|
Sub LoadSpellBar
	/if (${Me.Standing}) {
		/sit
		/delay 10 ${Me.Sitting}
		/echo \aw Loading Spell Bar
		/call LoadSpellGem "${SwarmPet}" 1
		/call LoadSpellGem "${NukeSpell1}" 2
		/call LoadSpellGem "${NukeSpell2}" 3
		/call LoadSpellGem "${NukeSpell3}" 4
		/call LoadSpellGem "${NukeSpell4}" 5		
		/call LoadSpellGem "${NukeSpell5}" 6
		/call LoadSpellGem "${DichoSpell}" 7
		/call LoadSpellGem "${TwinSpell}" 8
		/call LoadSpellGem "${PetOffenseBuff}" 9
		/call LoadSpellGem "${DamageShield}" 10
		/call LoadSpellGem "${PetHaste}" 11
		/call LoadSpellGem "${PetDefenseBuff}" 12
		/call LoadSpellGem "${MeleeShield}" 13
	/if (${Me.Sitting}) /stand
	/delay 10 ${Me.Standing}
	}
/return 
|----------------------------------------------------------------------------
|- SUB: SetSpells
|---------------------------------------------------------------------------- 
Sub SetSpells
	/varset SwarmPet 		${Spell[Reckless Servant].RankName}
	/varset PetSpell 		${Spell[Embodiment of Air].RankName}
	/varset PetHealSpell 	${Spell[Renewal of Ioulin].RankName}
	/varset PetHaste 		${Spell[Burnout XIII].RankName}
	/varset PetOffenseBuff 	${Spell[Iceflame Keep].RankName}
	/varset PetDefenseBuff 	${Spell[Aegis of Zeklor].RankName}
	/varset DichoSpell 		${Spell[Dissident Companion].RankName}	
	/varset NukeSpell1 		${Spell[Chaotic Inferno].RankName}
	/varset NukeSpell2 		${Spell[Spear of Molten Arcronite].RankName}
	/varset NukeSpell3 		${Spell[Spear of Molten Shieldstone].RankName}
	/varset NukeSpell4 		${Spell[Shock of Arcronite Steel].RankName}
	/varset NukeSpell5 		${Spell[Volley of Many].RankName}
	/varset ShieldSpell 	${Spell[Shield of Scales].RankName}	
	/varset MeleeShield 	${Spell[Shield of Order].RankName}
	/varset ManaRegenBuff 	${Spell[Burning Guardian].RankName}
	/varset DamageShield 	${Spell[Circle of the Inferno].RankName}
	/varset TwinSpell 		${Spell[Twincast].RankName}
	| /varset FirePet			${Spell[].RankName}
	| /varset PetAir			${Spell[].RankName}
	| /varset WaterPet		${Spell[].RankName}
	| /varset EarthPet		${Spell[].RankName}
/return
|----------------------------------------------------------------------------
|- SUB: Bind Change Var Int resets various interger settings from ini file
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
		} else /if (${IName.Equal[AllowMezBreak]}) {
			/if (!${AllowMezBreak}) {
				/echo \aw Setting AllowMezBreak to \ag ON
				/varset AllowMezBreak 1
			} else {
				/echo \aw Resetting AllowMezBreak to \ar OFF
				/varset AllowMezBreak 0
			}
		} else /if (${IName.Equal[UseAoE]}) {
			/if (!${UseAoE}) {
				/echo \aw Setting UseAoE to \ag ON
				/varset UseAoE 1
			} else {
				/echo \aw Resetting UseAoE to \ar OFF
				/varset UseAoE 0
			}
		} else /if (${IName.Equal[ChestCombatCast]}) {
			/if (!${ChestCombatCast}) {
				/echo \aw Setting ChestCombatCast to \ag ON
				/varset ChestCombatCast 1
			} else {
				/echo \aw Resetting ChestCombatCast to \ar OFF
				/varset ChestCombatCast 0
			}
		| } else /if (${IName.Equal[BringYourOwnSpells]}) {
			| /if (!${BringYourOwnSpells}) {
				| /echo \aw Setting BringYourOwnSpells to \ag ON
				| /varset BringYourOwnSpells 1
			| } else {
				| /echo \aw Resetting BringYourOwnSpells to \ar OFF
				| /varset BringYourOwnSpells 0
				| /call LoadSpellBar
			| }
		} 
	}
/return
|----------------------------------------------------------------------------
|- SUB: BIND CmdList - 
|----------------------------------------------------------------------------
Sub Bind_CmdList
	/call CommonHelp
	/echo \ag===${MacroName} Commands=== 
	/echo \ag/tglaoe\aw - Turn the use of AE abilities on/off
	/echo \ag/tglbp\aw - Turn on/off the use of a Chest piece defined in the ini
	/echo \ag/tglpet\aw - Pet toggle...cause sometimes they arent allowed
	/echo \ag/tglmezbreak\aw - Allow attacking mez'd mobs if below assistat % - Ignores waiting for MA
/return