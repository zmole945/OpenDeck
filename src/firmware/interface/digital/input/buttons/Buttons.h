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
#include "../../../../board/Board.h"

///
/// \brief Button handling.
/// \defgroup buttons Buttons
/// \ingroup interface
/// @{
///

class Buttons
{
    public:
    Buttons();

    static void update();
    static void processButton(uint8_t buttonID, bool state, bool debounce = true);

    private:
    //data processing
    static bool getButtonPressed(uint8_t buttonID);
    static void setButtonPressed(uint8_t buttonID, bool state);
    static void processMomentaryButton(uint8_t buttonID, bool buttonState, buttonMIDImessage_t midiMessage = buttonNote);
    static void processLatchingButton(uint8_t buttonID, bool buttonState, buttonMIDImessage_t midiMessage = buttonNote);
    static void updateButtonState(uint8_t buttonID, uint8_t buttonState);
    static bool getPreviousButtonState(uint8_t buttonID);
    static bool buttonDebounced(uint8_t buttonID, bool buttonState);
};

extern Buttons buttons;

/// @}