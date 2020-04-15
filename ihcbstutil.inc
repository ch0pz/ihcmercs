|- ihcbstutil.inc
|- Version 2.0
|- Updated: 4/25/2019
|--------------------------------------------------------------------------------------
|-Setup Variable Environment
|--------------------------------------------------------------------------------------
Sub BstSetup
|-Create Alias Toggles
	/squelch /alias /tglaoe			/setvarint Toggle UseAoE
	/squelch /alias /tglbp			/setvarint Toggle ChestCombatCast
	/squelch /alias /tglIllusion	/setvarint Toggle UseIllusion
	/squelch /alias /tglpet			/setvarint Toggle UsePet
	/squelch /alias /tglpoison		/setvarint Toggle UsePoisons
	/squelch /alias /tgldot			/setvarint Toggle DoDot
	/squelch /alias /tglmezbreak	/setvarint Toggle AllowMezBreak
	/squelch /alias /tglslow		/setvarint Toggle DoSlow
	/squelch /alias /tglferocity	/setvarint Toggle DoFerocity
	/squelch /alias /tglpetslow		/setvarint Toggle DoPetSlow
	/squelch /alias /tglswarm		/setvarint Toggle UseSwarmPet
	/squelch /alias /tglheal		/setvarint Toggle DoHeals
	| /squelch /alias /tgl			/setvarint Toggle 
	| /squelch /alias /tgl			/setvarint Toggle 

|-Spells
	/declare SwarmPet			string outer NULL
	/declare NukeSpell1			string outer NULL
	/declare NukeSpell2			string outer NULL
	/declare NukeSpell3			string outer NULL
	/declare NukeSpell4			string outer NULL
	/declare NukeSpell5			string outer NULL
	/declare DoTSpell1			string outer NULL
	/declare DoTSpell2			string outer NULL
	/declare SlowSpell			string outer NULL
	/declare DichoSpell			string outer NULL
	/declare HealSpell1			string outer NULL
	/declare PetHealSpell		string outer NULL
	/declare FocusSpell			string outer NULL
	/declare AtkBuff			string outer NULL
	/declare PetSpell			string outer NULL
	/declare PetEnduranceProc	string outer NULL
	/declare PetSpellGuard		string outer NULL
	/declare PetSlowProc		string outer NULL
	/declare PetOffenseBuff		string outer NULL
	/declare PetDefenseBuff		string outer NULL
	/declare PetHaste			string outer NULL
	/declare PetGrowl			string outer NULL
	/declare PetHealProc		string outer NULL
	/declare PetDamageProc		string outer NULL
	/declare UnityBuff			string outer NULL
	/declare KillShotBuff		string outer NULL
	/declare RunSpeedBuff		string outer NULL
	/declare ManaRegenBuff		string outer NULL
	/declare ManaRegenBuffName	string outer NULL
	/declare AtkHPBuff			string outer NULL
	/declare AtkHPBuffName		string outer NULL

|-discs
	/declare EndRegenDisc		string outer NULL
	/declare Maul				string outer NULL
	/declare SingleClaws		string outer NULL
	/declare BeastialBuffDisc	string outer NULL
	/declare AEClaws			string outer NULL
	/declare HHEFuryDisc		string outer NULL
	/declare DmgModDisc			string outer NULL
	/declare EndRegenProcDisc	string outer NULL

|-Config Options
	/call LoadCommonConfig
	/call LoadIni Buffs UseFocus				int 1
	/call LoadIni Buffs UseRunSpeed				int 1
	/call LoadIni Combat AllowMezBreak		 	int 0
	/call LoadIni Combat DoSlow					int 0
	/call LoadIni Combat DoDot					int 0
	/call LoadIni Combat Manatonuke				int 5
	/call LoadIni Combat StickHow				string behind
	/call LoadIni Combat StopNukeAggro			int 80
	/call LoadIni Combat UseAoE					int 0
	/call LoadIni Combat UseMelee		 		int 1
	/call LoadIni Healing DoHeals				int 0
	/call LoadIni Healing DynamicHealing		int 0
	/call LoadIni Healing Healpoint				int 30
	/call LoadIni Healing PetHealpoint			int 40
	/call LoadIni Healing TBMHealpoint			int 65
	/call LoadIni Healing RaidHealpoint			int 65
	/call LoadIni Item ChestItemName			string NULL
	/call LoadIni Item ChestCombatCast			int 0
	/call LoadIni Item UseIllusion				int 0
	/call LoadIni Item IllusionItem				string NULL
	/call LoadIni Item IllusionBuffName			string NULL
	/call LoadIni Options DoFerocity			int 1
	/call LoadIni Options FocParagonManaPct		int 80
	/call LoadIni Options FocParagonEndPct		int 80
	/call LoadIni Options ParagonManaPct		int 80
	/call LoadIni Pet UsePet		 			int 1
	/call LoadIni Pet DoPetTank		 			int 0
	/call LoadIni Pet UseSwarmpet		 		int 0
	/call LoadIni Pet DoPetSlow					int 0

