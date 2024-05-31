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

#include "include/Player.h"
#include "include/ObjectParams.h"
#include "include/GraphicalObject.h"
#include "include/InputManager.h"

MM::Player::Player(const ObjectParams *param) : GrapcicalObject(param){

}

void MM::Player::Draw(){
    GrapcicalObject::Draw();
}

void MM::Player::Update(){
    if (IM::Instance()->IsKeyDown(KEY_RIGHT))
        m_position.x += 2;
    if (IM::Instance()->IsKeyDown(KEY_LEFT))
        m_position.x -= 2;
    if (IM::Instance()->IsKeyDown(KEY_UP))
        m_position.y -= 2;
    if (IM::Instance()->IsKeyDown(KEY_DOWN))
        m_position.y += 2;
}

void MM::Player::Clean(){

}

void MM::Player::Input(){

}
