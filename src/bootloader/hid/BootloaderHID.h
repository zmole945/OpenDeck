/*
             LUFA Library
     Copyright (C) Dean Camera, 2017.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2017  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for BootloaderHID.c.
 */

#ifndef _BOOTLOADERHID_H_
#define _BOOTLOADERHID_H_

/* Includes: */
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/boot.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "Descriptors.h"

#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Platform/Platform.h>

#include "../../firmware/board/avr/variants/Common.h"
#include "../../firmware/board/common/constants/Reboot.h"

#ifdef BOARD_OPEN_DECK
#include "../../firmware/board/avr/variants/opendeck/pins/Pins.h"
#include "../../firmware/board/avr/variants/opendeck/Hardware.h"
#elif defined(BOARD_A_LEO) || defined(BOARD_A_PRO_MICRO)
#include "../../firmware/board/avr/variants/leonardo/pins/Pins.h"
#include "../../firmware/board/avr/variants/leonardo/Hardware.h"
#elif defined(BOARD_A_xu2)
#include "../../firmware/board/avr/variants/xu2/Pins.h"
#include "../../firmware/board/avr/variants/xu2/Hardware.h"
#elif defined(BOARD_T_2PP)
#include "../../firmware/board/avr/variants/teensy2pp/pins/Pins.h"
#include "../../firmware/board/avr/variants/teensy2pp/Hardware.h"
#endif

/* Preprocessor Checks: */
#if !defined(__OPTIMIZE_SIZE__)
#error This bootloader requires that it be optimized for size, not speed, to fit into the target device. Change optimization settings and try again.
#endif

/* Macros: */
/** Bootloader special address to start the user application */
#define COMMAND_STARTAPPLICATION        0xFFFF

/* Function Prototypes: */
static void SetupHardware(void);

void Application_Jump_Check(void) ATTR_INIT_SECTION(3);

void EVENT_USB_Device_ConfigurationChanged(void);

#endif
