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

#include "Object.h"

namespace sl {
namespace ax {
namespace game {
namespace object {

Object::Object(const int id) : id(id) {
}

Object::~Object() {
}

const int Object::getId() const{
	return this->id;
}

Point3D<double> Object::getCoordinates() const{
	return this->coordinates;
}

void Object::setCoordinates(Point3D<double> coordinates) {
	this->coordinates = coordinates;
}

Point3D<double> Object::getVelocity() const{
	return this->velocity;
}

void Object::setVelocity(Point3D<double> velocity) {
	this->velocity = velocity;
}

const bool Object::isFacingRight() const{
	return this->facingRight;
}

void Object::setFacingRight(const bool facingRight) {
	this->facingRight = facingRight;
}

bool Object::isBehind(const Object* const object, const Object* const other) {
	// we also compare by id because in a set, if two elements are not less than each other, they are considered equal
	// and duplicate
	return object->coordinates.z() < other->coordinates.z() ||
		(object->coordinates.z() == other->coordinates.z() && object->id < other->id);
}

} /* namespace object */
} /* namespace game */
} /* namespace ax */
} /* namespace sl */
