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

#include "include/GraphicalBaseObject.h"
#include "include/BaseObject.h"
#include "include/ObjectParams.h"
#include "include/TextureManager.h"


MM::GraphicalBaseObject::GraphicalBaseObject(const ObjectParams *params) :BaseObject(params), m_position(params->getX(), params->getY()), m_velocity(0,0), m_acceleration(0,0), m_width(params->getWidth()), m_height(params->getHeight()), m_currentFrame(1), m_currentRow(1),m_textureID(params->getTextureID()){

}


void MM::GraphicalBaseObject::Draw(){
    TextureManager::Instance()->DrawFrame(m_textureID, m_position.x, m_position.y, m_width, m_height, m_currentFrame, m_currentRow);
}

void MM::GraphicalBaseObject::Update(){
    m_velocity += m_acceleration;
    m_position += m_velocity;

}

void MM::GraphicalBaseObject::Clean(){

}

void MM::GraphicalBaseObject::Input(){

}
