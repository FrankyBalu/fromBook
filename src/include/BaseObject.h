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

#ifndef __BASEOBJECT
#define __BASEOBJECT

#include "ObjectParams.h"

#include <raylib.h>

namespace MM {

class BaseObject {
public:

    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual void Input() = 0;
    virtual void Clean() = 0;

protected:

    BaseObject([[maybe_unused]]const ObjectParams* param) {}
    virtual ~BaseObject() {}
};

} //namespace MM

#endif //__BASEOBJECT
