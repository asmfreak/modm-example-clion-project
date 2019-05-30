/*
 * Copyright (c) 2017, Sascha Schade
 * Copyright (c) 2018, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <modm/board.hpp>
#include <modm/debug/logger.hpp>
#include <modm/processing/timer.hpp>
#include <modm/platform/timer/timer_1.hpp>
#include <modm/driver/motion/mpu6050.hpp>
#include <chrono>
#include <iterator>

using namespace modm::literals;
using namespace std::literals::chrono_literals;

modm::IODeviceWrapper< Usart2, modm::IOBuffer::BlockIfFull > loggerDevice;
modm::log::Logger modm::log::info(loggerDevice);

// Set the log level
#undef    MODM_LOG_LEVEL
#define    MODM_LOG_LEVEL modm::log::INFO

// ----------------------------------------------------------------------------
int
main()
{
    Board::initialize();
    // Initialize Usart
    Usart2::connect<GpioA2::Tx, GpioA3::Rx >();
    Usart2::initialize<Board::SystemClock, 115200_Bd>();

    while (true)
    {
    }
    return 0;
}
