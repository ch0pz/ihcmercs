|- ihcshmutil.inc
|- Version 0.1
|- Updated: 5/24/2019
|--------------------------------------------------------------------------------------
|-Setup Variable Environment
|--------------------------------------------------------------------------------------

#warning

Sub ShmSetup
|-Spells
	/declare ShamanAura				string outer NULL
	/declare FocusSpell				string outer NULL
	/declare CanniSpell				string outer NULL
	/declare RunSpeedBuff			string outer NULL
	/declare HasteBuff				string outer NULL
	/declare DichoSpell				string outer NULL
	/declare PetSpell				string outer NULL
	/declare PetBuffSpell			string outer NULL
	/declare RecklessHeal1			string outer NULL
	/declare RecklessHeal2			string outer NULL
	/declare RecklessHeal3			string outer NULL
	/declare AESpiritualHeal		string outer NULL
	/declare RecourseHeal			string outer NULL
	/declare InterventionHeal		string outer NULL
	/declare GroupRenewalHoT		string outer NULL
	/declare CurseDoT1				string outer NULL
	/declare CurseDoT2				string outer NULL
	/declare FastPoisonDoT			string outer NULL
	/declare FastDiseaseDoT			string outer NULL
	/declare TwinHealNuke			string outer NULL
	/declare PoisonNuke				string outer NULL
	/declare FastPoisonNuke			string outer NULL
	/declare FrostNuke				string outer NULL
	/declare ChaoticDoT				string outer NULL
	/declare AllianceBuff			string outer NULL
	/declare GroupHealProcBuff		string outer NULL
	/declare CureSpell				string outer NULL
	/declare PureSpiritSpell		string outer NULL
	/declare SlowSpell				string outer NULL
	/declare AESlowSpell			string outer NULL
	/declare MaloSpell				string outer NULL
	/declare AEMaloSpell			string outer NULL
	/declare GrowthBuff				string outer NULL
	/declare MeleeProcBuff			string outer NULL
	/declare PackSelfBuff			string outer NULL
	/declare SlowProcBuff			string outer NULL
	/declare SelfHealProcBuff		string outer NULL
    /declare OOCRezSpell            string outer NULL
    /declare BattleRezSpell         string outer NULL
|- Misc Variables
	/declare Spell1					string outer NULL
	/declare Spell2					string outer NULL
	/declare Spell3					string outer NULL
	/declare Spell4					string outer NULL
	/declare Spell5					string outer NULL
	/declare Spell6					string outer NULL
	/declare Spell7					string outer NULL
	/declare Spell8					string outer NULL
	/declare Spell9					string outer NULL
	/declare Spell10				string outer NULL
	/declare Spell11				string outer NULL
	/declare Spell12				string outer NULL
	/declare Spell13				string outer NULL
	/declare WasStickOn				int	outer 0
	/declare PatchHealPoint			int outer 44
	/declare PatchHeal2Point		int outer 34
	/declare ClickHealPoint			int outer 35
	/declare HealPoint				int outer 99
	/declare HoTTimer				timer outer 0
	/declare CureTimer				timer outer 0
	/declare CureCheckTimer			timer outer 10s
	/declare SetHoTDurationTimer	int outer 0
	/declare DurationMod			float outer 1
	/declare oldtank				string outer NULL
	/declare oldtankid				string outer NULL
	/declare newtank				int outer 0
	/declare CureMemberCount    	int outer 0
	/declare CureMemberID     		int outer 0
    /declare DotSpell               string outer NULL
    /declare NukeSpell              string outer NULL
|-Special
	/declare EpicSpiritStaff		string outer NULL
	/declare UseEpic 				int outer 0

|-Config Options
	/call LoadCommonConfig
	/call LoadIni Buffs UseAllianceBuff			int 0
	/call LoadIni Buffs UseAura					int 1
	/call LoadIni Buffs UseFocus				int 1
	/call LoadIni Buffs UseGrowthBuff			int 1
	/call LoadIni Buffs UseHaste				int 1
	/call LoadIni Buffs UseRunSpeed				int 1
	/call LoadIni Combat AllowMezBreak		 	int 0
	/call LoadIni Combat DoDot					int 0
	/call LoadIni Combat Manatonuke				int 5
	/call LoadIni Combat StickHow				string behind
	/call LoadIni Combat StopNukeAggro			int 80
	/call LoadIni Combat UseAoE					int 0
	/call LoadIni Combat UseMelee		 		int 0
	/call LoadIni Combat UseRoar		 		int 1
	/call LoadIni Combat UseProcBuff		 	int 0
	/call LoadIni Debuff AutoDebuffAt			int 99
	/call LoadIni Debuff DoMalo					int 1
	/call LoadIni Debuff DoAEMalo				int 1
	/call LoadIni Debuff DoRoot					int 1
	/call LoadIni Debuff DoAERoot				int 1
	/call LoadIni Debuff DoSlow					int 1
	/call LoadIni Debuff DoAESlow				int 1
	/call LoadIni General DoAACanni				int 1
	/call LoadIni General AACanniManaPct		int 70
	/call LoadIni General AACanniMinHP			int 70
	/call LoadIni General DoSpellCanni			int 1
	/call LoadIni General CanniManaPct			int 90
	/call LoadIni General CanniMinHP			int 60
	/call LoadIni Healing DoCures				int 0
	/call LoadIni Healing DoHeals				int 1
	/call LoadIni Healing DoHoTs				int 1
	/call LoadIni Healing CureOther				int 0
	/call LoadIni Healing DynamicHealing		int 1
	/call LoadIni Healing BigHealPoint			int 70
	/call LoadIni Healing GroupHealPoint		int 80
	/call LoadIni Healing GroupHealCount		int 2
	/call LoadIni Healing HoTHealPoint			int 95
	/call LoadIni Healing PetHealPoint			int 30 
	/call LoadIni Healing RaidHealPoint			int 65
	/call LoadIni Healing TankHealPoint			int 90
	/call LoadIni Healing TBMHealPoint			int 65
    /call LoadIni Healing UseBattleRez          int 0
    /call LoadIni Healing AutoRez               int 1
	/call LoadIni Item ChestItemName			string "${Me.Inventory[17].Name}"
	/call LoadIni Item ChestCombatCast			int 0
	/call LoadIni Options BringYourOwnSpells	int 0
    /call LoadIni Options RetryRezDelay 		int 30
	/call LoadIni Pet UsePet		 			int 1
	/call LoadIni Pet UseSwarmpet		 		int 0
	/if (${Me.AltAbility[Spell Casting Reinforcement].Rank}==1) /varset DurationMod 1.15
    /if (${Me.AltAbility[Spell Casting Reinforcement].Rank}==2) /varset DurationMod 1.3
    /if (${Me.AltAbility[Spell Casting Reinforcement].Rank}==3) /varset DurationMod 1.5
    /if (${Me.AltAbility[Spell Casting Reinforcement].Rank}==4) /varset DurationMod 1.7
    /if (${Me.AltAbility[Spell Casting Reinforcement].Rank}==5) /varset DurationMod 1.9
|- Check for epic
	/if (${FindItem[=Crafted Talisman of Fates].ID}) {
		/varset EpicSpiritStaff	Crafted Talisman of Fates	
		/varset UseEpic 1
	} else /if (${FindItem[=Blessed Spiritstaff of the Heyokah].ID}) {
		/varset EpicSpiritStaff	Blessed Spiritstaff of the Heyokah
		/varset UseEpic 1
	}
|-Declare spell variables
	/declare spellmisc 			int outer 8
	/declare GroupBuffRecast 	int outer 0
	/declare miscspellremem		string outer NULL
	/declare tempid				string outer NULL
	/declare CastResult         string outer
	/declare spellrememtimer	timer outer 0
	/declare ReadyToCast	  	timer outer 0
	/declare groupbufftimer		timer outer 0
	/declare reztimer			timer outer 0
	/if (${Me.AltAbility[Mnemonic Retention].Rank}==5) /varset spellmisc 13
	/if (${Me.AltAbility[Mnemonic Retention].Rank}==4) /varset spellmisc 12
	/if (${Me.AltAbility[Mnemonic Retention].Rank}==3) /varset spellmisc 11
	/if (${Me.AltAbility[Mnemonic Retention].Rank}==2) /varset spellmisc 10
	/if (${Me.AltAbility[Mnemonic Retention].Rank}==1) /varset spellmisc 9
|-	/if (${DoHeals}) /call CheckPlugin MQ2WorstHurt
|-	/if (${Me.AltAbility[8300].Name.Find[disabled]} && ${Me.AltAbilityReady[8300]}) {
|-		/alt act 8300
|-		/delay 5
|-	}
/return 
Sub ClassAliasSetup
|-Create Class Aliases 
	|-- Toggles
	/squelch /alias /byos			/setvarint Toggle BringYourOwnSpells
	/squelch /alias /tglaoe			/setvarint Toggle UseAoE
	/squelch /alias /tglbp			/setvarint Toggle ChestCombatCast
	/squelch /alias /tglpet			/setvarint Toggle UsePet
	/squelch /alias /tglpoison		/setvarint Toggle UsePoisons
	/squelch /alias /tgldots		/setvarint Toggle DoDot
	/squelch /alias /tglmezbreak	/setvarint Toggle AllowMezBreak
	/squelch /alias /tglslow		/setvarint Toggle DoSlow
    /squelch /alias /tglbrez        /setvarint Toggle UseBattleRez
    /squelch /alias /tglps          /setvarint Toggle CureOther
    /squelch /alias /tglcure        /setvarint Toggle DoCures
	/call AliasSetup
	/call SetIni General IHCMacVersion			string ${IHCVersion}
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
    /call SetIni Healing UseBattleRez           int ${UseBattleRez}
    /call SetIni Healing DoCures                int ${DoCures}
	/call SetIni Item ChestCombatCast			int ${ChestCombatCast}
	/call SetIni Options BringYourOwnSpells		int ${BringYourOwnSpells}
	/call SetIni Pet UsePet		 				int ${UsePet}
	/call SetIni Pet UseSwarmpet		 		int ${UseSwarmpet}
