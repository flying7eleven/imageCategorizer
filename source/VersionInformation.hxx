/* vi: set tw=1000 ts=4 autoindent smartindent cindent: */
/**
 * This file is part of Image Categorizer
 * Developed 2015 by Tim Huetz
 *
 * Image Categorizer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Image Categorizer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Image Categorizer.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( __VERSIONINFORMATION_HXX__ )
#define __VERSIONINFORMATION_HXX__

// the required include files
#include <string>

unsigned short int getVersionMajor();
unsigned short int getVersionMinor();
unsigned short int getVersionPatch();
const std::string getVersionSHA1();
const std::string getVersionString();

#endif /* if !defined( __VERSIONINFORMATION_HXX__ ) */
