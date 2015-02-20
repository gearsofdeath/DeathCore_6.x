/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef DEF_MOGUSHAN_PALACE_H
#define DEF_MOGUSHAN_PALACE_H

#define DataHeader "MP"

uint32 const EncounterCount       		= 3;

enum Data
{
    	// Encounter States/Boss GUIDs
	DATA_BOSS_XIN_THE_WEAPONMASTER          = 0,
	DATA_BOSS_GEKKAN      			= 1,
	DATA_BOSS_TRIALOFKING	      	    	= 2
};

enum CreatureIds
{
	BOSS_XIN_THE_WEAPONMASTER		= 61884,
	BOSS_GEKKAN				= 61243,
	BOSS_TRIALOFKING			= 61442
};

enum GameObjects
{
    GO_DOOR_BEFORE_TRIAL    = 213594,
    GO_TRIAL_CHEST          = 214520,
    GO_DOOR_AFTER_TRIAL     = 213593,
    GO_DOOR_BEFORE_KING     = 213596
};

#endif