|-Declare spell variables
	/declare spellmisc 			int outer 8
	/declare GroupBuffRecast 	int outer 0
	/declare miscspellremem		string outer NULL
	/declare CastResult         string outer
	/declare spellrememtimer	timer outer 0
	/declare fparatimer2		timer outer 60s
	/declare groupbufftimer		timer outer 0
	/if (${Me.AltAbility[Mnemonic Retention].Rank}==5) /varset spellmisc 13
	/if (${Me.AltAbility[8300].Name.Find[disabled]} && ${Me.AltAbilityReady[8300]}) {
		/alt act 8300
		/delay 5
	}
/return 

|----------------------------------------------------------------------------
|- SUB: INIChanges
|---------------------------------------------------------------------------- 
Sub INIChanges
	/varset changetoini 0
	/call SaveCommonConfig
	/call SetIni Combat AllowMezBreak		 	int ${AllowMezBreak}
	/call SetIni Combat DoSlow					int ${DoSlow}
	/call SetIni Combat DoDot					int ${DoDot}
	/call SetIni Combat Manatonuke				int ${Manatonuke}
	/call SetIni Combat StopNukeAggro			int ${StopNukeAggro}
	/call SetIni Combat UseAoE					int ${UseAoE}
	/call SetIni Combat UseMelee		 		int ${UseMelee}
	/call SetIni Healing DoHeals				int ${DoHeals}
	/call SetIni Healing DynamicHealing			int ${DynamicHealing}
	/call SetIni Healing Healpoint				int ${Healpoint}
	/call SetIni Healing PetHealpoint			int ${PetHealpoint}
	/call SetIni Healing TBMHealpoint			int ${TBMHealpoint}
	/call SetIni Healing RaidHealpoint			int ${RaidHealpoint}
	/call SetIni Item ChestCombatCast			int ${ChestCombatCast}
	/call SetIni Item UseIllusion		 		int ${UseIllusion}
	/call SetIni Options DoFerocity				int ${DoFerocity}
	/call SetIni Options FocParagonManaPct		int ${FocParagonManaPct}
	/call SetIni Options FocParagonEndPct		int ${FocParagonEndPct}
	/call SetIni Options ParagonManaPct			int ${ParagonManaPct}
	/call SetIni Pet UsePet		 				int ${UsePet}
	/call SetIni Pet DoPetTank		 			int ${DoPetTank}
	/call SetIni Pet UseSwarmpet		 		int ${UseSwarmpet}
	/call SetIni Pet DoPetSlow			 		int ${DoPetSlow}
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
		/call LoadSpellGem "${DoTSpell1}" 7
		/call LoadSpellGem "${DoTSpell2}" 8
		/call LoadSpellGem "${DichoSpell}" 9
		/call LoadSpellGem "${PetGrowl}" 10
		/call LoadSpellGem "${HealSpell1}" 11
		/call LoadSpellGem "${AtkBuff}" 12
		/call LoadSpellGem "${RunSpeedBuff}" 13
		/varset miscspellremem ${RunSpeedBuff}
	}
	/if (${Me.Sitting}) {
		/stand
		/delay 10 ${Me.Standing}
	}	
/return 

