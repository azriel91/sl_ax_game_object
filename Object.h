/*=============================================================================

	Library: Silver

	Copyright (c) Azriel Hoh

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

=============================================================================*/

#ifndef __SL_AX_GAME_OBJECT__OBJECT_H
#define __SL_AX_GAME_OBJECT__OBJECT_H

#include <azriel/sl_math/Point3D.hpp>

#include "sl_ax_game_object/Block.h"

using ::sl::math::Point3D;

namespace sl {
namespace ax {
namespace game {
namespace object {

class SL_AX_GAME_OBJECT_EXPORT Object {
protected:
	/**
	 * The unique id of this object in game.
	 */
	const int id;
	/**
	 * The x, y, and z coordinates of this object.
	 */
	Point3D<double> coordinates;
	/**
	 * The x, y, and z velocity of this object.
	 */
	Point3D<double> velocity;
	/**
	 * Whether or not this object is facing right.
	 */
	bool facingRight;

public:
	Object(const int id);
	virtual ~Object();
	/**
	 * Get the unique id of this object in game.
	 *
	 * @return the id
	 */
	const int getId() const;
	/**
	 * Get the coordinates of this object.
	 *
	 * @return the coordinates
	 */
	Point3D<double> getCoordinates() const;
	/**
	 * Set the coordinates of this object.
	 *
	 * @param coordinates the coordinates
	 */
	void setCoordinates(Point3D<double> coordinates);
	/**
	 * Get the velocity of this object.
	 *
	 * @return the velocity
	 */
	Point3D<double> getVelocity() const;
	/**
	 * Set the velocity of this object.
	 *
	 * @param velocity the velocity
	 */
	void setVelocity(Point3D<double> velocity);
	/**
	 * Check whether or not this object is facing right.
	 *
	 * @return {@code true} if it is, {@code false} otherwise
	 */
	const bool isFacingRight() const;
	/**
	 * Set whether this object is facing right.
	 *
	 * @param facingRight whether this object is facing right
	 */
	void setFacingRight(const bool facingRight);

	/**
	 * Compare whether one object is behind another. If they both have the same z coordinate, the one with the lower id
	 * will be considered to be behind the one with the higher id.
	 *
	 * @return {@code true} if it is, {@code false} otherwise
	 */
	static bool isBehind(const Object* const object, const Object* const other);
};

} /* namespace object */
} /* namespace game */
} /* namespace ax */
} /* namespace sl */

#endif /* __SL_AX_GAME_OBJECT__OBJECT_H */