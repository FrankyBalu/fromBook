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

#ifndef __MULLEMAUS_LOG
#define __MULLEMAUS_LOG

#ifdef DEBUG
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#else
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_WARN
#endif

# define SPDLOG_FUNCTION __PRETTY_FUNCTION__
#include "spdlog/spdlog.h"



namespace MM {

    void Init_Log (void);

    void Shutdown_Log (void);

    void Set_Log_Level (int level);

    ///////////////////////////////////////////////////////////////////////////
    //  Trace und Debug logging stehen im Release build  nicht zur verfügung
    ///////////////////////////////////////////////////////////////////////////
    #ifdef DEBUG
        #ifdef TRACE
            #define LOG_T(...)    SPDLOG_TRACE(__VA_ARGS__)
        #endif

        #define LOG_D(...)    SPDLOG_DEBUG(__VA_ARGS__)

        ///ausgebe nnur im debugmodus?
        // #define LOG_I(...)     SPDLOG_INFO(__VA_ARGS__)

    #else
        #define LOG_T (...)     (void)0
        #define LOG_D (...)     (void)0
        #define LOG_I (...)      (void)0
    #endif

    #define LOG_I(...)     SPDLOG_INFO(__VA_ARGS__)

    #define LOG_W(...)     SPDLOG_WARN(__VA_ARGS__)

    #define LOG_E(...)    SPDLOG_ERROR(__VA_ARGS__)

    #define LOG_F(...)    SPDLOG_CRITICAL(__VA_ARGS__)

    #define LOG_ASSERT(x, msg) if ((x)) {} else { LOG_F("ASSERT - {}\n\t{}\n\tin file: {}\n\ton line: {}", #x, msg, __FILE__, __LINE__);}

} //namespace MM

#endif //__MULLEMAUS_LOG
