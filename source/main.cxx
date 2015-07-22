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

#include <QApplication>
#include "MainWindow.hxx"

int main( int argc, char **argv ) {
	//
	QApplication app( argc, argv );

	app.setOrganizationName( "Image Categorizer Developers" );
	app.setApplicationName( "Image Categorizer" );

	//
	ic::ui::MainWindow mainWin( NULL );
	mainWin.show();

	// it seems that anything succeeded and we can return now
	return app.exec();
}
