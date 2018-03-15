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

#include "DataTypes.h"
#include "Constants.h"
#include "../../../../board/Board.h"

///
/// \brief LED handling.
/// \defgroup leds LEDs
/// \ingroup interface
/// @{
///
class LEDs
{
    public:
    LEDs();
    static void init();
    static void update();
    static void setAllOn();
    static void setAllOff();
    static void setColor(uint8_t ledNumber, ledColor_t color);
    static ledColor_t getColor(uint8_t ledID);
    static void setBlinkState(uint8_t ledID, bool state);
    static bool getBlinkState(uint8_t ledID);
    static bool setBlinkTime(uint16_t blinkTime);
    static bool setFadeTime(uint8_t transitionSpeed);
    static ledColor_t velocityToColor(uint8_t receivedVelocity);
    static void ccToBlink(uint8_t cc, uint8_t value, uint8_t channel);
    static void noteToState(uint8_t receivedNote, uint8_t receivedVelocity, uint8_t receivedChannel, bool local = false);

    private:
    static uint8_t getState(uint8_t ledNumber);
    static void handleLED(uint8_t ledNumber, bool state, bool rgbLED = false, rgbIndex_t index = rgb_R);

    static void startUpAnimation();
};

extern LEDs leds;
/// @}