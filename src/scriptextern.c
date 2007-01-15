/*
	This file is part of Warzone 2100.
	Copyright (C) 1999-2004  Eidos Interactive
	Copyright (C) 2005-2007  Warzone Resurrection Project

	Warzone 2100 is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	Warzone 2100 is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Warzone 2100; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
/*
 * ScriptExtern.c
 *
 * All game variable access functions for the scripts
 *
 */

#include "lib/framework/frame.h"
#include "map.h"

#include "lib/script/script.h"
#include "scripttabs.h"
#include "scriptextern.h"

#include "lib/ivis_common/rendfunc.h"
#include "display.h"

#include "multiplay.h"

#include "winmain.h"
#include "hci.h"
#include "lib/gamelib/gtime.h"


// current game level
SDWORD		scrGameLevel = 0;

// whether the tutorial is active
BOOL		bInTutorial = FALSE;

// whether any additional special case victory/failure conditions have been met
BOOL		bExtraVictoryFlag = FALSE;
BOOL		bExtraFailFlag = FALSE;



// whether or not to track the player's transporter as it comes
// into an offworld mission.
BOOL		bTrackTransporter = FALSE;


// reset the script externals for a new level
void scrExternReset(void)
{
	scrGameLevel = 0;
	bInTutorial = FALSE;
	bExtraVictoryFlag = FALSE;
	bExtraFailFlag = FALSE;
}


// General function to get some basic game values
BOOL scrGenExternGet(UDWORD index)
{
	INTERP_TYPE		type;
	INTERP_VAL	scrFunctionResult;	//function return value to be pushed to stack

	switch (index)
	{

	case EXTID_TRACKTRANSPORTER:
		type = VAL_BOOL;
		scrFunctionResult.v.bval = bTrackTransporter;
		break;
	case EXTID_MAPWIDTH:
		type = VAL_INT;
		scrFunctionResult.v.ival = mapWidth;
		break;
	case EXTID_MAPHEIGHT:
		type = VAL_INT;
		scrFunctionResult.v.ival = mapHeight;
		break;
	case EXTID_GAMEINIT:
		type = VAL_BOOL;
		scrFunctionResult.v.bval = gameInitialised;
		break;
	case EXTID_SELECTEDPLAYER:
		type = VAL_INT;
		scrFunctionResult.v.ival = selectedPlayer;
		break;
	case EXTID_GAMELEVEL:
		type = VAL_INT;
		scrFunctionResult.v.ival = scrGameLevel;
		break;
	case EXTID_GAMETIME:
		type = VAL_INT;
		scrFunctionResult.v.ival = (SDWORD)(gameTime/SCR_TICKRATE);
		break;
	case EXTID_TUTORIAL:
		type = VAL_BOOL;
		scrFunctionResult.v.bval = bInTutorial;
		break;
	case EXTID_CURSOR:
		type = VAL_INT;
		scrFunctionResult.v.ival = iV_GetMouseFrame();	// from  rendfunc.c
//		DBPRINTF(("CURSOR = %d val\n",val));
		break;
	case EXTID_INTMODE:
		type=VAL_INT;
		scrFunctionResult.v.ival=intMode;
		break;

	case EXTID_TARGETTYPE:
		type=VAL_INT;
		scrFunctionResult.v.ival=getTargetType();
		break;
	case EXTID_EXTRAVICTORYFLAG:
		type=VAL_BOOL;
		scrFunctionResult.v.bval=bExtraVictoryFlag;
		break;
	case EXTID_EXTRAFAILFLAG:
		type=VAL_BOOL;
		scrFunctionResult.v.bval=bExtraFailFlag;
		break;
	case EXTID_MULTIGAMETYPE:		// multiplayer variable..
		type = VAL_INT;
		scrFunctionResult.v.ival = game.type;
		break;
	case EXTID_MULTIGAMEHUMANMAX:		// multiplayer variable..
		type = VAL_INT;
		scrFunctionResult.v.ival = game.maxPlayers;
		break;
	case EXTID_MULTIGAMEBASETYPE:
		type = VAL_INT;
		scrFunctionResult.v.ival	= game.base;
		break;
	case EXTID_MULTIGAMEALLIANCESTYPE:
		type = VAL_INT;
		scrFunctionResult.v.ival	= game.alliance;
		break;

		default:
		ASSERT( FALSE, "scrGenExternGet: unknown variable index" );
		return FALSE;
		break;
	}

	if (!stackPushResult(type, &scrFunctionResult))
	{
		return FALSE;
	}

	return TRUE;
}


// General function to set some basic game values
BOOL scrGenExternSet(UDWORD index)
{
	INTERP_VAL		sVal;
	INTERP_TYPE		type;
	SDWORD			val;

	// Get the value and store it in type,val
	if (!stackPop(&sVal))
	{
		return FALSE;
	}
	type = sVal.type;
	val = sVal.v.ival;

	switch (index)
	{
	case EXTID_GAMELEVEL:
		if (type != VAL_INT)
		{
			ASSERT( FALSE,"invalid type for gameLevel" );
			return FALSE;
		}
		scrGameLevel = val;
		break;
	case EXTID_TUTORIAL:
		if (type != VAL_BOOL)
		{
			ASSERT( FALSE,"invalid type for inTutorial" );
			return FALSE;
		}
		bInTutorial = val;
		break;
	case EXTID_EXTRAVICTORYFLAG:
		if (type != VAL_BOOL)
		{
			ASSERT( FALSE,"invalid type for extraVictoryFlag" );
			return FALSE;
		}
		bExtraVictoryFlag = val;
		break;
	case EXTID_EXTRAFAILFLAG:
		if (type != VAL_BOOL)
		{
			ASSERT( FALSE,"invalid type for extraFailFlag" );
			return FALSE;
		}
		bExtraFailFlag = val;
		break;
	default:
		ASSERT( FALSE, "scrGenExternSet: unknown variable index" );
		return FALSE;
		break;
	}

	return TRUE;
}



