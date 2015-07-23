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

#if !defined( __IC_UI_MAINWINDOW_HXX__ )
	#define __IC_UI_MAINWINDOW_HXX__

// include the required header files
#include <QMainWindow>

// create a forward declaration for the UIC generated code
namespace Ui {
	class MainWindow;
} /* namespace Ui */

namespace ic {

	namespace ui {

		class MainWindow: public QMainWindow {
			Q_OBJECT
			public:
				MainWindow( QWidget *parent );
				virtual ~MainWindow();
			public slots:
				void showPreferences();
				void quitApplication();
			private:
				Ui::MainWindow *ui;
		}; /* class MainWindow */

	} /* namespace ui */

} /* namespace ic */

#endif /* if !defined( __IC_UI_MAINWINDOW_HXX__ ) */
