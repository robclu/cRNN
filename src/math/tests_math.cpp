/*    
 *  cuRNN API tests for general math functions.
 *
 *  Copyright (C) 2015 Rob Clucas robclu1818@gmail.com
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <vector>

#include <gtest/gtest.h>

#include "math.hpp"

namespace curnn {
	void saxpy( const float a, const std::vector<float>& x, std::vector<float>& y );
}

TEST( currnMath, SaxpyCorrectlyPerformed ) {
	using std::vector;
	using std::cout;
	using std::endl;

	const size_t NUM_ELEMENTS = 3;
	const float  MULTIPLIER   = 2.0f;

	// Create data vectors
	vector<float> x;
	vector<float> y;

	// Fill vectors with data
	for ( size_t i = 0; i < NUM_ELEMENTS; i++ ) {
		x.push_back( float( i ) ); 
		y.push_back( float( i ) );
		cout << x[ i ] << endl;
	}

	// Execute saxpy
	curnn::saxpy( MULTIPLIER, x, y );

	// Check result
	EXPECT_EQ( y[1], MULTIPLIER * 1 + 1 );
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