/return
|* ------------------------------------------------------------------------------------------
| SUB: LoadSpellBar
|------------------------------------------------------------------------------------------ *|
Sub LoadSpellBar
	/if (!${BringYourOwnSpells}) {
		/if (${Me.Standing}) /sit
		/delay 10 ${Me.Sitting}
		/echo \aw Loading Spell Bar
		/call LoadSpellGem "${Spell1}" 1
		/call LoadSpellGem "${Spell2}" 2
		/call LoadSpellGem "${Spell3}" 3
		/call LoadSpellGem "${Spell4}" 4
		/call LoadSpellGem "${Spell5}" 5
		/call LoadSpellGem "${Spell6}" 6
		/call LoadSpellGem "${Spell7}" 7
		/call LoadSpellGem "${Spell8}" 8
		/if (${spellmisc}>8) {
			/call LoadSpellGem "${Spell9}" 9
		}
		/if (${spellmisc}>9) {
			/call LoadSpellGem "${Spell10}" 10
		}
		/if (${spellmisc}>10) {
			/call LoadSpellGem "${Spell11}" 11
		}
		/if (${spellmisc}>11) {
			/call LoadSpellGem "${Spell12}" 12
		}
		/if (${spellmisc}>12) {
        
            |-  We need to dynamically reload the cure spell based on if CureOther is set
            |- Cures are targeted for Spell Slot 13.
            /if (${CureOther}) {
                /varset Spell13 ${PureSpiritSpell}
            } else {
                /varset Spell13 ${CureSpell}
            }
            
			/call LoadSpellGem "${Spell13}" 13
		}
	}
	/if (${Me.Sitting}) /stand
	/delay 10 ${Me.Standing}
/return 
|----------------------------------------------------------------------------
|- SUB: CheckSpells
|---------------------------------------------------------------------------- 
Sub CheckSpells
|-*
|-	/if (${Me.Level}>=${Spell[].Level} && ${Me.Book[${Spell[].RankName}]}) {
|-		/varset  ${Spell[].RankName}
|-	} else /if (${Me.Level}>=${Spell[].Level} && ${Me.Book[${Spell[].RankName}]}) {
|-		/varset  ${Spell[].RankName}
|-	}

|- SelfHealProcBuff = Self Heal Ward Spells -- LVL 115 -> LVL 80
	/if (${Me.Level}>=${Spell[Ward of Recuperation].Level} && ${Me.Book[${Spell[Ward of Recuperation].RankName}]}) {
		/varset SelfHealProcBuff ${Spell[Ward of Recuperation].RankName}
	} else /if (${Me.Level}>=${Spell[Ward of Remediation].Level} && ${Me.Book[${Spell[Ward of Remediation].RankName}]}) {
		/varset SelfHealProcBuff ${Spell[Ward of Remediation].RankName}
	} else /if (${Me.Level}>=${Spell[Ward of Regeneration].Level} && ${Me.Book[${Spell[Ward of Regeneration].RankName}]}) {
		/varset SelfHealProcBuff ${Spell[Ward of Regeneration].RankName}
	} else /if (${Me.Level}>=${Spell[Ward of Rejuvenation].Level} && ${Me.Book[${Spell[Ward of Rejuvenation].RankName}]}) {
		/varset SelfHealProcBuff ${Spell[Ward of Rejuvenation].RankName}
	} else /if (${Me.Level}>=${Spell[Ward of Reconstruction].Level} && ${Me.Book[${Spell[Ward of Reconstruction].RankName}]}) {
		/varset SelfHealProcBuff ${Spell[Ward of Reconstruction].RankName}
	} else /if (${Me.Level}>=${Spell[Ward of Recovery].Level} && ${Me.Book[${Spell[Ward of Recovery].RankName}]}) {
		/varset SelfHealProcBuff ${Spell[Ward of Recovery].RankName}
	} else /if (${Me.Level}>=${Spell[Ward of Restoration].Level} && ${Me.Book[${Spell[Ward of Restoration].RankName}]}) {
		/varset SelfHealProcBuff ${Spell[Ward of Restoration].RankName}
	} else /if (${Me.Level}>=${Spell[Ward of Resurgence].Level} && ${Me.Book[${Spell[Ward of Resurgence].RankName}]}) {
		/varset SelfHealProcBuff ${Spell[Ward of Resurgence].RankName}
	}

|- CanniSpell 115 -> Start
	/if (${Me.Level}>=${Spell[Ancient Bargain].Level} && ${Me.Book[${Spell[Ancient Bargain].RankName}]}) {
		/varset CanniSpell ${Spell[Ancient Bargain].RankName}
	} else /if (${Me.Level}>=${Spell[Tribal Bargain].Level} && ${Me.Book[${Spell[Tribal Bargain].RankName}]}) {
		/varset CanniSpell ${Spell[Tribal Bargain].RankName}
	} else /if (${Me.Level}>=${Spell[Tribal Pact].Level} && ${Me.Book[${Spell[Tribal Pact].RankName}]}) {
		/varset CanniSpell ${Spell[Tribal Pact].RankName}
	} else /if (${Me.Level}>=${Spell[Ancestral Pact].Level} && ${Me.Book[${Spell[Ancestral Pact].RankName}]}) {
		/varset CanniSpell ${Spell[Ancestral Pact].RankName}
	} else /if (${Me.Level}>=${Spell[Ancestral Arrangement].Level} && ${Me.Book[${Spell[Ancestral Arrangement].RankName}]}) {
		/varset CanniSpell ${Spell[Ancestral Arrangement].RankName}
	} else /if (${Me.Level}>=${Spell[Ancestral Covenant].Level} && ${Me.Book[${Spell[Ancestral Covenant].RankName}]}) {
		/varset CanniSpell ${Spell[Ancestral Covenant].RankName}
	} else /if (${Me.Level}>=${Spell[Ancestral Obligation].Level} && ${Me.Book[${Spell[Ancestral Obligation].RankName}]}) {
		/varset CanniSpell ${Spell[Ancestral Obligation].RankName}
	} else /if (${Me.Level}>=${Spell[Ancestral Hearkening].Level} && ${Me.Book[${Spell[Ancestral Hearkening].RankName}]}) {
		/varset CanniSpell ${Spell[Ancestral Hearkening].RankName}
	} else /if (${Me.Level}>=${Spell[Ancestral Bargain].Level} && ${Me.Book[${Spell[Ancestral Bargain].RankName}]}) {
		/varset CanniSpell ${Spell[Ancestral Bargain].RankName}
	} else /if (${Me.Level}>=${Spell[Ancient Ancestra Calling].Level} && ${Me.Book[${Spell[Ancient Ancestra Calling].RankName}]}) {
		/varset CanniSpell ${Spell[Ancient Ancestra Calling].RankName}
	} else /if (${Me.Level}>=${Spell[Pained Memory].Level} && ${Me.Book[${Spell[Pained Memory].RankName}]}) {
		/varset CanniSpell ${Spell[Pained Memory].RankName}
	} else /if (${Me.Level}>=${Spell[Ancient Chaotic Pain].Level} && ${Me.Book[${Spell[Ancient Chaotic Pain].RankName}]}) {
		/varset CanniSpell ${Spell[Ancient Chaotic Pain].RankName}
	} else /if (${Me.Level}>=${Spell[Cannibalize IV].Level} && ${Me.Book[${Spell[Cannibalize IV].RankName}]}) {
		/varset CanniSpell ${Spell[Cannibalize IV].RankName}
	} else /if (${Me.Level}>=${Spell[Cannibalize III].Level} && ${Me.Book[${Spell[Cannibalize III].RankName}]}) {
		/varset CanniSpell ${Spell[Cannibalize III].RankName}
	} else /if (${Me.Level}>=${Spell[Cannibalize II].Level} && ${Me.Book[${Spell[Cannibalize II].RankName}]}) {
		/varset CanniSpell ${Spell[Cannibalize II].RankName}
	} else /if (${Me.Level}>=${Spell[Cannibalize].Level} && ${Me.Book[${Spell[Cannibalize].RankName}]}) {
		/varset CanniSpell ${Spell[Cannibalize].RankName}
	}  
|- ShamanAura
	/if (${Me.AltAbility[Pact of the Wolf].ID}) {
		/varset ShamanAura Pact of the Wolf
	}
