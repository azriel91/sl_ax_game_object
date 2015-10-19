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

#include <memory>
#include <string>
#include <google/gtest/gtest.h>
#include <google/gmock/gmock.h>

#include "TestConfig.h"

#ifdef US_BUILD_SHARED_LIBS
	#include <azriel/usbundleloader/BundleLoader.h>
#else
	#include <azriel/cppmicroservices/core/include/usModuleImport.h>
	US_IMPORT_MODULE(CppMicroServices)
	US_IMPORT_MODULE(sl_ax_game_object)
	US_INITIALIZE_STATIC_MODULE(main)
#endif

#include <azriel/sl_math/Point3D.hpp>

#include "../Object.h"

#ifdef US_PLATFORM_WINDOWS
	static const std::string LIB_PATH = US_RUNTIME_OUTPUT_DIRECTORY;
#else
	static const std::string LIB_PATH = US_LIBRARY_OUTPUT_DIRECTORY;
#endif

using ::sl::math::Point3D;

namespace sl {
namespace ax {
namespace game {
namespace object {

class ObjectTest : public testing::Test {
protected:
	std::unique_ptr<Object> objectZero;
	std::unique_ptr<Object> objectOne;

	virtual void SetUp() {
		this->objectZero.reset(new Object(0));
		this->objectOne.reset(new Object(1));
	}

	virtual void TearDown() {
	}
};

TEST_F(ObjectTest, smallerZCoordinate_IsBehind_LargerZCoordinate) {
	this->objectZero->setCoordinates(Point3D<double>(0, 0, 5));
	this->objectOne->setCoordinates(Point3D<double>(0, 0, 2));

	EXPECT_TRUE(Object::isBehind(this->objectOne.get(), this->objectZero.get()));
}

TEST_F(ObjectTest, smallerObjectId_IsBehind_WhenZCoordinatesEqual) {
	this->objectZero->setCoordinates(Point3D<double>(0, 0, 2));
	this->objectOne->setCoordinates(Point3D<double>(0, 0, 2));

	EXPECT_TRUE(Object::isBehind(this->objectZero.get(), this->objectOne.get()));
}

} /* namespace object */
} /* namespace game */
} /* namespace ax */
} /* namespace sl */

int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);

#ifdef US_BUILD_SHARED_LIBS
	BundleLoader bundleLoader;
	bundleLoader.load(LIB_PATH + LIB_NAME);
#endif

	return RUN_ALL_TESTS();
}
