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

#include "../../database/blocks/Encoders.h"

typedef enum
{
    sysExSection_encoders_enable,
    sysExSection_encoders_invert,
    sysExSection_encoders_mode,
    sysExSection_encoders_midiID,
    sysExSection_encoders_midiChannel,
    SYSEX_SECTIONS_ENCODERS
} sysExSection_encoders_t;

//map sysex sections to sections in db
const uint8_t sysEx2DB_encoders[SYSEX_SECTIONS_ENCODERS] =
{
    dbSection_encoders_enable,
    dbSection_encoders_invert,
    dbSection_encoders_mode,
    dbSection_encoders_midiID,
    dbSection_encoders_midiChannel,
};
