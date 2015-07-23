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

#include "MainWindow.hxx"
#include "ui_MainWindow.h"
#include "PreferenceDialog.hxx"
#include <QMessageBox>
using namespace ic::ui;

MainWindow::MainWindow( QWidget *parent ) : QMainWindow( parent ), ui( new Ui::MainWindow() ) {
	this->ui->setupUi( this );
}

MainWindow::~MainWindow() {}

void MainWindow::showPreferences() {
	PreferenceDialog dialog( this );

	// if the settings were accepted and saved, reload them
	if( QDialog::Accepted == dialog.exec() ) {
		// TODO: reload the settings
	}
}

void MainWindow::quitApplication() {
	QMessageBox msgBox;

	// set up the message box for asking the user if he or she really wants to quit
	msgBox.setText( tr( "Quit application" ) );
	msgBox.setInformativeText( tr( "Are you sure that you want to quit the application?" ) );
	msgBox.setStandardButtons( QMessageBox::Yes | QMessageBox::No );
	msgBox.setDefaultButton( QMessageBox::No );
	msgBox.setIcon( QMessageBox::Question );

	// if the user selected yes, quit the application
	if( QMessageBox::Yes == msgBox.exec() ) {
		QApplication::quit();
	}
}
