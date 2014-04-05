/*
***************************************************************************
*
* Author: Teunis van Beelen
*
* Copyright (C) 2013, 2014 Teunis van Beelen
*
* teuniz@gmail.com
*
***************************************************************************
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation version 2 of the License.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*
***************************************************************************
*
* This version of GPL is at http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
*
***************************************************************************
*/


#ifndef UI_MANSCAN2EDFFORM_H
#define UI_MANSCAN2EDFFORM_H


#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QObject>
#include <QTextEdit>
#include <QFileDialog>
#include <QCursor>
#include <QStyle>
#if QT_VERSION < 0x050000
#include <QPlastiqueStyle>
#include <QWindowsStyle>
#endif
#include <QProgressDialog>
#include <QString>
#include <QByteArray>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "utils.h"
#include "edflib.h"
#include "utc_date_time.h"



class UI_MANSCAN2EDFwindow : public QObject
{
  Q_OBJECT

public:
  UI_MANSCAN2EDFwindow(char *recent_dir=NULL, char *save_dir=NULL);

private:


QPushButton  *pushButton1,
             *pushButton2;

QTextEdit    *textEdit1;

QDialog      *myobjectDialog;

char  *recent_opendir,
      *recent_savedir;


int get_worddatafile(struct segment_prop_struct *, int, FILE *);
int get_channel_gain(struct segment_prop_struct *, int, FILE *);
int get_start_date(struct segment_prop_struct *, int, FILE *);
int get_sample_rate(struct segment_prop_struct *, int, FILE *);
int get_filter_settings(struct segment_prop_struct *, int, FILE *);
int get_recorder_version(struct segment_prop_struct *, int, FILE *);
int get_starttime_offset(struct segment_prop_struct *, int, FILE *);
int get_events(struct segment_prop_struct *, int, FILE *);
int get_number_of_segments(FILE *);
char * fgetline(char *, int, FILE *);
long long get_long_time(const char *);



private slots:

void SelectFileButton();

};




#endif


