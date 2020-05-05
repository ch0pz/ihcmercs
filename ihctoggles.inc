|- File: ihctoggless.inc
|- Version 2.1
|- Original File: auto_subs.inc
|- Auto-Subs Shared routines across Auto series macros by Noobhaxor
|- Version 6.2
|- Updated: 4/25/2019
|- Modified version of the above file to maintain compatability with the automac's / kissassist
|- Modified to fit the IHC mac's and mod's better
|- Testing 3
|--------------------------------------------------------------------------------------
 |-Toggle switches toggling on/off modes from INI files
 |--------------------------------------------------------------------------------------
 Sub WizToggles
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