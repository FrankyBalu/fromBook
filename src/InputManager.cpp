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

#include "include/InputManager.h"

#include <raylib.h>

MM::InputManager *MM::InputManager::s_pInstance= nullptr;


MM::InputManager::InputManager(){
}

bool MM::InputManager::IsKeyPressed(Keys key){
    return ::IsKeyPressed(key);
}

bool MM::InputManager::IsKeyPressedRepeat(Keys key){
    return ::IsKeyPressedRepeat(key);
}

bool MM::InputManager::IsKeyDown(Keys key){
    return ::IsKeyDown(key);
}

bool MM::InputManager::IsKeyReleased(Keys key){
    return ::IsKeyReleased(key);
}

bool MM::InputManager::IsKeyUp(Keys key){
    return ::IsKeyUp(key);
}

void MM::InputManager::SetExitKey(Keys key){
    ::SetExitKey(key);
}
