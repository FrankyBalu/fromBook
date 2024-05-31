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

#include "include/GraphicalObject.h"
#include "include/BaseObject.h"
#include "include/ObjectParams.h"
#include "include/TextureManager.h"


MM::GrapcicalObject::GrapcicalObject(const ObjectParams *params) :BaseObject(params){
    m_x = params->getX();
    m_y = params->getY();
    m_width = params->getWidth();
    m_height = params->getHeight();
    m_textureID = params->getTextureID();
}


void MM::GrapcicalObject::Draw(){
    TextureManager::Instance()->DrawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentFrame, m_currentRow);
}

void MM::GrapcicalObject::Update(){

}

void MM::GrapcicalObject::Clean(){

}

void MM::GrapcicalObject::Input(){

}
