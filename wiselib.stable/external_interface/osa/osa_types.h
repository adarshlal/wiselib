/***************************************************************************
 ** This file is part of the generic algorithm library Wiselib.           **
 ** Copyright (C) 2008,2009 by the Wisebed (www.wisebed.eu) project.      **
 **                                                                       **
 ** The Wiselib is free software: you can redistribute it and/or modify   **
 ** it under the terms of the GNU Lesser General Public License as        **
 ** published by the Free Software Foundation, either version 3 of the    **
 ** License, or (at your option) any later version.                       **
 **                                                                       **
 ** The Wiselib is distributed in the hope that it will be useful,        **
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of        **
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
 ** GNU Lesser General Public License for more details.                   **
 **                                                                       **
 ** You should have received a copy of the GNU Lesser General Public      **
 ** License along with the Wiselib.                                       **
 ** If not, see <http://www.gnu.org/licenses/>.                           **
 ***************************************************************************/
#ifndef CONNECTOR_OSA_TYPES_H
#define CONNECTOR_OSA_TYPES_H

extern "C" {
#include <stdint.h>
#include <stdio.h>
#include "opencom.h"
#include "interfaces/radio/iradio_int.h"
#include "interfaces/hardware/ihardware_control.h"
#include "interfaces/time/itimer.h"
}

namespace wiselib
{
   // -----------------------------------------------------------------------
   typedef struct _TrRecpList {
      IRadio_Int *radio;
      IHardwareControl *ihc;
      ITimer *timer;
   } TrRecpList;
}
#define RECPS ((TrRecpList*) comp -> recpList)

#endif
