/* GemRB - Infinity Engine Emulator
 * Copyright (C) 2003 The GemRB Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header: /data/gemrb/cvs2svn/gemrb/gemrb/gemrb/plugins/Core/MoviePlayer.h,v 1.6 2006/01/08 22:07:44 avenger_teambg Exp $
 *
 */

/**
 * @file MoviePlayer.h
 * Declares MoviePlayer class, abstract loader and player for videos
 * @author The GemRB Project
 */


#ifndef MOVIEPLAYER_H
#define MOVIEPLAYER_H

#include "../../includes/win32def.h"
#include "../../includes/globals.h"
#include "Plugin.h"
#include "DataStream.h"


#ifdef WIN32

#ifdef GEM_BUILD_DLL
#define GEM_EXPORT __declspec(dllexport)
#else
#define GEM_EXPORT __declspec(dllimport)
#endif

#else
#define GEM_EXPORT
#endif

/**
 * @class MoviePlayer
 * Abstract loader and player for videos
 */

class GEM_EXPORT MoviePlayer : public Plugin {
public:
	MoviePlayer(void);
	virtual ~MoviePlayer(void);
	virtual bool Open(DataStream* stream, bool autoFree = true) = 0;
	virtual int Play() = 0;
	virtual void CallBackAtFrames(ieDword cnt, ieDword *frames, ieDword *strrefs) = 0;
};

#endif
