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

#include "Analog.h"
#include "../../board/Board.h"
#include "Variables.h"

uint16_t    lastAnalogueValue[MAX_NUMBER_OF_ANALOG];
uint8_t     fsrPressed[MAX_NUMBER_OF_ANALOG/8+1];

Analog::Analog()
{
    //def const
}

void Analog::update()
{
    if (!board.analogDataAvailable())
        return;

    //check values
    for (int i=0; i<MAX_NUMBER_OF_ANALOG; i++)
    {
        int16_t analogData = board.getAnalogValue(i);

        //don't process component if it's not enabled
        if (!database.read(DB_BLOCK_ANALOG, dbSection_analog_enable, i))
            continue;

        analogType_t type = (analogType_t)database.read(DB_BLOCK_ANALOG, dbSection_analog_type, i);

        if (type != aType_button)
        {
            switch(type)
            {
                case aType_potentiometer_cc:
                case aType_potentiometer_note:
                case aType_NRPN_7:
                case aType_NRPN_14:
                checkPotentiometerValue(i, analogData);
                break;

                case aType_fsr:
                checkFSRvalue(i, analogData);
                break;

                default:
                break;
            }
        }
        else
        {
            //read raw value
            analogData = board.getAnalogValue(i);

            if (analogData == -1)
            {
                continue;
            }

            bool state = analogData > DIGITAL_VALUE_THRESHOLD;
            buttons.processButton(i+MAX_NUMBER_OF_BUTTONS, state, false);
        }
    }

    board.continueADCreadout();
}

void Analog::debounceReset(uint16_t index)
{
    lastAnalogueValue[index] = 0;

    uint8_t arrayIndex = index/8;
    uint8_t fsrIndex = index - 8*arrayIndex;

    BIT_CLEAR(fsrPressed[arrayIndex], fsrIndex);
}

Analog analog;
