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

#include "NewProjectDialog.hxx"
#include "ui_NewProjectDialog.h"
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
using namespace ic::ui;

NewProjectDialog::NewProjectDialog( QWidget *parent ) : QDialog( parent ), ui( new Ui::NewProjectDialog() ) {
	this->ui->setupUi( this );
}

NewProjectDialog::~NewProjectDialog() {}

void NewProjectDialog::selectProjectBaseDirectory() {
	QSettings settings;
	const QString selectedBaseDirectory = QFileDialog::getExistingDirectory( this, tr( "Select project base directory" ), settings.value( "ui/newProjectDialog/lastBaseDirectory", "" ).toString() );

	this->ui->lineEditProjectBaseDirectory->setText( selectedBaseDirectory );
	settings.setValue( "ui/newProjectDialog/lastBaseDirectory", selectedBaseDirectory );
}

void NewProjectDialog::accept() {
	if( this->ui->lineEditProjectName->text().length() <= 0 || this->ui->lineEditProjectBaseDirectory->text().length() <= 0 ) {
		QMessageBox::information( this, tr( "Missing information" ), tr( "Please be sure that you filled out all required fields before continuing." ) );
		return;
	}
	QDialog::accept();
}
