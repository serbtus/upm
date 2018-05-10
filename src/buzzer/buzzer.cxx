/*
 * Author: Jon Trulson <jtrulson@ics.com>
 * Copyright (c) 2016 Intel Corporation.
 *
 * based on original C++ driver by
 * Author: Yevgeniy Kiveisha <yevgeniy.kiveisha@intel.com>
 * Copyright (c) 2014 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <stdexcept>
#include <unistd.h>
#include <string>
#include <iostream>

#include "mraa/initio.hpp"
#include "buzzer.hpp"


using namespace upm;
using namespace std;

Buzzer::Buzzer(int pinNumber) : m_buzzer(buzzer_init(pinNumber))
{
    if (!m_buzzer)
        throw std::runtime_error(std::string(__FUNCTION__) +
                                 ": buzzer_init() failed");
}

Buzzer::Buzzer(std::string initStr)
{
    mraa::MraaIo mraaIo(initStr);
    std::vector<std::string> upmTokens;

    if (mraaIo.getLeftoverStr() != "") {
      upmTokens = Buzzer::parse(mraaIo.getLeftoverStr());
    }

    for (std::string tok : upmTokens) {
      if (tok.substr(0, 4) == "vol:") {
        // setVolume(::atof(tok.substr(4));
      } else {}
    }
}

Buzzer::~Buzzer()
{
    //buzzer_close(m_buzzer);
}

void Buzzer::setVolume(float vol)
{
    buzzer_set_volume(m_buzzer, vol);
}

float Buzzer::getVolume()
{
    return buzzer_get_volume(m_buzzer);
}

int Buzzer::playSound(int note, int delay)
{
    if (buzzer_play_sound(m_buzzer, note, delay))
        throw std::runtime_error(std::string(__FUNCTION__) +
                                 ": buzzer_play_sound() failed");
    return note;
}

void Buzzer::stopSound()
{
    if (buzzer_stop_sound(m_buzzer))
        throw std::runtime_error(std::string(__FUNCTION__) +
                                 ": buzzer_stop_sound() failed");
}

