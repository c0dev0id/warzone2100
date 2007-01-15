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
#ifndef _bug_
#define _bug_

#include <assert.h>

#define iV_DEBUG_FILE	"ivi.log"

#ifdef _DEBUG
//	#define iV_DEBUG
#endif

#ifdef iV_DEBUG

#define iV_DEBUG0(S)										iV_Debug((S))
#define iV_DEBUG1(S,A)									iV_Debug((S),(A))
#define iV_DEBUG2(S,A,B) 								iV_Debug((S),(A),(B))
#define iV_DEBUG3(S,A,B,C)								iV_Debug((S),(A),(B),(C))
#define iV_DEBUG4(S,A,B,C,D)							iV_Debug((S),(A),(B),(C),(D))
#define iV_DEBUG5(S,A,B,C,D,E)						iV_Debug((S),(A),(B),(C),(D),(E))
#define iV_DEBUG6(S,A,B,C,D,E,F)						iV_Debug((S),(A),(B),(C),(D),(E),(F))
#define iV_DEBUG7(S,A,B,C,D,E,F,G)					iV_Debug((S),(A),(B),(C),(D),(E),(F),(G))
#define iV_DEBUG8(S,A,B,C,D,E,F,G,H)				iV_Debug((S),(A),(B),(C),(D),(E),(F),(G),(H))
#define iV_DEBUG9(S,A,B,C,D,E,F,G,H,I)				iV_Debug((S),(A),(B),(C),(D),(E),(F),(G),(H),(I))
#define iV_DEBUG10(S,A,B,C,D,E,F,G,H,I,J) 		iV_Debug((S),(A),(B),(C),(D),(E),(F),(G),(H),(I),(J))
#define iV_DEBUG11(S,A,B,C,D,E,F,G,H,I,J,K) 		iV_Debug((S),(A),(B),(C),(D),(E),(F),(G),(H),(I),(J),(K))
#define iV_DEBUG12(S,A,B,C,D,E,F,G,H,I,J,K,L)	iV_Debug((S),(A),(B),(C),(D),(E),(F),(G),(H),(I),(J),(K),(L))
#define iV_DEBUG_CREATE_LOG							_debug_create_log()
#define iV_ASSERT(A)										assert((A))



#else

#define iV_DEBUG0(S)
#define iV_DEBUG1(S,A)
#define iV_DEBUG2(S,A,B)
#define iV_DEBUG3(S,A,B,C)
#define iV_DEBUG4(S,A,B,C,D)
#define iV_DEBUG5(S,A,B,C,D,E)
#define iV_DEBUG6(S,A,B,C,D,E,F)
#define iV_DEBUG7(S,A,B,C,D,E,F,G)
#define iV_DEBUG8(S,A,B,C,D,E,F,G,H)
#define iV_DEBUG9(S,A,B,C,D,E,F,G,H,I)
#define iV_DEBUG10(S,A,B,C,D,E,F,G,H,I,J)
#define iV_DEBUG11(S,A,B,C,D,E,F,G,H,I,J,K)
#define iV_DEBUG12(S,A,B,C,D,E,F,G,H,I,J,K,L)
#define iV_DEBUG_CREATE_LOG
#define iV_ASSERT(A)

#endif

//*************************************************************************

extern void iV_Debug(char *string, ...);
extern void iV_DebugDisplayLog(void);

//*************************************************************************

extern void _debug_create_log(void);

#endif
