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

#ifndef __TEXTUREMANAGER
#define __TEXTUREMANAGER

#include <string>
#include <map>
#include <raylib.h>

namespace MM {


typedef enum {  FLIP_NONE,
                FLIP_HORIZONTAL,
                FLIP_VERTICAL
} FLIP;

class TextureManager {
public:

    static TextureManager* Instance();

    ///////////////////////////////////////////////////////////////////////////
    //
    //  Die zwei gehören sicher wo anders hin (Game::Render?)
    //
    ///////////////////////////////////////////////////////////////////////////
    void BeginDrawing();
    void EndDrawing();


    bool Load(const std::string& file, const std::string& id);

    bool DrawSimple (const std::string &id, float x, float y);

    bool DrawFrame(const std::string &id, float x, float y, float width, float height, int frame, int row, FLIP flip = FLIP_NONE);

    bool DrawEx(const std::string &id, Rectangle src, Rectangle dest, float rotate = 0.0f, FLIP flip = FLIP_NONE);

    bool FreeTexture(const std::string &id);

    void Clear();

    Rectangle GetRectangle(const std::string &id);

private:

    TextureManager();
    ~TextureManager();
    static TextureManager *s_pInstance;
    std::map<std::string, Texture2D> m_textureMap;
};

} //namespace MM

#endif //__TEXTUREMANAGER
