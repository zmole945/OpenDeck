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

//power of 2
#define NUMBER_OF_ANALOG_SAMPLES    1
#define ANALOG_SAMPLE_SHIFT         0

#define ADC_AVG_VALUE(value)        (value >> ANALOG_SAMPLE_SHIFT)

typedef enum
{
    lowHysteresis,
    highHysteresis
} hysteresisType_t;