|- FocusSpell
	/if (${Me.Level}>=${Spell[Talisman of the Ry'Gorr].Level} && ${Me.Book[${Spell[Talisman of the Ry'Gorr].RankName}]}) {
		/varset FocusSpell ${Spell[Talisman of the Ry'Gorr].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Wulthan].Level} && ${Me.Book[${Spell[Talisman of the Wulthan].RankName}]}) {
		/varset FocusSpell ${Spell[Talisman of the Wulthan].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Doomscale].Level} && ${Me.Book[${Spell[Talisman of the Doomscale].RankName}]}) {
		/varset FocusSpell ${Spell[Talisman of the Doomscale].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Courageous].Level} && ${Me.Book[${Spell[Talisman of the Courageous].RankName}]}) {
		/varset FocusSpell ${Spell[Talisman of the Courageous].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of Kolos' Unity].Level} && ${Me.Book[${Spell[Talisman of Kolos' Unity].RankName}]}) {
		/varset FocusSpell ${Spell[Talisman of Kolos' Unity].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of Soul's Unity].Level} && ${Me.Book[${Spell[Talisman of Soul's Unity].RankName}]}) {
		/varset FocusSpell ${Spell[Talisman of Soul's Unity].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of Unity].Level} && ${Me.Book[${Spell[Talisman of Unity].RankName}]}) {
		/varset FocusSpell ${Spell[Talisman of Unity].RankName}
	}
|- RunSpeedBuff
	/if (${Me.Level}>=${Spell[Spirit of Tala'Tak].Level} && ${Me.Book[${Spell[Spirit of Tala'Tak].RankName}]}) {
		/varset RunSpeedBuff ${Spell[Spirit of Tala'Tak].RankName}
	} else /if (${Me.Level}>=${Spell[Spirit of Bih`Li].Level} && ${Me.Book[${Spell[Spirit of Bih`Li].RankName}]}) {
		/varset RunSpeedBuff ${Spell[Spirit of Bih`Li].RankName}
	} else /if (${Me.Level}>=${Spell[Pack Shrew].Level} && ${Me.Book[${Spell[Pack Shrew].RankName}]}) {
        /varset RunSpeedBuff ${Spell[Pack Shrew].RankName}
    }
|- HasteBuff |- AA to Start
	/if (${Me.AltAbility[Talisman of Celerity].ID}) {
		/varset HasteBuff Talisman of Celerity
	} else /if (${Me.Level}>=${Spell[Talisman of Celerity].Level} && ${Me.Book[${Spell[Talisman of Celerity].RankName}]}) {
		/varset HasteBuff ${Spell[Talisman of Celerity].RankName}
	} else /if (${Me.Level}>=${Spell[Swift Like the Wind].Level} && ${Me.Book[${Spell[Swift Like the Wind].RankName}]}) {
		/varset HasteBuff ${Spell[Swift Like the Wind].RankName}
	} else /if (${Me.Level}>=${Spell[Celerity].Level} && ${Me.Book[${Spell[Celerity].RankName}]}) {
		/varset HasteBuff ${Spell[Celerity].RankName}
	} else /if (${Me.Level}>=${Spell[Alacrity].Level} && ${Me.Book[${Spell[Alacrity].RankName}]}) {
		/varset HasteBuff ${Spell[Alacrity].RankName}
	} else /if (${Me.Level}>=${Spell[Quickness].Level} && ${Me.Book[${Spell[Quickness].RankName}]}) {
		/varset HasteBuff ${Spell[Quickness].RankName}
	}
|- DichoSpell
	/if (${Me.Level}>=${Spell[Dissident Roar].Level} && ${Me.Book[${Spell[Dissident Roar].RankName}]}) {
		/varset DichoSpell ${Spell[Dissident Roar].RankName}
	} else /if (${Me.Level}>=${Spell[Roar of the Lion].Level} && ${Me.Book[${Spell[Roar of the Lion].RankName}]}) {
		/varset DichoSpell ${Spell[Roar of the Lion].RankName}
	}

|- PetSpell LVL112 - First Spell
    /if (${Me.Level}>=${Spell[Grondo's Faithful].Level} && ${Me.Book[${Spell[Grondo's Faithful].RankName}]}) {
		/varset PetSpell ${Spell[Grondo's Faithful].RankName}
	} else /if (${Me.Level}>=${Spell[Mirtuk's Faithful].Level} && ${Me.Book[${Spell[Mirtuk's Faithful].RankName}]}) {
		/varset PetSpell ${Spell[Mirtuk's Faithful].RankName}
	} else /if (${Me.Level}>=${Spell[Olesira's Faithful].Level} && ${Me.Book[${Spell[Olesira's Faithful].RankName}]}) {
		/varset PetSpell ${Spell[Olesira's Faithful].RankName}
	} else /if (${Me.Level}>=${Spell[Kriegas' Faithful].Level} && ${Me.Book[${Spell[Kriegas' Faithful].RankName}]}) {
		/varset PetSpell ${Spell[Kriegas' Faithful].RankName}
	} else /if (${Me.Level}>=${Spell[Hilnaah's Faithful].Level} && ${Me.Book[${Spell[Hilnaah's Faithful].RankName}]}) {
		/varset PetSpell ${Spell[Hilnaah's Faithful].RankName}
	} else /if (${Me.Level}>=${Spell[Wurt's Faithful].Level} && ${Me.Book[${Spell[Wurt's Faithful].RankName}]}) {
		/varset PetSpell ${Spell[Wurt's Faithful].RankName}
	} else /if (${Me.Level}>=${Spell[Aina's Faithful].Level} && ${Me.Book[${Spell[Aina's Faithful].RankName}]}) {
		/varset PetSpell ${Spell[Aina's Faithful].RankName}
	} else /if (${Me.Level}>=${Spell[Vegu's Faithful].Level} && ${Me.Book[${Spell[Vegu's Faithful].RankName}]}) {
		/varset PetSpell ${Spell[Vegu's Faithful].RankName}
	} else /if (${Me.Level}>=${Spell[Kyrah's Faithful].Level} && ${Me.Book[${Spell[Kyrah's Faithful].RankName}]}) {
		/varset PetSpell ${Spell[Kyrah's Faithful].RankName}
	} else /if (${Me.Level}>=${Spell[Farrel's Companion].Level} && ${Me.Book[${Spell[Farrel's Companion].RankName}]}) {
		/varset PetSpell ${Spell[Farrel's Companion].RankName}
	} else /if (${Me.Level}>=${Spell[True Spirit].Level} && ${Me.Book[${Spell[True Spirit].RankName}]}) {
		/varset PetSpell ${Spell[True Spirit].RankName}
	} else /if (${Me.Level}>=${Spell[Spirit of the Howler].Level} && ${Me.Book[${Spell[Spirit of the Howler].RankName}]}) {
		/varset PetSpell ${Spell[Spirit of the Howler].RankName}
	} else /if (${Me.Level}>=${Spell[Frenzied Spirit].Level} && ${Me.Book[${Spell[Frenzied Spirit].RankName}]}) {
		/varset PetSpell ${Spell[Frenzied Spirit].RankName}
	} else /if (${Me.Level}>=${Spell[Guardian spirit].Level} && ${Me.Book[${Spell[Guardian spirit].RankName}]}) {
		/varset PetSpell ${Spell[Guardian spirit].RankName}
	} else /if (${Me.Level}>=${Spell[Vigilant Spirit].Level} && ${Me.Book[${Spell[Vigilant Spirit].RankName}]}) {
		/varset PetSpell ${Spell[Vigilant Spirit].RankName}
	} else /if (${Me.Level}>=${Spell[Companion Spirit].Level} && ${Me.Book[${Spell[Companion Spirit].RankName}]}) {
		/varset PetSpell ${Spell[Companion Spirit].RankName}
	}
|- PetBuffSpell LVL 112 - Start
	/if (${Me.Level}>=${Spell[Spirit Bracing].Level} && ${Me.Book[${Spell[Spirit Bracing].RankName}]}) {
		/varset PetBuffSpell ${Spell[Spirit Bracing].RankName}
	} else /if (${Me.Level}>=${Spell[Spirit Bolstering].Level} && ${Me.Book[${Spell[Spirit Bolstering].RankName}]}) {
		/varset PetBuffSpell ${Spell[Spirit Bolstering].RankName}
	} else /if (${Me.Level}>=${Spell[Spirit Quickening].Level} && ${Me.Book[${Spell[Spirit Quickening].RankName}]}) {
		/varset PetBuffSpell ${Spell[Spirit Quickening].RankName}
	}
    
|- OOC Rez Spell - LVL59 AA @ lvl 100 for full 96%
    /if (${Me.AltAbility[Rejuvenation Of Spirit].ID}) {
		/varset OOCRezSpell Rejuvenation of Spirit
    } else /if (${Me.Level}>=${Spell[Incarnate Anew].Level} && ${Me.Book[${Spell[Incarnate Anew].RankName}]}) {
		/varset OOCRezSpell ${Spell[Incarnate Anew].RankName}
	}
    
|- Battle Rez Spell LVL LVL70
    /if (${Me.AltAbility[Call of the Wild].ID}) {
		/varset BattleRezSpell Call of the Wild
	}

|-----------------------------------------------------------------------------------------------------------------------
|- The Reckless Heals are the variables used for normal healing within IHCSHM for levels below 100, RecklessHeal1 and
|- RecklessHeal2 will be replaced with normal in-combat healing spells. RecklessHeal1 will be the highest level healing
|- spell at a given point with RecklesHeal2 being the second highest level healing spell. This is stagged in a similar
|- manner to the reckless line.

|- RecklessHeal1
	/if (${Me.Level}>=115 && ${Me.Book[${Spell[Reckless Renewal].RankName}]}) {
		/varset RecklessHeal1 ${Spell[Reckless Renewal].RankName}
	} else /if (${Me.Level}>=110 && ${Me.Book[${Spell[Reckless Rejuvenation].RankName}]}) {
		/varset RecklessHeal1 ${Spell[Reckless Rejuvenation].RankName}
	} else /if (${Me.Level}>=105 && ${Me.Book[${Spell[Reckless Regeneration].RankName}]}) {
		/varset RecklessHeal1 ${Spell[Reckless Regeneration].RankName}
	} else /if (${Me.Level}>=100 && ${Me.Book[${Spell[Reckless Restoration].RankName}]}) {
		/varset RecklessHeal1 ${Spell[Reckless Restoration].RankName}
	} else /if (${Me.Level}>=95 && ${Me.Book[${Spell[Reckless Remedy].RankName}]}) {
		/varset RecklessHeal1 ${Spell[Reckless Remedy].RankName}
	} else /if (${Me.Level}>=90 && ${Me.Book[${Spell[Reckless Mending].RankName}]}) {
		/varset RecklessHeal1 ${Spell[Reckless Mending].RankName}
	} else /if (${Me.Level}>=88 && ${Me.Book[${Spell[Qirik's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Qirik's Mending].RankName}
    } else /if (${Me.Level}>=83 && ${Me.Book[${Spell[Dannal's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Dannal's Mending].RankName}
    } else /if (${Me.Level}>=78 && ${Me.Book[${Spell[Gemmi's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Gemmi's Mending].RankName}
    } else /if (${Me.Level}>=73 && ${Me.Book[${Spell[Ahnkaul's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Ahnkaul's Mending].RankName}
    } else /if (${Me.Level}>=70 && ${Me.Book[${Spell[Ancient: Wilslik's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Ancient: Wilslik's Mending].RankName}
    } else /if (${Me.Level}>=68 && ${Me.Book[${Spell[Yoppa's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Yoppa's Mending].RankName}
    } else /if (${Me.Level}>=65 && ${Me.Book[${Spell[Daluda's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Daluda's Mending].RankName}
    } else /if (${Me.Level}>=62 && ${Me.Book[${Spell[Tnarg's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Tnarg's Mending].RankName}
    } else /if (${Me.Level}>=58 && ${Me.Book[${Spell[Chloroblast].RankName}]}) {
        |- LVL58 -- Skipping Kragg's Mending because it has a cast time out of sync with all the other
        |- Shaman spells. This probably will only be an issue with EQ Progression servers in the Kunark
        |- era.
        /varset RecklessHeal1 ${Spell[Chloroblast].RankName}
    } else /if (${Me.Level}>=55 && ${Me.Book[${Spell[Chloroblast].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Chloroblast].RankName}
    } else /if (${Me.Level}>=50 && ${Me.Book[${Spell[Kragg's Salve].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Kragg's Salve].RankName}
    } else /if (${Me.Level}>=45 && ${Me.Book[${Spell[Superior Healing].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Superior Healing].RankName}
    } else /if (${Me.Level}>=40 && ${Me.Book[${Spell[Spirit Salve].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Spirit Salve].RankName}
    } else /if (${Me.Level}>=29 && ${Me.Book[${Spell[Greater Healing].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Greater Healing].RankName}
    } else /if (${Me.Level}>=19 && ${Me.Book[${Spell[Healing].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Healing].RankName}
    } else /if (${Me.Level}>=9 && ${Me.Book[${Spell[Light Healing].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Light Healing].RankName}
    } else /if (${Me.Level}>=1 && ${Me.Book[${Spell[Minor Healing].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal1 ${Spell[Minor Healing].RankName}
    }
    
    
|- RecklessHeal2
	/if (${Me.Level}>=115 && ${Me.Book[${Spell[Reckless Rejuvenation].RankName}]}) {
		/varset RecklessHeal2 ${Spell[Reckless Rejuvenation].RankName}
	} else /if (${Me.Level}>=110 && ${Me.Book[${Spell[Reckless Regeneration].RankName}]}) {
		/varset RecklessHeal2 ${Spell[Reckless Regeneration].RankName}
	} else /if (${Me.Level}>=105 && ${Me.Book[${Spell[Reckless Restoration].RankName}]}) {
		/varset RecklessHeal2 ${Spell[Reckless Restoration].RankName}
	} else /if (${Me.Level}>=100 && ${Me.Book[${Spell[Reckless Remedy].RankName}]}) {
		/varset RecklessHeal2 ${Spell[Reckless Remedy].RankName}
	} else /if (${Me.Level}>=95 && ${Me.Book[${Spell[Reckless Mending].RankName}]}) {
		/varset RecklessHeal2 ${Spell[Reckless Mending].RankName}
	} else /if (${Me.Level}>=88 && ${Me.Book[${Spell[Dannal's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Dannal's Mending].RankName}
    } else /if (${Me.Level}>=83 && ${Me.Book[${Spell[Gemmi's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Gemmi's Mending].RankName}
    } else /if (${Me.Level}>=78 && ${Me.Book[${Spell[Ahnkaul's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Ahnkaul's Mending].RankName}
    } else /if (${Me.Level}>=73 && ${Me.Book[${Spell[Ancient: Wilslik's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Ancient: Wilslik's Mending].RankName}
    } else /if (${Me.Level}>=70 && ${Me.Book[${Spell[Yoppa's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Yoppa's Mending].RankName}
    } else /if (${Me.Level}>=68 && ${Me.Book[${Spell[Daluda's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Daluda's Mending].RankName}
    } else /if (${Me.Level}>=65 && ${Me.Book[${Spell[Tnarg's Mending].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Tnarg's Mending].RankName}
    } else /if (${Me.Level}>=62 && ${Me.Book[${Spell[Chloroblast].RankName}]}) { 
        |- LVL62 -- Skipping Kragg's Mending because it has a cast time out of sync with all the other
        |- Shaman spells.
        /varset RecklessHeal2 ${Spell[Chloroblast].RankName}
    } else /if (${Me.Level}>=58 && ${Me.Book[${Spell[Chloroblast].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Chloroblast].RankName}
    } else /if (${Me.Level}>=55 && ${Me.Book[${Spell[Kragg's Salve].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Kragg's Salve].RankName}
    } else /if (${Me.Level}>=50 && ${Me.Book[${Spell[Superior Healing].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Superior Healing].RankName}
    } else /if (${Me.Level}>=45 && ${Me.Book[${Spell[Spirit Salve].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Spirit Salve].RankName}
    } else /if (${Me.Level}>=40 && ${Me.Book[${Spell[Greater Healing].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Greater Healing].RankName}
    } else /if (${Me.Level}>=29 && ${Me.Book[${Spell[Healing].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Healing].RankName}
    } else /if (${Me.Level}>=19 && ${Me.Book[${Spell[Light Healing].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Light Healing].RankName}
    } else /if (${Me.Level}>=9 && ${Me.Book[${Spell[Minor Healing].RankName}]}) { 
        |- SWITCH TO MENDING SERIES
        /varset RecklessHeal2 ${Spell[Minor Healing].RankName}
    }
    
|-----------------------------------------------------------------------------------------------------------------------    
|- As of 01/12/2020 RecklessHeal3 will be deprecated. Keeping these spells here at high levels in case future xpacs
|- require additional healing. 
|- RecklessHeal3
	/if (${Me.Level}>=115 && ${Me.Book[${Spell[Reckless Regeneration].RankName}]}) {
		/varset RecklessHeal3 ${Spell[Reckless Regeneration].RankName}
	} else /if (${Me.Level}>=110 && ${Me.Book[${Spell[Reckless Restoration].RankName}]}) {
		/varset RecklessHeal3 ${Spell[Reckless Restoration].RankName}
	} else /if (${Me.Level}>=105 && ${Me.Book[${Spell[Reckless Remedy].RankName}]}) {
		/varset RecklessHeal3 ${Spell[Reckless Remedy].RankName}
	} else /if (${Me.Level}>=100 && ${Me.Book[${Spell[Reckless Mending].RankName}]}) {
		/varset RecklessHeal3 ${Spell[Reckless Mending].RankName}
	}
|- AESpiritualHeal LVL 115-LVL100
	/if (${Me.Level}>=${Spell[Spiritual Squall].Level} && ${Me.Book[${Spell[Spiritual Squall].RankName}]}) {
		/varset AESpiritualHeal ${Spell[Spiritual Squall].RankName}
	} else /if (${Me.Level}>=${Spell[Spiritual Swell].Level} && ${Me.Book[${Spell[Spiritual Swell].RankName}]}) {
		/varset AESpiritualHeal ${Spell[Spiritual Swell].RankName}
	} else /if (${Me.Level}>=${Spell[Spiritual Surge].Level} && ${Me.Book[${Spell[Spiritual Surge].RankName}]}) {
		/varset AESpiritualHeal ${Spell[Spiritual Surge].RankName}
	}

|- RecourseHeal LVL115-87
	/if (${Me.Level}>=${Spell[Zrelik's Recourse].Level} && ${Me.Book[${Spell[Zrelik's Recourse].RankName}]}) {
		/varset RecourseHeal ${Spell[Zrelik's Recourse].RankName}
	} else /if (${Me.Level}>=${Spell[Eyrzekla's Recourse].Level} && ${Me.Book[${Spell[Eyrzekla's Recourse].RankName}]}) {
		/varset RecourseHeal ${Spell[Eyrzekla's Recourse].RankName}
	} else /if (${Me.Level}>=${Spell[Krasir's Recourse].Level} && ${Me.Book[${Spell[Krasir's Recourse].RankName}]}) {
		/varset RecourseHeal ${Spell[Krasir's Recourse].RankName}
	} else /if (${Me.Level}>=${Spell[Blezon's Recourse].Level} && ${Me.Book[${Spell[Blezon's Recourse].RankName}]}) {
		/varset RecourseHeal ${Spell[Blezon's Recourse].RankName}
	} else /if (${Me.Level}>=${Spell[Gotikan's Recourse].Level} && ${Me.Book[${Spell[Gotikan's Recourse].RankName}]}) {
		/varset RecourseHeal ${Spell[Gotikan's Recourse].RankName}
	} else /if (${Me.Level}>=${Spell[Qirik's Recourse].Level} && ${Me.Book[${Spell[Qirik's Recourse].RankName}]}) {
		/varset RecourseHeal ${Spell[Qirik's Recourse].RankName}
	}

|- InterventionHeal LVL 113 -> 78
	/if (${Me.Level}>=${Spell[Primordial Intervention].Level} && ${Me.Book[${Spell[Primordial Intervention].RankName}]}) {
		/varset InterventionHeal ${Spell[Primordial Intervention].RankName}
	} else /if (${Me.Level}>=${Spell[Prehistoric Intervention].Level} && ${Me.Book[${Spell[Prehistoric Intervention].RankName}]}) {
		/varset InterventionHeal ${Spell[Prehistoric Intervention].RankName}
	} else /if (${Me.Level}>=${Spell[Historian's Intervention].Level} && ${Me.Book[${Spell[Historian's Intervention].RankName}]}) {
		/varset InterventionHeal ${Spell[Historian's Intervention].RankName}
	} else /if (${Me.Level}>=${Spell[Antecessor's Intervention].Level} && ${Me.Book[${Spell[Antecessor's Intervention].RankName}]}) {
		/varset InterventionHeal ${Spell[Antecessor's Intervention].RankName}
	} else /if (${Me.Level}>=${Spell[Progenitor's Intervention].Level} && ${Me.Book[${Spell[Progenitor's Intervention].RankName}]}) {
		/varset InterventionHeal ${Spell[Progenitor's Intervention].RankName}
	} else /if (${Me.Level}>=${Spell[Ascendant's Intervention].Level} && ${Me.Book[${Spell[Ascendant's Intervention].RankName}]}) {
		/varset InterventionHeal ${Spell[Ascendant's Intervention].RankName}
	} else /if (${Me.Level}>=${Spell[Antecedent's Intervention].Level} && ${Me.Book[${Spell[Antecedent's Intervention].RankName}]}) {
		/varset InterventionHeal ${Spell[Antecedent's Intervention].RankName}
	} else /if (${Me.Level}>=${Spell[Ancestral Intervention].Level} && ${Me.Book[${Spell[Ancestral Intervention].RankName}]}) {
		/varset InterventionHeal ${Spell[Ancestral Intervention].RankName}
	}

|- GroupRenewalHoT |- LVL 115->70 -- Prior to 70 Breath of Trushar as a non-group HoTs will be used including the
|- the Torpor/Stoicism line. LVL 44 is the lowest level.

	/if (${Me.Level}>=${Spell[Spectre of Renewal].Level} && ${Me.Book[${Spell[Spectre of Renewal].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Spectre of Renewal].RankName}
	} else /if (${Me.Level}>=${Spell[Cloud of Renewal].Level} && ${Me.Book[${Spell[Cloud of Renewal].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Cloud of Renewal].RankName}
	} else /if (${Me.Level}>=${Spell[Shear of Renewal].Level} && ${Me.Book[${Spell[Shear of Renewal].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Shear of Renewal].RankName}
	} else /if (${Me.Level}>=${Spell[Wisp of Renewal].Level} && ${Me.Book[${Spell[Wisp of Renewal].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Wisp of Renewal].RankName}
	} else /if (${Me.Level}>=${Spell[Phantom of Renewal].Level} && ${Me.Book[${Spell[Phantom of Renewal].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Phantom of Renewal].RankName}
	} else /if (${Me.Level}>=${Spell[Penumbra of Renewal].Level} && ${Me.Book[${Spell[Penumbra of Renewal].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Penumbra of Renewal].RankName}
	} else /if (${Me.Level}>=${Spell[Shadow of Renewal].Level} && ${Me.Book[${Spell[Shadow of Renewal].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Shadow of Renewal].RankName}
	} else /if (${Me.Level}>=${Spell[Shade of Renewal].Level} && ${Me.Book[${Spell[Shade of Renewal].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Shade of Renewal].RankName}
	} else /if (${Me.Level}>=${Spell[Specter of Renewal].Level} && ${Me.Book[${Spell[Specter of Renewal].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Specter of Renewal].RankName}
	} else /if (${Me.Level}>=${Spell[Ghost of Renewal].Level} && ${Me.Book[${Spell[Ghost of Renewal].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Ghost of Renewal].RankName}
	} else /if (${Me.Level}>=${Spell[Breath of Trushar].Level} && ${Me.Book[${Spell[Breath of Trushar].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Breath of Trushar].RankName}
	} else /if (${Me.Level}>=${Spell[Torpor].Level} && ${Me.Book[${Spell[Torpor].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Torpor].RankName}
	} else /if (${Me.Level}>=${Spell[Stoicism].Level} && ${Me.Book[${Spell[Stoicism].RankName}]}) {
		/varset GroupRenewalHoT ${Spell[Stoicism].RankName}
	}
	|- /varset SetHoTDurationTimer ${Math.Calc[((${Spell[${GroupRenewalHoT}].Duration}*6)*${DurationMod})+(${Me.AltAbility[Prolonged Salve].Rank}*6)].Int}

|- CurseDoT1 LVL 115->100

	/if (${Me.Level}>=${Spell[Marlek's Curse].Level} && ${Me.Book[${Spell[Marlek's Curse].RankName}]}) {
		/varset CurseDoT1 ${Spell[Marlek's Curse].RankName}
	} else /if (${Me.Level}>=${Spell[Erogo's Curse].Level} && ${Me.Book[${Spell[Erogo's Curse].RankName}]}) {
		/varset CurseDoT1 ${Spell[Erogo's Curse].RankName}
	} else /if (${Me.Level}>=${Spell[Sraskus' Curse].Level} && ${Me.Book[${Spell[Sraskus' Curse].RankName}]}) {
		/varset CurseDoT1 ${Spell[Sraskus' Curse].RankName}
	} else /if (${Me.Level}>=${Spell[Enalam's Curse].Level} && ${Me.Book[${Spell[Enalam's Curse].RankName}]}) {
		/varset CurseDoT1 ${Spell[Enalam's Curse].RankName}
	}

|- CurseDoT2 LVL115->LVL43
	/if (${Me.Level}>=${Spell[Evil Eye].Level} && ${Me.Book[${Spell[Evil Eye].RankName}]}) {
		/varset CurseDoT2 ${Spell[Evil Eye].RankName}
	} else /if (${Me.Level}>=${Spell[Jinx].Level} && ${Me.Book[${Spell[Jinx].RankName}]}) {
		/varset CurseDoT2 ${Spell[Jinx].RankName}
	} else /if (${Me.Level}>=${Spell[Garugaru].Level} && ${Me.Book[${Spell[Garugaru].RankName}]}) {
		/varset CurseDoT2 ${Spell[Garugaru].RankName}
	} else /if (${Me.Level}>=${Spell[Naganaga].Level} && ${Me.Book[${Spell[Naganaga].RankName}]}) {
		/varset CurseDoT2 ${Spell[Naganaga].RankName}
	} else /if (${Me.Level}>=${Spell[Hoodoo].Level} && ${Me.Book[${Spell[Hoodoo].RankName}]}) {
		/varset CurseDoT2 ${Spell[Hoodoo].RankName}
	} else /if (${Me.Level}>=${Spell[Hex].Level} && ${Me.Book[${Spell[Hex].RankName}]}) {
		/varset CurseDoT2 ${Spell[Hex].RankName}
	} else /if (${Me.Level}>=${Spell[Mojo].Level} && ${Me.Book[${Spell[Mojo].RankName}]}) {
		/varset CurseDoT2 ${Spell[Mojo].RankName}
	} else /if (${Me.Level}>=${Spell[Pocus].Level} && ${Me.Book[${Spell[Pocus].RankName}]}) {
		/varset CurseDoT2 ${Spell[Pocus].RankName}
	} else /if (${Me.Level}>=${Spell[Juju].Level} && ${Me.Book[${Spell[Juju].RankName}]}) {
		/varset CurseDoT2 ${Spell[Juju].RankName}
	} else /if (${Me.Level}>=${Spell[Curse of Sisslak].Level} && ${Me.Book[${Spell[Curse of Sisslak].RankName}]}) {
		/varset CurseDoT2 ${Spell[Curse of Sisslak].RankName}
	} else /if (${Me.Level}>=${Spell[Bane].Level} && ${Me.Book[${Spell[Bane].RankName}]}) {
		/varset CurseDoT2 ${Spell[Bane].RankName}
	} else /if (${Me.Level}>=${Spell[Anathema].Level} && ${Me.Book[${Spell[Anathema].RankName}]}) {
		/varset CurseDoT2 ${Spell[Anathema].RankName}
	} else /if (${Me.Level}>=${Spell[Odium].Level} && ${Me.Book[${Spell[Odium].RankName}]}) {
		/varset CurseDoT2 ${Spell[Odium].RankName}
	}
|- FastPoisonDoT LVL115->LVL89
	/if (${Me.Level}>=${Spell[Xalgoti's Venom].Level} && ${Me.Book[${Spell[Xalgoti's Venom].RankName}]}) {
		/varset FastPoisonDoT ${Spell[Xalgoti's Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Mawmun's Venom].Level} && ${Me.Book[${Spell[Mawmun's Venom].RankName}]}) {
		/varset FastPoisonDoT ${Spell[Mawmun's Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Serpentil's Venom].Level} && ${Me.Book[${Spell[Serpentil's Venom].RankName}]}) {
		/varset FastPoisonDoT ${Spell[Serpentil's Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Banescale's Venom].Level} && ${Me.Book[${Spell[Banescale's Venom].RankName}]}) {
		/varset FastPoisonDoT ${Spell[Banescale's Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Stranglefang's Venom].Level} && ${Me.Book[${Spell[Stranglefang's Venom].RankName}]}) {
		/varset FastPoisonDoT ${Spell[Stranglefang's Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Undaleen's Venom].Level} && ${Me.Book[${Spell[Undaleen's Venom].RankName}]}) {
		/varset FastPoisonDoT ${Spell[Undaleen's Venom].RankName}
	}

|- FastDiseaseDoT LVL115->LVL87
	/if (${Me.Level}>=${Spell[Malvus's Malady].Level} && ${Me.Book[${Spell[Malvus's Malady].RankName}]}) {
		/varset FastDiseaseDoT ${Spell[Malvus's Malady].RankName}
	} else /if (${Me.Level}>=${Spell[Hoshkar's Malady].Level} && ${Me.Book[${Spell[Hoshkar's Malady].RankName}]}) {
		/varset FastDiseaseDoT ${Spell[Hoshkar's Malady].RankName}
	} else /if (${Me.Level}>=${Spell[Sephry's Malady].Level} && ${Me.Book[${Spell[Sephry's Malady].RankName}]}) {
		/varset FastDiseaseDoT ${Spell[Sephry's Malady].RankName}
	} else /if (${Me.Level}>=${Spell[Elsrop's Malady].Level} && ${Me.Book[${Spell[Elsrop's Malady].RankName}]}) {
		/varset FastDiseaseDoT ${Spell[Elsrop's Malady].RankName}
	} else /if (${Me.Level}>=${Spell[Giaborn's Malady].Level} && ${Me.Book[${Spell[Giaborn's Malady].RankName}]}) {
		/varset FastDiseaseDoT ${Spell[Giaborn's Malady].RankName}
	} else /if (${Me.Level}>=${Spell[Nargul's Malady].Level} && ${Me.Book[${Spell[Nargul's Malady].RankName}]}) {
		/varset FastDiseaseDoT ${Spell[Nargul's Malady].RankName}
	}

|- TwinHealNuke LVL115->LVL85
	/if (${Me.Level}>=${Spell[Wintry Gift].Level} && ${Me.Book[${Spell[Wintry Gift].RankName}]}) {
		/varset TwinHealNuke ${Spell[Wintry Gift].RankName}
	} else /if (${Me.Level}>=${Spell[Frostbitten Gift].Level} && ${Me.Book[${Spell[Frostbitten Gift].RankName}]}) {
		/varset TwinHealNuke ${Spell[Frostbitten Gift].RankName}
	} else /if (${Me.Level}>=${Spell[Glacial Gift].Level} && ${Me.Book[${Spell[Glacial Gift].RankName}]}) {
		/varset TwinHealNuke ${Spell[Glacial Gift].RankName}
	} else /if (${Me.Level}>=${Spell[Frigid Gift].Level} && ${Me.Book[${Spell[Frigid Gift].RankName}]}) {
		/varset TwinHealNuke ${Spell[Frigid Gift].RankName}
	} else /if (${Me.Level}>=${Spell[Freezing Gift].Level} && ${Me.Book[${Spell[Freezing Gift].RankName}]}) {
		/varset TwinHealNuke ${Spell[Freezing Gift].RankName}
	} else /if (${Me.Level}>=${Spell[Frozen Gift].Level} && ${Me.Book[${Spell[Frozen Gift].RankName}]}) {
		/varset TwinHealNuke ${Spell[Frozen Gift].RankName}
	} else /if (${Me.Level}>=${Spell[Frost Gift].Level} && ${Me.Book[${Spell[Frost Gift].RankName}]}) {
		/varset TwinHealNuke ${Spell[Frost Gift].RankName}
	}

|- PoisonNuke LVL115->LVL34
	/if (${Me.Level}>=${Spell[Narandi's Spear of Venom].Level} && ${Me.Book[${Spell[Narandi's Spear of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Narandi's Spear of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Nexona's Spear of Venom].Level} && ${Me.Book[${Spell[Nexona's Spear of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Nexona's Spear of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Serisaria's Spear of Venom].Level} && ${Me.Book[${Spell[Serisaria's Spear of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Serisaria's Spear of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Slaunk's Spear of Venom].Level} && ${Me.Book[${Spell[Slaunk's Spear of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Slaunk's Spear of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Hiqork's Spear of Venom].Level} && ${Me.Book[${Spell[Hiqork's Spear of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Hiqork's Spear of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Spinechiller's Spear of Venom].Level} && ${Me.Book[${Spell[Spinechiller's Spear of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Spinechiller's Spear of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Severilous' Spear of Venom].Level} && ${Me.Book[${Spell[Severilous' Spear of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Severilous' Spear of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Vestax's Spear of Venom].Level} && ${Me.Book[${Spell[Vestax's Spear of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Vestax's Spear of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Ahnkaul's Spear of Venom].Level} && ${Me.Book[${Spell[Ahnkaul's Spear of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Ahnkaul's Spear of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Yoppa's Spear of Venom].Level} && ${Me.Book[${Spell[Yoppa's Spear of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Yoppa's Spear of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Spear of Torment].Level} && ${Me.Book[${Spell[Spear of Torment].RankName}]}) {
		/varset PoisonNuke ${Spell[Spear of Torment].RankName}
	} else /if (${Me.Level}>=${Spell[Blast of Venom].Level} && ${Me.Book[${Spell[Blast of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Blast of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Shock of Venom].Level} && ${Me.Book[${Spell[Shock of Venom].RankName}]}) {
		/varset PoisonNuke ${Spell[Shock of Venom].RankName}
	} else /if (${Me.Level}>=${Spell[Blast of Poison].Level} && ${Me.Book[${Spell[Blast of Poison].RankName}]}) {
		/varset PoisonNuke ${Spell[Blast of Poison].RankName}
	} else /if (${Me.Level}>=${Spell[Shock of the Tainted].Level} && ${Me.Book[${Spell[Shock of the Tainted].RankName}]}) {
		/varset PoisonNuke ${Spell[Shock of the Tainted].RankName}
	}
    
|- FastPoisonNuke LVL115->LVL73
	/if (${Me.Level}>=${Spell[Direfang's Bite].Level} && ${Me.Book[${Spell[Direfang's Bite].RankName}]}) {
		/varset FastPoisonNuke ${Spell[Direfang's Bite].RankName}
	} else /if (${Me.Level}>=${Spell[Mawmun's Bite].Level} && ${Me.Book[${Spell[Mawmun's Bite].RankName}]}) {
		/varset FastPoisonNuke ${Spell[Mawmun's Bite].RankName}
	} else /if (${Me.Level}>=${Spell[Reefmaw's Bite].Level} && ${Me.Book[${Spell[Reefmaw's Bite].RankName}]}) {
		/varset FastPoisonNuke ${Spell[Reefmaw's Bite].RankName}
	} else /if (${Me.Level}>=${Spell[Seedspitter's Bite].Level} && ${Me.Book[${Spell[Seedspitter's Bite].RankName}]}) {
		/varset FastPoisonNuke ${Spell[Seedspitter's Bite].RankName}
	} else /if (${Me.Level}>=${Spell[Bite of the Grendlaen].Level} && ${Me.Book[${Spell[Bite of the Grendlaen].RankName}]}) {
		/varset FastPoisonNuke ${Spell[Bite of the Grendlaen].RankName}
	} else /if (${Me.Level}>=${Spell[Bite of the Blightwolf].Level} && ${Me.Book[${Spell[Bite of the Blightwolf].RankName}]}) {
		/varset FastPoisonNuke ${Spell[Bite of the Blightwolf].RankName}
	} else /if (${Me.Level}>=${Spell[Bite of the Ukun].Level} && ${Me.Book[${Spell[Bite of the Ukun].RankName}]}) {
		/varset FastPoisonNuke ${Spell[Bite of the Ukun].RankName}
	} else /if (${Me.Level}>=${Spell[Bite of the Brownie].Level} && ${Me.Book[${Spell[Bite of the Brownie].RankName}]}) {
		/varset FastPoisonNuke ${Spell[Bite of the Brownie].RankName}
	}else /if (${Me.Level}>=${Spell[Sting of the Queen].Level} && ${Me.Book[${Spell[Sting of the Queen].RankName}]}) {
		/varset FastPoisonNuke ${Spell[Sting of the Queen].RankName}
	}
    
|-FrostNuke
	/if (${Me.Level}>=${Spell[Ice Salvo].Level} && ${Me.Book[${Spell[Ice Salvo].RankName}]}) {
		/varset FrostNuke ${Spell[Ice Salvo].RankName}
	} else /if (${Me.Level}>=${Spell[Ice Shards].Level} && ${Me.Book[${Spell[Ice Shards].RankName}]}) {
		/varset FrostNuke ${Spell[Ice Shards].RankName}
	} else /if (${Me.Level}>=${Spell[Ice Squall].Level} && ${Me.Book[${Spell[Ice Squall].RankName}]}) {
		/varset FrostNuke ${Spell[Ice Squall].RankName}
	} else /if (${Me.Level}>=${Spell[Ice Burst].Level} && ${Me.Book[${Spell[Ice Burst].RankName}]}) {
		/varset FrostNuke ${Spell[Ice Burst].RankName}
	} else /if (${Me.Level}>=${Spell[Ice Mass].Level} && ${Me.Book[${Spell[Ice Mass].RankName}]}) {
		/varset FrostNuke ${Spell[Ice Mass].RankName}
	} else /if (${Me.Level}>=${Spell[Ice Floe].Level} && ${Me.Book[${Spell[Ice Floe].RankName}]}) {
		/varset FrostNuke ${Spell[Ice Floe].RankName}
	} else /if (${Me.Level}>=${Spell[Ice Sheet].Level} && ${Me.Book[${Spell[Ice Sheet].RankName}]}) {
		/varset FrostNuke ${Spell[Ice Sheet].RankName}
	} else /if (${Me.Level}>=${Spell[Tundra Crumble].Level} && ${Me.Book[${Spell[Tundra Crumble].RankName}]}) {
		/varset FrostNuke ${Spell[Tundra Crumble].RankName}
	} else /if (${Me.Level}>=${Spell[Glacial Avalanche].Level} && ${Me.Book[${Spell[Glacial Avalanche].RankName}]}) {
		/varset FrostNuke ${Spell[Glacial Avalanche].RankName}
	} else /if (${Me.Level}>=${Spell[Ice Age].Level} && ${Me.Book[${Spell[Ice Age].RankName}]}) {
		/varset FrostNuke ${Spell[Ice Age].RankName}
	} else /if (${Me.Level}>=${Spell[Velium Strike].Level} && ${Me.Book[${Spell[Velium Strike].RankName}]}) {
		/varset FrostNuke ${Spell[Velium Strike].RankName}
	} else /if (${Me.Level}>=${Spell[Ice Strike].Level} && ${Me.Book[${Spell[Ice Strike].RankName}]}) {
		/varset FrostNuke ${Spell[Ice Strike].RankName}
	} else /if (${Me.Level}>=${Spell[Blizzard Blast].Level} && ${Me.Book[${Spell[Blizzard Blast].RankName}]}) {
		/varset FrostNuke ${Spell[Blizzard Blast].RankName}
	} else /if (${Me.Level}>=${Spell[Winter's Roar].Level} && ${Me.Book[${Spell[Winter's Roar].RankName}]}) {
		/varset FrostNuke ${Spell[Winter's Roar].RankName}
	} else /if (${Me.Level}>=${Spell[Frost Strike].Level} && ${Me.Book[${Spell[Frost Strike].RankName}]}) {
		/varset FrostNuke ${Spell[Frost Strike].RankName}
	} else /if (${Me.Level}>=${Spell[Spirit Strike].Level} && ${Me.Book[${Spell[Spirit Strike].RankName}]}) {
		/varset FrostNuke ${Spell[Spirit Strike].RankName}
	} else /if (${Me.Level}>=${Spell[Frost Rift].Level} && ${Me.Book[${Spell[Frost Rift].RankName}]}) {
		/varset FrostNuke ${Spell[Frost Rift].RankName}
	}
|- ChaoticDoT LVL??? -> LVL104
	/if (${Me.Level}>=${Spell[Chaotic Poison].Level} && ${Me.Book[${Spell[Chaotic Poison].RankName}]}) {
		/varset ChaoticDoT ${Spell[Chaotic Poison].RankName}
	} else /if (${Me.Level}>=${Spell[Chaotic Venom].Level} && ${Me.Book[${Spell[Chaotic Venom].RankName}]}) {
		/varset ChaoticDoT ${Spell[Chaotic Venom].RankName}
	}
|- AllianceBuff
	/if (${Me.Level}>=${Spell[Ancient Alliance].Level} && ${Me.Book[${Spell[Ancient Alliance].RankName}]}) {
		/varset AllianceBuff ${Spell[Ancient Alliance].RankName}
	}
|- GroupHealProcBuff
	/if (${Me.Level}>=${Spell[Responsive Spirit].Level} && ${Me.Book[${Spell[Responsive Spirit].RankName}]}) {
		/varset GroupHealProcBuff ${Spell[Responsive Spirit].RankName}
	}
|- CureSpell
	/if (${Me.Level}>=${Spell[Blood of Tevik].Level} && ${Me.Book[${Spell[Blood of Tevik].RankName}]}) {
		/varset CureSpell ${Spell[Blood of Tevik].RankName}
	} else /if (${Me.Level}>=${Spell[Blood of Rivans].Level} && ${Me.Book[${Spell[Blood of Rivans].RankName}]}) {
		/varset CureSpell ${Spell[Blood of Rivans].RankName}
	} else /if (${Me.Level}>=${Spell[Blood of Sanera].Level} && ${Me.Book[${Spell[Blood of Sanera].RankName}]}) {
		/varset CureSpell ${Spell[Blood of Sanera].RankName}
	} else /if (${Me.Level}>=${Spell[Blood of Klar].Level} && ${Me.Book[${Spell[Blood of Klar].RankName}]}) {
		/varset CureSpell ${Spell[Blood of Klar].RankName}
	} else /if (${Me.Level}>=${Spell[Blood of Corbeth].Level} && ${Me.Book[${Spell[Blood of Corbeth].RankName}]}) {
		/varset CureSpell ${Spell[Blood of Corbeth].RankName}
	} else /if (${Me.Level}>=${Spell[Blood of Avoling].Level} && ${Me.Book[${Spell[Blood of Avoling].RankName}]}) {
		/varset CureSpell ${Spell[Blood of Avoling].RankName}
	} else /if (${Me.Level}>=${Spell[Blood of Nadox].Level} && ${Me.Book[${Spell[Blood of Nadox].RankName}]}) {
		/varset CureSpell ${Spell[Blood of Nadox].RankName}
	}
|- Eradicate Curse
	/if (${Me.Level}>=${Spell[Blood of Tevik].Level} && ${Me.Book[${Spell[Blood Of Tevik].RankName}]}) {
		/varset PureSpiritSpell ${Spell[Blood of Tevik].RankName}
	}
|- SlowSpell AA Starts at LVL 78
	/if (${Me.AltAbility[Turgur's Swarm].ID}) {
		/varset SlowSpell Turgur's Swarm
	} else /if (${Me.Level}>=${Spell[Hungry Plague].Level} && ${Me.Book[${Spell[Hungry Plague].RankName}]}) {
		/varset SlowSpell ${Spell[Hungry Plague].RankName}
	} else /if (${Me.Level}>=${Spell[Balance of Discord].Level} && ${Me.Book[${Spell[Balance of Discord].RankName}]}) {
		/varset SlowSpell ${Spell[Balance of Discord].RankName}
	} else /if (${Me.Level}>=${Spell[Balance of the Nihil].Level} && ${Me.Book[${Spell[Balance of the Nihil].RankName}]}) {
		/varset SlowSpell ${Spell[Balance of the Nihil].RankName}
	} else /if (${Me.Level}>=${Spell[Cloud of Grummus].Level} && ${Me.Book[${Spell[Cloud of Grummus].RankName}]}) {
		/varset SlowSpell ${Spell[Cloud of Grummus].RankName}
	} else /if (${Me.Level}>=${Spell[Plague of Insects].Level} && ${Me.Book[${Spell[Plague of Insects].RankName}]}) {
		/varset SlowSpell ${Spell[Plague of Insects].RankName}
	} else /if (${Me.Level}>=${Spell[Turgur's Insects].Level} && ${Me.Book[${Spell[Turgur's Insects].RankName}]}) {
		/varset SlowSpell ${Spell[Turgur's Insects].RankName}
	} else /if (${Me.Level}>=${Spell[Togor's Insects].Level} && ${Me.Book[${Spell[Togor's Insects].RankName}]}) {
		/varset SlowSpell ${Spell[Togor's Insects].RankName}
	} else /if (${Me.Level}>=${Spell[Tagar's Insects].Level} && ${Me.Book[${Spell[Tagar's Insects].RankName}]}) {
		/varset SlowSpell ${Spell[Tagar's Insects].RankName}
	} else /if (${Me.Level}>=${Spell[Walking Sleep].Level} && ${Me.Book[${Spell[Walking Sleep].RankName}]}) {
		/varset SlowSpell ${Spell[Walking Sleep].RankName}
	} else /if (${Me.Level}>=${Spell[Drowsy].Level} && ${Me.Book[${Spell[Drowsy].RankName}]}) {
		/varset SlowSpell ${Spell[Drowsy].RankName}
	}
    
|- AESlowSpell AA Starts at LVL 80 -- TARGET AE
	/if (${Me.AltAbility[Turgur's Virulent Swarm].ID}) {
		/varset AESlowSpell Turgur's Virulent Swarm
	} else /if (${Me.Level}>=${Spell[Tigir's Insects].Level} && ${Me.Book[${Spell[Tigir's Insects].RankName}]}) {
		/varset AESlowSpell ${Spell[Tigir's Insects].RankName}
	}
    
|- MaloSpell AA Starts at LVL 75
	/if (${Me.AltAbility[Malaise].ID}) {
		/varset MaloSpell Malaise
	} else /if (${Me.Level}>=${Spell[Malosinise].Level} && ${Me.Book[${Spell[Malosinise].RankName}]}) {
		/varset MaloSpell ${Spell[Malosinise].RankName}
	} else /if (${Me.Level}>=${Spell[Malos].Level} && ${Me.Book[${Spell[Malos].RankName}]}) {
		/varset MaloSpell ${Spell[Malos].RankName}
	} else /if (${Me.Level}>=${Spell[Malosinia].Level} && ${Me.Book[${Spell[Malosinia].RankName}]}) {
		/varset MaloSpell ${Spell[Malosinia].RankName}
	} else /if (${Me.Level}>=${Spell[Malo].Level} && ${Me.Book[${Spell[Malo].RankName}]}) {
		/varset MaloSpell ${Spell[Malo].RankName}
	} else /if (${Me.Level}>=${Spell[Malosini].Level} && ${Me.Book[${Spell[Malosini].RankName}]}) {
		/varset MaloSpell ${Spell[Malosini].RankName}
	} else /if (${Me.Level}>=${Spell[Malosi].Level} && ${Me.Book[${Spell[Malosi].RankName}]}) {
		/varset MaloSpell ${Spell[Malosi].RankName}
	} else /if (${Me.Level}>=${Spell[Malaisement].Level} && ${Me.Book[${Spell[Malaisement].RankName}]}) {
		/varset MaloSpell ${Spell[Malaisement].RankName}
	} else /if (${Me.Level}>=${Spell[Malaise].Level} && ${Me.Book[${Spell[Malaise].RankName}]}) {
		/varset MaloSpell ${Spell[Malaise].RankName}
	} 
    
|- AEMaloSpell AA Starts at LVL 95
	/if (${Me.AltAbility[Wind of Malaise].ID}) {
		/varset AEMaloSpell Wind of Malaise
	} else /if (${Me.Level}>=${Spell[Wind of Malisene].Level} && ${Me.Book[${Spell[Wind of Malisene].RankName}]}) {
		/varset AEMaloSpell ${Spell[Wind of Malisene].RankName}
	} else /if (${Me.Level}>=${Spell[Wind of Malis].Level} && ${Me.Book[${Spell[Wind of Malis].RankName}]}) {
		/varset AEMaloSpell ${Spell[Wind of Malis].RankName}
	}
    
|- GrowthBuff
	/if (${Me.Level}>=${Spell[Frenzied Growth].Level} && ${Me.Book[${Spell[Frenzied Growth].RankName}]}) {
		/varset GrowthBuff ${Spell[Frenzied Growth].RankName}
	} else /if (${Me.Level}>=${Spell[Savage Growth].Level} && ${Me.Book[${Spell[Savage Growth].RankName}]}) {
		/varset GrowthBuff ${Spell[Savage Growth].RankName}
	} else /if (${Me.Level}>=${Spell[Ferocious Growth].Level} && ${Me.Book[${Spell[Ferocious Growth].RankName}]}) {
		/varset GrowthBuff ${Spell[Ferocious Growth].RankName}
	} else /if (${Me.Level}>=${Spell[Rampant Growth].Level} && ${Me.Book[${Spell[Rampant Growth].RankName}]}) {
		/varset GrowthBuff ${Spell[Rampant Growth].RankName}
	} else /if (${Me.Level}>=${Spell[Unfettered Growth].Level} && ${Me.Book[${Spell[Unfettered Growth].RankName}]}) {
		/varset GrowthBuff ${Spell[Unfettered Growth].RankName}
	} else /if (${Me.Level}>=${Spell[Untamed Growth].Level} && ${Me.Book[${Spell[Untamed Growth].RankName}]}) {
		/varset GrowthBuff ${Spell[Untamed Growth].RankName}
	} else /if (${Me.Level}>=${Spell[Wild Growth].Level} && ${Me.Book[${Spell[Wild Growth].RankName}]}) {
		/varset GrowthBuff ${Spell[Wild Growth].RankName}
	}
|- MeleeProcBuff MAX -> LVL71
	/if (${Me.Level}>=${Spell[Talisman of the Lioness].Level} && ${Me.Book[${Spell[Talisman of the Lioness].RankName}]}) {
		/varset MeleeProcBuff ${Spell[Talisman of the Lioness].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Sabretooth].Level} && ${Me.Book[${Spell[Talisman of the Sabretooth].RankName}]}) {
		/varset MeleeProcBuff ${Spell[Talisman of the Sabretooth].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Leopard].Level} && ${Me.Book[${Spell[Talisman of the Leopard].RankName}]}) {
		/varset MeleeProcBuff ${Spell[Talisman of the Leopard].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Snow Leopard].Level} && ${Me.Book[${Spell[Talisman of the Snow Leopard].RankName}]}) {
		/varset MeleeProcBuff ${Spell[Talisman of the Snow Leopard].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Lion].Level} && ${Me.Book[${Spell[Talisman of the Lion].RankName}]}) {
		/varset MeleeProcBuff ${Spell[Talisman of the Lion].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Tiger].Level} && ${Me.Book[${Spell[Talisman of the Tiger].RankName}]}) {
		/varset MeleeProcBuff ${Spell[Talisman of the Tiger].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Lynx].Level} && ${Me.Book[${Spell[Talisman of the Lynx].RankName}]}) {
		/varset MeleeProcBuff ${Spell[Talisman of the Lynx].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Cougar].Level} && ${Me.Book[${Spell[Talisman of the Cougar].RankName}]}) {
		/varset MeleeProcBuff ${Spell[Talisman of the Cougar].RankName}
	} else /if (${Me.Level}>=${Spell[Talisman of the Panther].Level} && ${Me.Book[${Spell[Talisman of the Panther].RankName}]}) {
		/varset MeleeProcBuff ${Spell[Talisman of the Panther].RankName}
	} 
    
    
|- SlowProcBuff LVL112->LVL68
	/if (${Me.Level}>=${Spell[Ennui].Level} && ${Me.Book[${Spell[Ennui].RankName}]}) {
		/varset SlowProcBuff ${Spell[Ennui].RankName}
	} else /if (${Me.Level}>=${Spell[Incapacity].Level} && ${Me.Book[${Spell[Incapacity].RankName}]}) {
		/varset SlowProcBuff ${Spell[Incapacity].RankName}
	} else /if (${Me.Level}>=${Spell[Sluggishness].Level} && ${Me.Book[${Spell[Sluggishness].RankName}]}) {
		/varset SlowProcBuff ${Spell[Sluggishness].RankName}
	} else /if (${Me.Level}>=${Spell[Fatigue].Level} && ${Me.Book[${Spell[Fatigue].RankName}]}) {
		/varset SlowProcBuff ${Spell[Fatigue].RankName}
	} else /if (${Me.Level}>=${Spell[Apathy].Level} && ${Me.Book[${Spell[Apathy].RankName}]}) {
		/varset SlowProcBuff ${Spell[Apathy].RankName}
	} else /if (${Me.Level}>=${Spell[Lethargy].Level} && ${Me.Book[${Spell[Lethargy].RankName}]}) {
		/varset SlowProcBuff ${Spell[Lethargy].RankName}
	} else /if (${Me.Level}>=${Spell[Listlessness].Level} && ${Me.Book[${Spell[Listlessness].RankName}]}) {
		/varset SlowProcBuff ${Spell[Listlessness].RankName}
	} else /if (${Me.Level}>=${Spell[Languor].Level} && ${Me.Book[${Spell[Languor].RankName}]}) {
		/varset SlowProcBuff ${Spell[Languor].RankName}
	} else /if (${Me.Level}>=${Spell[Lassitude].Level} && ${Me.Book[${Spell[Lassitude].RankName}]}) {
		/varset SlowProcBuff ${Spell[Lassitude].RankName}
	} else /if (${Me.Level}>=${Spell[Lingering Sloth].Level} && ${Me.Book[${Spell[Lingering Sloth].RankName}]}) {
		/varset SlowProcBuff ${Spell[Lingering Sloth].RankName}
	}
|- PackSelfBuff
	/if (${Me.Level}>=${Spell[Pack of The Black Fang].Level} && ${Me.Book[${Spell[Pack of The Black Fang].RankName}]}) {
		/varset PackSelfBuff ${Spell[Pack of The Black Fang].RankName}
	} else /if (${Me.Level}>=${Spell[Pack of Mirtuk].Level} && ${Me.Book[${Spell[Pack of Mirtuk].RankName}]}) {
		/varset PackSelfBuff ${Spell[Pack of Mirtuk].RankName}
	} else /if (${Me.Level}>=${Spell[Pack of Olesira].Level} && ${Me.Book[${Spell[Pack of Olesira].RankName}]}) {
		/varset PackSelfBuff ${Spell[Pack of Olesira].RankName}
	} else /if (${Me.Level}>=${Spell[Pack of Kriegas].Level} && ${Me.Book[${Spell[Pack of Kriegas].RankName}]}) {
		/varset PackSelfBuff ${Spell[Pack of Kriegas].RankName}
	} else /if (${Me.Level}>=${Spell[Pack of Hilnaah].Level} && ${Me.Book[${Spell[Pack of Hilnaah].RankName}]}) {
		/varset PackSelfBuff ${Spell[Pack of Hilnaah].RankName}
	} else /if (${Me.Level}>=${Spell[Pack of Wurt].Level} && ${Me.Book[${Spell[Pack of Wurt].RankName}]}) {
		/varset PackSelfBuff ${Spell[Pack of Wurt].RankName}
	}
    |- Ignoring the LVL 85 Call the Pack buff due to the decrease in mana per tick.
    
    |- Shaman spell gem strategy
    |- Fewer heals will be available at lower levels as those spell gems will be taken up by debuffs or dps/dots if toggled
    |- on. At higher levels as debuffs move to AA's, these abilities will revert to heals. While there may be a small level
    |- gap between heals becoming available and AA's coming in play, the amount of benefit adding extra nukes to these slots
    |- for a small set of levels seems minimal. If individuals would rather their Shaman in a buffing/debuffing/DPS role
    |- vs healing, we will just forego any heals completely and replace them with DPS abilities.
    
    |- Low Level Heal spells and heals spells that will always be on bar even if not a main healer.
	/varset Spell1 ${RecklessHeal1}
	/varset Spell2 ${RecklessHeal2}
    
    
    /if (${DoDot}) {
        /if ( ${Me.Level}>=87 ) {
            |- High Levels we use fast dots
            /varset Spell3 ${FastDiseaseDoT}
            
        } else /if ( ${Me.Level}>=43 ) {
            |- Low levels we use curse dots
            /varset Spell3 ${CurseDoT2}
        } else {
            |- Really low levels we have no dots programmed
            /echo \ag NO LOW LEVEL DOTS AVAILABLE \aw
        }
        /varset DotSpell ${Spell3}
    } else {
        |- Valid at >=LVL100
        /varset Spell3 ${AESpiritualHeal}
    }
    
    |- Slow
    /if ( ${Me.Level} >= 87 ) {
        |- Valid at >=LVL87
        /varset Spell4 ${RecourseHeal}
    } else {
        /varset Spell4 ${SlowSpell}
    }
    
    |- MALO
    /if ( ${Me.Level} >= 78 ) {
        |- Valid at >=LVL78
        /varset Spell5 ${InterventionHeal}
    } else {
        /varset Spell5 ${MaloSpell}
    }

    /if ( ${Me.Level} >= 44) {
        |- Valid at >=LVL44
        /varset Spell6 ${GroupRenewalHoT}
    } else {
        /varset Spell6 ${FrostNuke}
        /varset NukeSpell ${Spell6}
    }
    
	/if (${DichoSpell.NotEqual[NULL]}) {
        |- Valid at >=LVL101
		/varset Spell7 ${DichoSpell}
	} else /if (${MeleeProcBuff.NotEqual[NULL]}) {
        |- Valid at >=LVL71
		/varset Spell7 ${MeleeProcBuff}
	} else {
        |- Under level 71
        /varset Spell7 ${PoisonNuke}
    }
    
    |- MiscGem < 55
    |- Valid at 68
	/varset Spell8 ${SlowProcBuff}
    
    |- MiscGem < 75
    |- Spell Valid at 81
    |- Slot Valid at 55
	/varset Spell9 ${GrowthBuff}
    

    |- MiscGem < 80
    |- Spell Valid at 80
    |- Slot Valid at 75
	/varset Spell10 ${SelfHealProcBuff}
    
    |- Spell Valid at 
    |- Slot Valid at 80
	/varset Spell11 ${TwinHealNuke}
    
	/if (${spellmisc}==12) {
            |- MiscGem < 106
            |- Slot Valid at 80
		/varset Spell12 ${CureSpell}
		/varset miscspellremem ${Spell12}
	} else /if (${spellmisc}==13) {
    
        |- Using 13 as a DPS option -- 3 Reckless heal options seems a bit overkill with the number of other heals available
		/varset Spell12 ${RecklessHeal3}
		
        |- Slot Valid at 106
        /varset Spell13 ${CureSpell}
		/varset miscspellremem ${Spell13}
	}
/return
|----------------------------------------------------------------------------
|- SUB: Bind Change Var Int resets various interger settings from ini file
|----------------------------------------------------------------------------
Sub Bind_SetVarInt(string ISection, string IName, int IVar)
    /docommand /varset changetoini 1
	/if (${ISection.Equal[Toggle]}) {
		/if (${IName.Equal[BringYourOwnSpells]}) {
			/if (!${BringYourOwnSpells}) {
				/echo \aw Setting BringYourOwnSpells to \ag ON
				/varset BringYourOwnSpells 1
			} else {
				/echo \aw Resetting BringYourOwnSpells to \ar OFF
				/varset BringYourOwnSpells 0
				/call LoadSpellBar
			}
		} else /if (${IName.Equal[UseAoE]}) {
            /if (!${UseAoE}) {
                /echo \aw Setting  UseAoE, AEMalo, and AESlow to \ag ON
				/varset UseAoE 1
                /varset DoAEMalo 1
                /varset DoAESlow 1
            } else {
            	/echo \aw Resetting  UseAoE, AEMalo, and AESlow to \ar OFF
				/varset UseAoE 0
                /varset DoAEMalo 0
                /varset DoAESlow 0
            }
        } else /if (${IName.Equal[UsePet]}) {
            /if (!${UsePet}) {
                /echo \aw Setting  UsePet to \ag ON
				/varset UsePet 1
            } else {
            	/echo \aw Resetting  UsePet to \ar OFF
				/varset UsePet 0
            }
        } else /if (${IName.Equal[ChestCombatCast]}) {
            /if (!${ChestCombatCast}) {
                /echo \aw Setting  ChestCombatCast to \ag ON
				/varset ChestCombatCast 1
            } else {
            	/echo \aw Resetting  ChestCombatCast to \ar OFF
				/varset ChestCombatCast 0
            }
        } else /if (${IName.Equal[UsePoisons]}) {
            /if (!${UsePoisons}) {
                /echo \aw Setting  UsePoisons to \ag ON
				/varset UsePoisons 1
                /call LoadSpellBar
            } else {
            	/echo \aw Resetting  UsePoisons to \ar OFF
				/varset UsePoisons 0
                /call LoadSpellBar
            }
        } else /if (${IName.Equal[DoDot]}) {
            /if (!${DoDot}) {
                /echo \aw Setting  DoDot to \ag ON
				/varset DoDot 1
                /call LoadSpellBar
            } else {
            	/echo \aw Resetting  DoDot to \ar OFF
				/varset DoDot 0
                /call LoadSpellBar
            }
        } else /if (${IName.Equal[AllowMezBreak]}) {
            /if (!${AllowMezBreak}) {
                /echo \aw Setting  AllowMezBreak to \ag ON
				/varset AllowMezBreak 1
            } else {
            	/echo \aw Resetting  AllowMezBreak to \ar OFF
				/varset AllowMezBreak 0
            }
        } else /if (${IName.Equal[DoSlow]}) {
            /if (!${DoSlow}) {
                /echo \aw Setting  DoSlow to \ag ON
				/varset DoSlow 1
            } else {
            	/echo \aw Resetting  DoSlow to \ar OFF
				/varset DoSlow 0
            }
        } else /if (${IName.Equal[UseBattleRez]}) {
            /if (!${UseBattleRez}) {
                /echo \aw Setting  UseBattleRez to \ag ON
				/varset UseBattleRez 1
            } else {
            	/echo \aw Resetting  UseBattleRez to \ar OFF
				/varset UseBattleRez 0
            }
        } else /if (${IName.Equal[CureOther]}) {
            /if (!${CureOther}) {
                /echo \aw Setting  Use Pure Spirit to \ag ON
				/varset CureOther 1
                /call LoadSpellBar
            } else {
            	/echo \aw Resetting  Use Pure Spirit to \ar OFF
				/varset CureOther 0
                /call LoadSpellBar
            }
        } else /if (${IName.Equal[DoCures]}) {
             /if (!${DoCures}) {
                /echo \aw Setting  Use Cures set to \ag ON
				/varset DoCures 1
            } else {
            	/echo \aw Resetting  Use Cures set to \ar OFF
				/varset DoCures 0
            }           
        }
    } else /if (${ISection.Equal[Set]}) {
        |- No sets
    }
/return
|----------------------------------------------------------------------------
|- SUB: BIND BNDSingleCure - 
|----------------------------------------------------------------------------
Sub Bind_BNDSingleCure(int RequestorID)
	/call SingleCure ${RequestorID}
/return 
|----------------------------------------------------------------------------
|- SUB: BIND CmdList - 
|----------------------------------------------------------------------------
Sub Bind_CmdList
    /call CommonHelp
    /echo \ag===${MacroName} Commands=== 
    /echo \ag/byos\aw - Bring Your Own Spells! Use what ever spells you have mem'd
    /echo \ag/tglaoe\aw - Turn the use of AE abilities on/off including AESlow and AEMalo
    /echo \ag/tglbp\aw - Turn on/off the use of a Chest piece defined in the ini
    /echo \ag/tglpet\aw - Pet toggle...cause sometimes they arent allowed
    /echo \ag/tglmezbreak\aw - Allow attacking mez'd mobs if below assistat % - Ignores waiting for MA
    /echo \ag/tglpoison\aw - Use poison nukes over cold nukes and poison DOTs over disease dots if enabled
    /echo \ag/tgldots\aw - Cast DOTs as part of the combat routine if enabled
    /echo \ag/tglslow\aw - Cast slows as part of the debuff routine
    /echo \ag/tglbrez\aw - Have the Shaman use the 0% XP battle rez if enabled
    /echo \ag/tglps\aw - If enabled, will use the Pure Spirit spell line over the Blood spell line.
/return