|----------------------------------------------------------------------------
|- SUB: CheckSpells
|---------------------------------------------------------------------------- 
Sub CheckSpells
|-Swarm Pet*
	/if (${Me.Level}>=${Spell[Akalit's Feralgia].Level} && ${Me.Book[${Spell[Akalit's Feralgia].RankName}]}) {
		/varset SwarmPet ${Spell[Akalit's Feralgia].RankName}
	}
|-Cold/Poison Nuke fast cast*
	/if (${Me.Level}>=${Spell[Frozen Toxin].Level} && ${Me.Book[${Spell[Frozen Toxin].RankName}]}) {
		/varset NukeSpell1 ${Spell[Frozen Toxin].RankName}
	}
|-Cold/Poison/Disease Nuke fast cast*
	/if (${Me.Level}>=${Spell[Beramos' Maelstrom].Level} && ${Me.Book[${Spell[Beramos' Maelstrom].RankName}]}) {
		/varset NukeSpell2 ${Spell[Beramos' Maelstrom].RankName}
	}
|-Poison Nuke fast cast*
	/if (${Me.Level}>=${Spell[Mawmun's Bite].Level} && ${Me.Book[${Spell[Mawmun's Bite].RankName}]}) {
		/varset NukeSpell3 ${Spell[Mawmun's Bite].RankName}
	}
|-Lance#1 Timer#11 Ice Nuke fast cast* 
	/if (${Me.Level}>=${Spell[Kromtus Lance].Level} && ${Me.Book[${Spell[Kromtus Lance].RankName}]}) {
		/varset NukeSpell4 ${Spell[Kromtus Lance].RankName}
	}
|-Lance#2 Timer#7 Ice Nuke fast cast*
	/if (${Me.Level}>=${Spell[Frostbite Lance].Level} && ${Me.Book[${Spell[Frostbite Lance].RankName}]}) {
		/varset NukeSpell5 ${Spell[Frostbite Lance].RankName}
	}
|-Poison DoT Instant Cast*
	/if (${Me.Level}>=${Spell[Polybiad Blood].Level} && ${Me.Book[${Spell[Polybiad Blood].RankName}]}) {
		/varset DoTSpell1 ${Spell[Polybiad Blood].RankName}
	}
|-Cold DoT Instant Cast*
	/if (${Me.Level}>=${Spell[Ekron's Chill].Level} && ${Me.Book[${Spell[Ekron's Chill].RankName}]}) {
		/varset DoTSpell2 ${Spell[Ekron's Chill].RankName}
	}
|-Dicho Spell*
	/if (${Me.Level}>=${Spell[Dissident Fury].Level} && ${Me.Book[${Spell[Dissident Fury].RankName}]}) {
	/varset DichoSpell ${Spell[Dissident Fury].RankName}
	}
|-Slow Spell*
	/if (${Me.Level}>=${Spell[Sha's Reprisal].Level} && ${Me.Book[${Spell[Sha's Reprisal].RankName}]}) {
		/varset SlowSpell ${Spell[Sha's Reprisal].RankName}
	}
|-Single target HealSpell1*
	/if (${Me.Level}>=${Spell[Deltro's Mending].Level} && ${Me.Book[${Spell[Deltro's Mending].RankName}]}) {
		/varset HealSpell1 ${Spell[Deltro's Mending].RankName}
	}
|-Pet Heal*
	/if (${Me.Level}>=${Spell[Salve of Artikla].Level} && ${Me.Book[${Spell[Salve of Artikla].RankName}]}) {
		/varset PetHealSpell ${Spell[Salve of Artikla].RankName}
	}
|-ATK Buff*
	/if (${Me.Level}>=${Spell[Shared Merciless Ferocity].Level} && ${Me.Book[${Spell[Shared Merciless Ferocity].RankName}]}) {
		/varset AtkBuff ${Spell[Shared Merciless Ferocity].RankName}
	}
|--- Pet*
	/if (${Me.Level}>=${Spell[Spirit of Akalit].Level} && ${Me.Book[${Spell[Spirit of Akalit].RankName}]}) {
		/varset PetSpell ${Spell[Spirit of Akalit].RankName}
	}
 |-Focus*
	/if (${Me.Level}>=${Spell[Focus of Artikla].Level} && ${Me.Book[${Spell[Focus of Artikla].RankName}]}) {
		/varset FocusSpell ${Spell[Focus of Artikla].RankName}
	}
 |- Unity Mana/Hp/End Regen + Atk/HP Buff*
	/if (${Me.Level}>=${Spell[Feralist's Unity].Level} && ${Me.Book[${Spell[Feralist's Unity].RankName}]}) {
		/varset UnityBuff ${Spell[Feralist's Unity].RankName}
	}
 |-Mana/Hp/End Regen Buff*
	/if (${Me.Level}>=${Spell[Spiritual Empowerment].Level} && ${Me.Book[${Spell[Spiritual Empowerment].RankName}]}) {
		/varset ManaRegenBuff ${Spell[Spiritual Empowerment].RankName}
	}
 |-Atk+HP Buff*
	/if (${Me.Level}>=${Spell[Spiritual Vibrancy].Level} && ${Me.Book[${Spell[Spiritual Vibrancy].RankName}]}) {
		/varset AtkHPBuff ${Spell[Spiritual Vibrancy].RankName}
	}
 |-Pet Dmg Absorb + HoT buff*
	/if (${Me.Level}>=${Spell[Natural Cooperation].Level} && ${Me.Book[${Spell[Natural Cooperation].RankName}]}) {
		/varset KillShotBuff ${Spell[Natural Cooperation].RankName}
	}
 |-Runspeed* 
	/if (${Me.Level}>=${Spell[Spirit of Tala'Tak].Level} && ${Me.Book[${Spell[Spirit of Tala'Tak].RankName}]}) {
		/varset RunSpeedBuff ${Spell[Spirit of Tala'Tak].RankName}
	}
|-Pet Buffs
 |-Pet Group End Regen Proc*
	/if (${Me.Level}>=${Spell[Exhausting Bite].Level} && ${Me.Book[${Spell[Exhausting Bite].RankName}]}) {
		/varset PetEnduranceProc ${Spell[Exhausting Bite].RankName}
	}
 |-Pet Growl Buff*
	/if (${Me.Level}>=${Spell[Growl of the Sabretooth].Level} && ${Me.Book[${Spell[Growl of the Sabretooth].RankName}]}) {
		/varset PetGrowl ${Spell[Growl of the Sabretooth].RankName}
	}
 |-Pet Mitigate Spell Damage*
	/if (${Me.Level}>=${Spell[Spellbreaker's Keep].Level} && ${Me.Book[${Spell[Spellbreaker's Keep].RankName}]}) {
		/varset PetSpellGuard ${Spell[Spellbreaker's Keep].RankName}
	}
 |-Pet Slow Proc*
	/if (${Me.Level}>=${Spell[Deadlock Jaws].Level} && ${Me.Book[${Spell[Deadlock Jaws].RankName}]}) {
		/varset PetSlowProc ${Spell[Deadlock Jaws].RankName}
	}
 |-Pet DPS buff*
	/if (${Me.Level}>=${Spell[Virzak's Aggression].Level} && ${Me.Book[${Spell[Virzak's Aggression].RankName}]}) {
		/varset PetOffenseBuff ${Spell[Virzak's Aggression].RankName}
	}
 |-Pet Tanking buff*
	/if (${Me.Level}>=${Spell[Virzak's Protection].Level} && ${Me.Book[${Spell[Virzak's Protection].RankName}]}) {
		/varset PetDefenseBuff ${Spell[Virzak's Protection].RankName}
	}
 |-Pet Haste*
	/if (${Me.Level}>=${Spell[Tremendous Velocity].Level} && ${Me.Book[${Spell[Tremendous Velocity].RankName}]}) {
		/varset PetHaste ${Spell[Tremendous Velocity].RankName}
	}
 |-Pet Heal proc buff*
	/if (${Me.Level}>=${Spell[Convivial Warder].Level} && ${Me.Book[${Spell[Convivial Warder].RankName}]}) {
		/varset PetHealProc ${Spell[Convivial Warder].RankName}
	}
 |-Pet Damage Proc Buff*
	/if (${Me.Level}>=${Spell[Spirit of Beramos].Level} && ${Me.Book[${Spell[Spirit of Beramos].RankName}]}) {
		/varset PetDamageProc ${Spell[Spirit of Beramos].RankName}
	}
/return

|----------------------------------------------------------------------------
|- SUB: SetupDiscs
|---------------------------------------------------------------------------- 
Sub SetupDiscs
|------Discs*
	/if (${Me.Level}>=${Spell[Mangle].Level} && ${Me.CombatAbility[${Spell[Mangle].RankName}]}) {
		/varset Maul ${Spell[Mangle].RankName}
	}
|-AE Claws*
	/if (${Me.Level}>=${Spell[Storm of Claws].Level} && ${Me.CombatAbility[${Spell[Storm of Claws].RankName}]}) {
		/varset AEClaws ${Spell[Storm of Claws].RankName}
	}
|-Single target claws*
	/if (${Me.Level}>=${Spell[Focused Clamor of Claws].Level} && ${Me.CombatAbility[${Spell[Focused Clamor of Claws].RankName}]}) {
		/varset SingleClaws ${Spell[Focused Clamor of Claws].RankName}
	}
|-Beastial Buff*
	/if (${Me.Level}>=${Spell[Bestial Savagery].Level} && ${Me.CombatAbility[${Spell[Bestial Savagery].RankName}]}) {
		/varset BeastialBuffDisc ${Spell[Bestial Savagery].RankName}
	}
|-HHE Burn Disc*
	/if (${Me.Level}>=${Spell[Ruaabri's Fury].Level} && ${Me.CombatAbility[${Spell[Ruaabri's Fury].RankName}]}) {
		/varset HHEFuryDisc ${Spell[Ruaabri's Fury].RankName}
	}
|-All Skills Damage Modifier*
	/if (${Me.Level}>=${Spell[Savage Rancor].Level} && ${Me.CombatAbility[${Spell[Savage Rancor].RankName}]}) {
		/varset DmgModDisc ${Spell[Savage Rancor].RankName}
	}
|-Group End Regen*
	/if (${Me.Level}>=${Spell[Reflexive Sundering].Level} && ${Me.CombatAbility[${Spell[Reflexive Sundering].RankName}]}) {
		/varset EndRegenProcDisc ${Spell[Reflexive Sundering].RankName}
	}
|-End Regen*
	/if (${Me.Level}>=${Spell[Breather].Level} && ${Me.CombatAbility[${Spell[Breather].RankName}]}) {
		/varset EndRegenDisc ${Spell[Breather].RankName}
	}
/return

|----------------------------------------------------------------------------
|- SUB: Bind Change Var Int resets various interger settings from ini file
|----------------------------------------------------------------------------
Sub Bind_SetVarInt(string ISection, string IName, int IVar)
    /docommand /varset changetoini 1
	
|-Toggles
	/if (${ISection.Equal[Toggle]}) {
|-doHeals	
		/if (${IName.Equal[DoHeals]}) {
			/if (!${DoHeals}) {
				 /echo \aw Setting DoHeals to \ag ON
				 /varset DoHeals 1
			 } else {
				 /echo \aw Resetting DoHeals to \ar OFF
				 /varset DoHeals 0
				}
|-UsePet
			} else /if (${IName.Equal[UsePet]}) {
				/if (!${UsePet}) {
				 /echo \aw Setting UsePet to \ag ON
				 /varset UsePet 1
			 } else {
				 /echo \aw Resetting UsePet to \ar OFF
				 /varset UsePet 0
				}	 
|-UseSwarmPet			
			} else /if (${IName.Equal[UseSwarmpet]}) {
				/if (!${UseSwarmpet}) {
				 /echo \aw Setting UseSwarmpet to \ag ON
				 /varset UseSwarmpet 1
			 } else {
				 /echo \aw Resetting UseSwarmpet to \ar OFF
				 /varset UseSwarmpet 0
				}		
|-Mezbreak
		 } else /if (${IName.Equal[AllowMezBreak]}) {
			/if (!${AllowMezBreak}) {
				/echo \aw Setting AllowMezBreak to \ag ON
				/varset AllowMezBreak 1
			} else {
				/echo \aw Resetting AllowMezBreak to \ar OFF
				/varset AllowMezBreak 0
			}
|-UseAoE
		} else /if (${IName.Equal[UseAoE]}) {
			/if (!${UseAoE}) {
				/echo \aw Setting UseAoE to \ag ON
				/varset UseAoE 1
			} else {
				/echo \aw Resetting UseAoE to \ar OFF
				/varset UseAoE 0
			}
|-DoDot
		} else /if (${IName.Equal[DoDot]}) {
			/if (!${DoDot}) {
				/echo \aw Setting DoDot to \ag ON
				/varset DoDot 1
				/call LoadSpellBar
			} else {
				/echo \aw Resetting DoDot to \ar OFF
				/varset DoDot 0
				/call LoadSpellBar
			}
|-ChestCombat
		} else /if (${IName.Equal[ChestCombatCast]}) {
			/if (!${ChestCombatCast}) {
				/echo \aw Setting ChestCombatCast to \ag ON
				/varset ChestCombatCast 1
			} else {
				/echo \aw Resetting ChestCombatCast to \ar OFF
				/varset ChestCombatCast 0
			}
|-Use Illusion
		} else /if (${IName.Equal[UseIllusion]}) {
			/if (!${UseIllusion}) {
				/echo \aw Setting UseIllusion to \ag ON
				/varset UseIllusion 1
			} else {
				/echo \aw Resetting UseIllusion to \ar OFF
				/varset UseIllusion 0
			}
|-DoSlow
		} else /if (${IName.Equal[DoSlow]}) {
			/if (!${DoSlow}) {
				/echo \aw Setting DoSlow to \ag ON
				/varset DoSlow 1
			} else {
				/echo \aw Resetting DoSlow to \ar OFF
				/varset DoSlow 0
			}
|-DoFero
		} else /if (${IName.Equal[DoFerocity]}) {
			/if (!${DoFerocity}) {
				/echo \aw Setting DoFerocity to \ag ON
				/varset DoFerocity 1
			} else {
				/echo \aw Resetting DoFerocity to \ar OFF
				/varset DoFerocity 0
			}
|-DoPetSlow
		} else /if (${IName.Equal[DoPetSlow]}) {
			/if (!${DoPetSlow}) {
				/echo \aw Setting DoPetSlow to \ag ON
				/varset DoPetSlow 1
			} else {
				/echo \aw Resetting DoPetSlow to \ar OFF
				/varset DoPetSlow 0
			}
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