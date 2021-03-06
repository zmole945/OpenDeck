/*
    OpenDeck MIDI platform firmware
    Copyright (C) 2015-2018 Igor Petrovic

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

///
/// \brief Hardcoded board version.
/// @{
///

#define HARDWARE_VERSION_MAJOR      1
#define HARDWARE_VERSION_MINOR      2
#define HARDWARE_VERSION_REVISION   1

/// @}

#include "../../../common/Common.h"
#include "../Common.h"
#include "pins/Pins.h"
#include "pins/Map.h"
#include "../../../../interface/digital/output/leds/DataTypes.h"
#include "Hardware.h"

///
/// \addtogroup board
/// @{
///

class Board
{
    public:
    //init
    Board();
    void init();
    bool checkNewRevision();

    //digital in
    bool digitalInputDataAvailable();
    static void continueDigitalInReadout();

    //buttons
    bool getButtonState(uint8_t buttonIndex);

    //analog
    bool analogDataAvailable();
    int16_t getAnalogValue(uint8_t analogID);
    static void continueADCreadout();
    static uint16_t scaleADC(uint16_t value, uint16_t maxValue);

    //encoders
    static uint8_t getEncoderPair(uint8_t buttonID);
    int8_t getEncoderState(uint8_t encoderID);

    //leds
    static uint8_t getRGBaddress(uint8_t rgbID, rgbIndex_t index);
    static uint8_t getRGBID(uint8_t ledID);

    void reboot(rebootType_t type);

    private:
    //init
    static void initPins();
    static void initAnalog();
    static void initEncoders();
    static void initUART_MIDI(uint16_t baudRate);
    static void initUSB_MIDI();
    static void configureTimers();
    static int8_t readEncoder(uint8_t encoderID, uint8_t pairState);
};

extern Board board;

/// @}
