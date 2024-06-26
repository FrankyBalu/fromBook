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

#ifndef __GRAPHICALBASEOBJECT
#define __GRAPHICALBASEOBJECT

#include "BaseObject.h"
#include "ObjectParams.h"
#include "Vector2D.h"

namespace MM {

class GraphicalBaseObject : public BaseObject {
public:

    GraphicalBaseObject(const ObjectParams *param);

    virtual void Draw();
    virtual void Update();
    virtual void Input();
    virtual void Clean();

protected:

    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;
    float m_width;
    float m_height;

    int m_currentFrame;
    int m_currentRow;

    std::string m_textureID;
};

} // namespace MM

#endif //__GRAPHICALBASEOBJECT
