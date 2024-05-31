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

#ifndef __OBJECTPARAMS
#define __OBJECTPARAMS

#include <string>

namespace MM {

    class ObjectParams{
    public:
        ObjectParams(float x, float y, float width, float height, std::string textureID) : m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID){

        }

        float getX() const { return m_x; }
        float getY() const { return m_y; }
        float getWidth() const { return m_width; }
        float getHeight() const { return m_height; }
        std::string getTextureID() const { return m_textureID; }

    private:

        float m_x;
        float m_y;
        float m_width;
        float m_height;

        std::string m_textureID;

    };

} //namespace MM

#endif //__OBJECTPARAMS
