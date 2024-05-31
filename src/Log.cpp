/*
 * Mullemaus
 * Copyright (C) 2024   Frank Kartheuser <frank.kartheuser1988@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "include/Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

// #include <memory>
// #include <spdlog/common.h>
// #include <spdlog/spdlog.h>

void MM::Init_Log(){
    auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

#ifdef DEBUG
    consoleSink->set_pattern("%^[%H:%M:%S.%e]%=8l:(%s: %#) %v%$");
#else
    consoleSink->set_pattern("%^[%H:%M:%S.%e]%=8l:  %v%$");
#endif

    std::vector<spdlog::sink_ptr> sinks{consoleSink};
    auto logger = std::make_shared<spdlog::logger>("MULLEMAUS_LOGGER", sinks.begin(), sinks.end());
    logger->set_level(spdlog::level::debug);
    logger->flush_on(spdlog::level::debug);

    spdlog::register_logger(logger);
    spdlog::set_default_logger(logger);
}


void MM::Shutdown_Log(){
    spdlog::shutdown();
}

void MM::Set_Log_Level(int level){
    spdlog::set_level(static_cast<spdlog::level::level_enum>(level));
}
